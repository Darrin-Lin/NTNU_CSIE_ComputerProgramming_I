#include <stdint.h>
#include <stdio.h>
uint64_t parity_2d(int32_t, int32_t, int32_t, int32_t, int32_t);

uint64_t parity_2d(int32_t n1, int32_t n2, int32_t n3, int32_t n4, int32_t n5)
{
    static int64_t column[5] = {0}; //
    static int64_t row = 0;        //
    static int64_t bits[32] = {0};
    for (int32_t i = 0; i < 32; i++)
    {
        bits[i] += ((1 << i) & n1 )? 1 : 0;
        column[0] += ((1 << i) & n1) ? 1 : 0;
    }
    for (int32_t i = 0; i < 32; i++)
    {
        bits[i] += ((1 << i) & n2) ? 1 : 0;
        column[1] += ((1 << i) & n1) ? 1 : 0;
    }
    for (int32_t i = 0; i < 32; i++)
    {
        bits[i] += ((1 << i) & n3) ? 1 : 0;
        column[2] += ((1 << i) & n1) ? 1 : 0;
    }
    for (int32_t i = 0; i < 32; i++)
    {
        bits[i] += ((1 << i) & n4 )? 1 : 0;
        column[3] += ((1 << i) & n1) ? 1 : 0;
    }
    for (int32_t i = 0; i < 32; i++)
    {
        bits[i] += ((1 << i) & n5) ? 1 : 0;
        column[4] += ((1 << i) & n1) ? 1 : 0;
    }
    for(int32_t i=0;i<5;i++)
    {
        column[i]= !column[i]%2;
        row+=column[i];
    }
    row=!row%2;
    for(int32_t i=0;i<32;i++)
    {
        bits[i]= !bits[i]%2;
    }
    uint64_t result = 0;
    for (int32_t i = 31; i >=0; i--)
    {
        result += (bits[i] << i+1); 
    }
    result += row;
    return result;
}