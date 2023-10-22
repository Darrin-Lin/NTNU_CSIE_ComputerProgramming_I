#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void the_hanoi_tower(int32_t disk_number);
static void ht_iterative(int32_t disk_n);
#define compare_double 1e-6

void the_hanoi_tower(int32_t disk_number)
{
    if (disk_number < 1)
    {
        printf("invalid disk number.\n");
        return;
    }
    ht_iterative(disk_number);
    return;
}
static void ht_iterative(int32_t disk_n)
{
    for (int32_t i = 1; i < pow(2, disk_n); i++)
    {
        for (int32_t j = 1; j <= disk_n; j++)
        {
            if ((j+disk_n+1) % 2) // 231
            {
                if (fabs(fmod((double)i, pow(2, j)) - pow(2, j - 1)) < compare_double)
                {
                    if ((int)(i / pow(2, j)) % 3 == 0)
                    {
                        printf("move disk %d to rod %d\n", j, 2);
                        break;
                    }
                    else if ((int)(i / pow(2, j)) % 3 == 1)
                    {
                        printf("move disk %d to rod %d\n", j, 3);
                        break;
                    }
                    else
                    {
                        printf("move disk %d to rod %d\n", j, 1);
                        break;
                    }
                }
            }
            else // 321
            {
                if (fabs(fmod((double)i, pow(2, j)) - pow(2, j - 1)) < compare_double)
                {
                    if ((int)(i / pow(2, j)) % 3 == 0)
                    {
                        printf("move disk %d to rod %d\n", j, 3);
                        break;
                    }
                    else if ((int)(i / pow(2, j)) % 3 == 1)
                    {
                        printf("move disk %d to rod %d\n", j, 2);
                        break;
                    }
                    else
                    {
                        printf("move disk %d to rod %d\n", j, 1);
                        break;
                    }
                }
            }
        }
    }
}