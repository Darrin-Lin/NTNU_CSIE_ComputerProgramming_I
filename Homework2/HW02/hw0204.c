#include <stdio.h>
#include <stdint.h>

int main()
{
    int64_t init_inv = 0, month_inv = 0;
    int32_t start_year = 0, start_month = 0, end_years = 0, end_months = 0;
    double return_rate = 0;
    int64_t money_input = 0;
    double money_now = 0, money_get = 0, ROI = 0;
    printf("Initial Investment: ");
    scanf("%ld", &init_inv);
    if(init_inv<0)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("Recurring Monthly Investment: ");
    scanf("%ld", &month_inv);
    if(month_inv<0)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("Start Month: ");
    scanf("%d", &start_month);
    if(start_month<1||start_month>12)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("Start Year: ");
    scanf("%d", &start_year);
    if(start_year<0)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("End Month: ");
    scanf("%d", &end_months);
    if (end_months < 1 || end_months > 12)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("End Year: ");
    scanf("%d", &end_years);
    if (end_years < 0||end_years<start_year||(end_years==start_year&&end_months<start_month))
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("Annual Rate of Return (%%): ");
    scanf("%lf", &return_rate);
    if (return_rate < 0)
    {
        printf("Invalid Input.\n");
        return 1;
    }
    printf("--- Output ---\n");
    return_rate = return_rate / 12 / 100;
    money_input = init_inv;
    money_now = init_inv;
    for (int i = start_year; i <= end_years; i++)
    {
        for (int j = start_month; j <= 12; j++)
        {
            if (i == end_years && j == end_months)
            {
                printf("%d.%d) %ld/%.2f/%.2f/%.2f%%\n", i, j, money_input, money_now, money_get, ROI); // how many float
                break;
            }
            else
            {
                printf("%d.%d) %ld/%.2f/%.2f/%.2f%%\n", i, j, money_input, money_now, money_get, ROI); // how many float
            }
            money_input+=month_inv;
            money_now = money_now*(1+return_rate)+month_inv;
            money_get = money_now - (double)money_input;
            ROI = money_get / (double)money_input * 100;
        }
        start_month = 1;
    }
    return 0;
}