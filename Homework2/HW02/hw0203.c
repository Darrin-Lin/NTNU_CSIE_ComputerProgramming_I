#include <stdio.h>
#include <stdint.h>

// int32_t S0(int32_t n)
// {
// }

int main()
{
    int32_t n = 0;
    int8_t S0 = 1, S1 = 0, S2 = 0, S3 = 0, S4 = 0, S5 = 0, S6 = 0;
    do{
        scanf("%d", &n);
        if (!n)
            break;
        if (S0)
        {
            S0=1;
            if (n %2)///odd
            {
                S1=1;//fix next S
                S2=1;
            }
        }
    }
    while (n)
        ;

    return 0;
}