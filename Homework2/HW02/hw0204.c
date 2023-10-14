#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t init_inv = 0, month_inv = 0;
    int32_t start_year = 0, start_month = 0, end_years = 0, end_months = 0;
    int32_t rate_inp = 0;
    double return_rate = 0;
    int64_t money_input = 0;
    double money_now = 0, money_get = 0, ROI = 0;
    printf("Initial Investment:           ");
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
    printf("Start Month:                  ");
    scanf("%d", &start_month);
    if (start_month < 1 || start_month > 12)
    {
        printf("Invalid Start Month.\n");
        return 1;
    }
    printf("Start Year:                   ");
    scanf("%d", &start_year);
    if (start_year < 0 || start_year > 10000)
    {
        printf("Invalid Start Year.\n");
        return 1;
    }
    printf("End Month:                    ");
    scanf("%d", &end_months);
    if (end_months < 1 || end_months > 12)
    {
        printf("Invalid End Month.\n");
        return 1;
    }
    printf("End Year:                     ");
    scanf("%d", &end_years);
    if (end_years < 0 || end_years > 10000 || end_years < start_year || (end_years == start_year && end_months < start_month))
    {
        printf("Invalid End Year.\n");
        return 1;
    }
    printf("Annual Rate of Return (%%):    ");
    scanf("%d", &rate_inp);
    if (rate_inp < 1 || rate_inp > 100)
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
                // printf("%d.%d) %d/%.2f/%.2f/%.2f%%\n", i, j, money_input, money_now, money_get, ROI); // how many float
                break;
            }
            else
            {
                if (j < 10)
                    printf("%d.0%d) ", i, j);
                else
                    printf("%d.%d) ", i, j);
                if (money_input >= 0)
                    printf("%ld/", money_input);
                else
                    printf("*/");
                if (money_now >= 0)
                    printf("%ld/", (int64_t)(money_now + 1E-9));
                else
                    printf("*/");
                if (money_get >= 0)
                    printf("%ld/", (int64_t)(money_get + 1E-9));
                else
                    printf("*/");
                if (ROI >= 0)
                    if ((int)(ROI * 100 + 1E-9) % 10 == 0 && (int)(ROI * 10 + 1E-9) % 10 == 0)
                        printf("%.0f%%\n", ROI);
                    else if ((int)(ROI * 100 + 1E-9) % 10 == 0)
                        printf("%.1f%%\n", ROI);
                    else
                    {
                        if((int)(ROI * 1000 + 1E-9) % 10 >=5)
                            ROI-=5E-3;
                        printf("%.2f%%\n", ROI);
                    }
                else
                    printf("*%%\n");
            }

            // if (money_input)

            // else
            //     ROI = 0;
            if (money_input >= (int64_t)1E15 || money_input < 0)
                money_input = -1;
            else
                money_input += month_inv;
            if (money_now >= (int64_t)1E15 || money_now < 0)
                money_now = -1;
            else
                money_now = money_now * (1.0 + return_rate) + month_inv;
            if (money_get >= (int64_t)1E15 || money_get < 0)
                money_get = -1;
            else
                money_get = money_now - (double)money_input;
            if (ROI >= (int64_t)1E15 || ROI < 0)
                ROI = -1;
            else
                ROI = money_get / money_now * 100;
        }
        start_month = 1;
    }
    return 0;
}