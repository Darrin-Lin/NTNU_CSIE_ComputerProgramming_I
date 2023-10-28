#include <stdio.h>
#include <stdint.h>

#define i32 int32_t

int main()
{
    i32 start_year = 0, end_year = 0, start_month = 0, end_month = 0, start_day = 0, end_day = 0;
    i32 start_hour = 0, end_hour = 0, start_minute = 0, end_minute = 0, start_second = 0, end_second = 0;
    int64_t total_time = 0;
    printf("Start Time: ");
    scanf("%d-%d-%d %d:%d:%d", &start_year, &start_month, &start_day, &start_hour, &start_minute, &start_second);
    printf("End Time:   ");
    scanf("%d-%d-%d %d:%d:%d", &end_year, &end_month, &end_day, &end_hour, &end_minute, &end_second);
    // total_time += (end_year - start_year) * 31536000;
    // for(i32 i = start_year+1; i < end_year; i++)
    // {

    //     if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
    //     {
    //         total_time += 86400;
    //     }
    // }

    // total_time += (end_month - start_month) * 2592000;
    // total_time += (end_day - start_day) * 86400;
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
                if(j == 1 || j == 3 || j == 5 || j == 7 || j == 8 || j == 10|| j == 12)
                {
                    total_time += 2678400;
                }
                else if(j == 4 || j == 6 || j == 9 || j == 11)
                {
                    total_time += 2592000;
                }
                else if(j == 2)
                {
                    if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
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
    printf("Duration:   %ld sec\n", total_time);
    return 0;
}