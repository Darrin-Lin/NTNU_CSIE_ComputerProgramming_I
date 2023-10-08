#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t init_inv = 0, month_inv = 0;
    int32_t start_year = 0, start_month = 0, end_years = 0, end_months = 0;
    int32_t rate_inp = 0;
    double return_rate = 0;
    int32_t money_input = 0;
    double money_now = 0, money_get = 0, ROI = 0;
    printf("Initial Investment: ");
    scanf("%d", &init_inv);
    if (init_inv < 1 || init_inv > 10000000)
    {
        printf("Invalid Initial Investment.\n");
        return 1;
    }
    printf("Recurring Monthly Investment: ");
    scanf("%d", &month_inv);
    if (month_inv < 0 || month_inv > 10000000)
    {
        printf("Invalid Recurring Monthly Investment.\n");
        return 1;
    }
    printf("Start Month: ");
    scanf("%d", &start_month);
    if (start_month < 1 || start_month > 12)
    {
        printf("Invalid Start Month.\n");
        return 1;
    }
    printf("Start Year: ");
    scanf("%d", &start_year);
    if (start_year < 0 || start_year > 10000)
    {
        printf("Invalid Start Year.\n");
        return 1;
    }
    printf("End Month: ");
    scanf("%d", &end_months);
    if (end_months < 1 || end_months > 12)
    {
        printf("Invalid End Month.\n");
        return 1;
    }
    printf("End Year: ");
    scanf("%d", &end_years);
    if (end_years < 0 || end_years > 10000 || end_years < start_year || (end_years == start_year && end_months < start_month))
    {
        printf("Invalid End Year.\n");
        return 1;
    }
    printf("Annual Rate of Return (%%): ");
    scanf("%d", &rate_inp);
    if (return_rate < 1 || return_rate > 100)
    {
        printf("Invalid Annual Rate of Return.\n");
        return 1;
    }
    printf("--- Output ---\n");
    return_rate = (double)rate_inp / 12.0 / 100.0;
    money_input = init_inv;
    money_now = init_inv;
    for (int32_t i = start_year; i <= end_years; i++)
    {
        for (int32_t j = start_month; j <= 12; j++)
        {
            if (i == end_years && j == end_months)
            {
                printf("%d.%d) %d/%.2f/%.2f/%.2f%%\n", i, j, money_input, money_now, money_get, ROI); // how many float
                break;
            }
            else
            {
                printf("%d.%d) %d/%.2f/%.2f/%.2f%%\n", i, j, money_input, money_now, money_get, ROI); // how many float
            }
            money_input += month_inv;
            money_now = money_now * (1 + return_rate) + month_inv;
            money_get = money_now - (double)money_input;
            // if (money_input)
            ROI = money_get / (double)money_input * 100;
            // else
            //     ROI = 0;
        }
        start_month = 1;
    }
    return 0;
}