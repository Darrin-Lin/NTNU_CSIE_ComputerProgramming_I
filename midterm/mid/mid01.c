#include <stdio.h>
#include <stdint.h>

#define i32 int32_t

int main()
{
    i32 start_year = 0, end_year = 0, start_month = 0, end_month = 0, start_day = 0, end_day = 0;
    i32 start_hour = 0, end_hour = 0, start_minute = 0, end_minute = 0, start_second = 0, end_second = 0;
    uint64_t total_time = 0;
    printf("Start Time: ");
    scanf("%d-%d-%d %d:%d:%d", &start_year, &start_month, &start_day, &start_hour, &start_minute, &start_second);
    printf("End Time:   ");
    scanf("%d-%d-%d %d:%d:%d", &end_year, &end_month, &end_day, &end_hour, &end_minute, &end_second);
    if (start_year < 0 || start_month < 0 || start_day < 0 || start_hour < 0 || start_minute < 0 || start_second < 0 || end_year < 0 || end_month < 0 || end_day < 0 || end_hour < 0 || end_minute < 0 || end_second < 0)
    {
        printf("Invalid input\n");
        return 1;
    }
    if (start_month > 12 || end_month > 12 || start_day > 31 || end_day > 31 || start_hour > 23 || end_hour > 23 || start_minute > 59 || end_minute > 59 || start_second > 59 || end_second > 59)
    {
        printf("Invalid input\n");
        return 1;
    }
    for (int32_t i = start_year; i <= end_year; i++)
    {
        for (int32_t j = start_month; j <= 12; j++)
        {
            if (i == end_year && j == end_month)
            {
                break;
            }
            else
            {
                if (j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10 || j == 12)
                {
                    total_time += 2678400;
                }
                else if (j == 4 || j == 6 || j == 9 || j == 11)
                {
                    total_time += 2592000;
                }
                else if (j == 2)
                {
                    if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
                    {
                        total_time += 2505600;
                    }
                    else
                    {
                        total_time += 2419200;
                    }
                }
            }
        }
        start_month = 1;
    }
    total_time -= (start_day - 1) * 86400;
    total_time += (end_day - 1) * 86400;
    total_time += (end_hour - start_hour) * 3600;
    total_time += (end_minute - start_minute) * 60;
    total_time += (end_second - start_second);
    printf("Duration:   %lu sec\n", total_time);
    return 0;
}