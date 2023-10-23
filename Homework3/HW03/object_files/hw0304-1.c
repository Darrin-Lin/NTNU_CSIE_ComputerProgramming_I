#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void the_hanoi_tower(int32_t disk_number);
static void ht_recursive(int32_t disk_n, int32_t rod_now, int32_t rod_next, int32_t rod_no_use);

void the_hanoi_tower(int32_t disk_number)
{
    if (disk_number < 2 || disk_number > 20)
    {
        printf("invalid disk number.\n");
        return;
    }
    ht_recursive(disk_number, 1, 2, 3);
    return;
}
static void ht_recursive(int32_t disk_n, int32_t rod_now, int32_t rod_move_to, int32_t rod_no_use)
{
    if (disk_n == 1)
    {
        printf("move disk %d to rod %d\n",disk_n,rod_move_to);
        return;
    }
    ht_recursive(disk_n-1,rod_now,rod_no_use,rod_move_to);
    printf("move disk %d to rod %d\n",disk_n,rod_move_to);
    ht_recursive(disk_n-1,rod_no_use,rod_move_to,rod_now);
    return;
}