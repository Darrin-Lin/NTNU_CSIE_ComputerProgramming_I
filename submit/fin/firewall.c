#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// First , you should have a rule array , where its size is 100 elements.
// Then set rule[idx] to the input function pointer.
// Rule Function Pointer:
// int32_t (*rule)( const uint8_t *p_input_packet , const int32_t input_size ,
// uint8_t **pp_output_packet , int32_t *p_output_size )
// Input: p_input_packet -> input packet (one packet)
// input_size -> input_packet size
// Output: pp_output_packet -> output_packet (one packet)
// p_output_size -> output_packet size
// return -> 1 if the input packet is dropped , -1 if the input is invalid and skip this rule; otherwise , return 0
// If the inputs are invalid , return -1; otherwise , return 0.
int32_t set_rule(int32_t idx, int32_t (*rule)(const uint8_t *p_input_packet, const int32_t input_size, uint8_t **pp_output_packet, int32_t *p_output_size));

// Set rule[idx] to NULL.
// If the inputs are invalid , return -1; otherwise , return 0.
int32_t unset_rule(int32_t idx);

// For every input packet , apply all rules on the packet and store every ouput packet on the pp_output_packets.
// If the inputs are invalid , return -1; otherwise , return 0.
int32_t filter(const uint8_t *p_input_packets, const int32_t input_size, uint8_t **pp_output_packets, int32_t *p_output_size);

static int32_t (*rule_array[100])(const uint8_t *p_input_packet, const int32_t input_size, uint8_t **pp_output_packet, int32_t *p_output_size) = {
    NULL,
};

int32_t set_rule(int32_t idx, int32_t (*rule)(const uint8_t *p_input_packet, const int32_t input_size, uint8_t **pp_output_packet, int32_t *p_output_size))
{
    if (rule == NULL)
    {
        return -1;
    }
    if (idx < 0 || idx >= 100)
    {
        return -1;
    }
    rule_array[idx] = rule;
    return 0;
}

int32_t unset_rule(int32_t idx)
{
    if (idx < 0 || idx >= 100)
    {
        return -1;
    }
    rule_array[idx] = NULL;
    return 0;
}

int32_t filter(const uint8_t *p_input_packets, const int32_t input_size, uint8_t **pp_output_packets, int32_t *p_output_size)
{
    if (p_input_packets == NULL || pp_output_packets == NULL || p_output_size == NULL)
    {
        return -1;
    }
    if (input_size < 0)
    {
        return -1;
    }
    uint8_t *ptr_out_packet = NULL;
    uint8_t **pptr_packets = NULL;
    uint64_t packet_num = 0;
    uint64_t *ptr_packet_size = NULL;
    for (int32_t i = 0; i < input_size; i++)
    {
        packet_num++;
        uint16_t size = *(p_input_packets + i + 10) + *(p_input_packets + i + 11) * 256;
        pptr_packets = (uint8_t **)realloc(pptr_packets, sizeof(uint8_t *) * packet_num);
        ptr_packet_size = (uint64_t *)realloc(ptr_packet_size, sizeof(uint64_t) * packet_num);
        if (pptr_packets == NULL)
        {
            return -1;
        }
        if (ptr_packet_size == NULL)
        {
            return -1;
        }
        uint8_t *ptr_packet = NULL;
        ptr_packet = (uint8_t *)malloc(sizeof(uint8_t) * size);
        if (ptr_packet == NULL)
        {
            return -1;
        }
        for (int32_t j = 0; j < size; j++)
        {
            *(ptr_packet + j) = *(p_input_packets + i + j);
        }
        *(pptr_packets + packet_num - 1) = ptr_packet;
        *(ptr_packet_size + packet_num - 1) = size + 10;
        i += (10 + size);
    }

    for (uint64_t x = 0; x < packet_num; x++)
    {
        for (int32_t i = 0; i < 100; i++)
        {
            if (rule_array[i] == NULL)
            {
                continue;
            }
            int32_t temp_size = 0;
            uint8_t *temp_packet = NULL;
            int32_t result = rule_array[i](*(pptr_packets + x), *(ptr_packet_size + x), &temp_packet, &temp_size);
            if (result == -1)
            {
                return -1;
            }
            if (result == 1)
            {
                *(ptr_packet_size + x) = 0;
                free(*(pptr_packets + x));
                *(pptr_packets + x) = NULL;
                break;
            }
            if (temp_size < 0)
            {
                return -1;
            }
            if (temp_size == 0)
            {
                continue;
            }
            uint8_t *ptr = NULL;
            ptr = (uint8_t *)realloc(*(pptr_packets + x), sizeof(uint8_t) * temp_size);
            if (ptr == NULL)
            {
                return -1;
            }
            *(pptr_packets + x) = ptr;
            for (int32_t j = 0; j < temp_size; j++)
            {
                *(*(pptr_packets + x) + j) = *(temp_packet + j);
            }
            *(ptr_packet_size + x) = temp_size;
        }
    }
    uint64_t output_size = 0;

    for (uint64_t i = 0; i < packet_num; i++)
    {
        if (*(ptr_packet_size + i) == 0)
        {
            continue;
        }
        output_size += *(ptr_packet_size + i);
    }
    ptr_out_packet = (uint8_t *)calloc(output_size, sizeof(uint8_t));
    if (ptr_out_packet == NULL)
    {
        return -1;
    }
    uint64_t temp = 0;
    for (uint64_t i = 0; i < packet_num; i++)
    {
        if (*(ptr_packet_size + i) == 0)
        {
            continue;
        }
        for (uint64_t j = 0; j < *(ptr_packet_size + i); j++)
        {
            *(ptr_out_packet + temp + j) = *(*(pptr_packets + i) + j);
        }
        temp += *(ptr_packet_size + i);
    }
    *pp_output_packets = ptr_out_packet;
    *p_output_size = output_size;

    free(ptr_out_packet);
    for (uint64_t i = 0; i < packet_num; i++)
    {
        free(*(pptr_packets + i));
    }
    free(ptr_packet_size);
    free(pptr_packets);
    return 0;
}
