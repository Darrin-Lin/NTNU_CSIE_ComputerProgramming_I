#include <stdio.h>
#include <stdint.h>

int main()
{
    int32_t n = 0;
    int8_t run_S0 = 0, run_S1 = 0, run_S2 = 0, run_S3 = 0, run_S4 = 0, run_S5 = 0, run_S6 = 0;
    int8_t now_S0 = 1, now_S1 = 0, now_S2 = 0, now_S3 = 0, now_S4 = 0, now_S5 = 0, now_S6 = 0;
    int8_t not_first_print = 0;
    do
    {
        printf("Please enter an integer: ");
        scanf("%d", &n);
        if (n == 0)
            break;
        // which run
        if (now_S0)
        {
            now_S0 = 0;
            if (n % 2) /// Odd
            {
                run_S1 = 1;
                run_S2 = 1;
            }
            else // Even
                run_S3 = 1;
        }
        if (now_S1)
        {
            now_S1 = 0;
            if (n % 2) /// Odd
                run_S2 = 1;
            else // Even
                run_S4 = 1;
        }
        if (now_S2)
        {
            now_S2 = 0;
            if (n % 2) /// Odd
                run_S3 = 1;
            else // Even
                run_S5 = 1;
        }
        if (now_S3)
        {
            now_S3 = 0;
            if (n % 2) /// Odd
                run_S5 = 1;
            else // Even
                run_S0 = 1;
        }
        if (now_S4)
        {
            now_S4 = 0;
            if (n % 2) /// Odd
                run_S5 = 1;
            else // Even
            {
                run_S2 = 1;
                run_S6 = 1;
            }
        }
        if (now_S5)
        {
            now_S5 = 0;
            if (n % 2) /// Odd
                run_S6 = 1;
            else // Even
                run_S0 = 1;
        }
        if (now_S6)
        {
            now_S6 = 0;
            if (n % 2) /// Odd
                run_S6 = 1;
            else // Even
                run_S1 = 1;
        }
        // add now_Sn
        if (run_S0)
        {
            now_S0 = 1;
            run_S0 = 0;
        }
        if (run_S1)
        {
            now_S1 = 1;
            run_S1 = 0;
        }
        if (run_S2)
        {
            now_S2 = 1;
            run_S2 = 0;
        }
        if (run_S3)
        {
            now_S3 = 1;
            run_S3 = 0;
        }
        if (run_S4)
        {
            now_S4 = 1;
            run_S4 = 0;
        }
        if (run_S5)
        {
            now_S5 = 1;
            run_S5 = 0;
        }
        if (run_S6)
        {
            now_S6 = 1;
            run_S6 = 0;
        }
    } while (n);
    printf("Possible States: ");
    if (now_S0)
    {
        not_first_print = 1;
        printf("S0");
    }
    if (now_S1)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S1");
    }
    if (now_S2)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S2");
    }
    if (now_S3)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S3");
    }
    if (now_S4)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S4");
    }
    if (now_S5)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S5");
    }
    if (now_S6)
    {
        if (not_first_print)
            printf(", ");
        else
            not_first_print = 1;
        printf("S6");
    }
    printf("\n");
    return 0;
}