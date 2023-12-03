#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

void button_set_frame(uint8_t **src, size_t *size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame);

void button_unset_frame(uint8_t *src, const size_t size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame);

void button_set_frame(uint8_t **src, size_t *size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame)
{
    if(start_frame > end_frame)
    {
        // perror("Invalid Frame");
        return;
    }
    if (end_frame + 1 > *size)
    {
        uint8_t *ptr = NULL;
        ptr = (uint8_t *)realloc(*src, end_frame + 1);
        if(ptr!= *src)
        {
            free((void *)*src);
            *src = ptr;
        }
        for(size_t i = *size; i <= end_frame; i++)
        {
            (*src)[i] = 0;
        }
        *size = end_frame + 1;
    }
    for(size_t i = start_frame; i <= end_frame; i++)
    {
        (*src)[i] |= button;
    }
    return;
}

void button_unset_frame(uint8_t *src, const size_t size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame)
{
    if (src == NULL)
    {
        // perror("Invalid Source");
        return;
    }
    if (start_frame > end_frame)
    {
        // perror("Invalid Frame");
        return;
    }
    
    for (size_t i = start_frame; i <= end_frame; i++)
    {
        if (i >= size)
        {
            // perror("Invalid Frame");
            return;
        }
        src[i] -= (src[i]) & button;
    }
    return;
}