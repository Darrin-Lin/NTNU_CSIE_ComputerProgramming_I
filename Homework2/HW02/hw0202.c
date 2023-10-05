#include <stdio.h>
#include <stdint.h>
int32_t num_long_f(uint64_t x)
{
    int32_t log_num = 0;
    if (x == 0)
        log_num++;
    while (x)
    {
        log_num++;
        x /= 10;
    }
    return log_num;
}
int32_t ten_power(uint32_t u)
{
    int32_t result = 1;
    for (int32_t i = 0; i < u; i++)
        result *= 10;
    return result;
}
int main()
{
    int64_t inp1 = 0, inp2 = 0;
    int32_t longest = 0;
    uint64_t result = 0;
    int32_t separate = 0, space = 0, num_long = 0, num_print = 0, t_power = 0;
    printf("Please enter the first  number: ");
    scanf("%ld", &inp1);
    printf("Please enter the second number: ");
    scanf("%ld", &inp2);
    if (inp1 < 0 || inp2 < 0)
    {
        printf("Invalid input\n");
        return 1;
    }
    result = inp1 * inp2;
    if (inp1 && inp2)
        longest = num_long_f(result);
    else if (inp1)
        longest = num_long_f(inp1);
    else
        longest = num_long_f(inp2);
    separate = longest * 2 + 1;

    // 1_ for loop + last number
    // n1
    // space
    num_long = num_long_f(inp1);
    space = separate - (num_long * 2 - 1);
    for (int32_t i = 0; i < space; i++)
        printf(" ");
    num_print = inp1;
    // number
    for (int32_t i = 0; i < num_long - 1; i++)
    {
        t_power = ten_power(num_long - i - 1);
        printf("%ld ", num_print / t_power);
        num_print %= t_power; //
    }
    printf("%d", inp1 % 10);

    // n2
    // space
    num_long = num_long_f(inp2);
    space = separate - (num_long * 2 - 1);
    printf("\n");
    printf("*)");
    for (int32_t i = 0; i < space - 2; i++)
        printf(" ");
    num_print = inp2;
    // number
    for (int32_t i = 0; i < num_long - 1; i++)
    {
        t_power = ten_power(num_long - i - 1);
        printf("%ld ", num_print / t_power);
        num_print %= t_power; //
    }
    printf("%d", inp2 % 10);
    printf("\n");
    //----
    for (int32_t i = 0; i < separate; i++)
        printf("-");
    printf("\n");

    

    //---
    for (int32_t i = 0; i < separate; i++)
        printf("-");
    printf("\n");
    //answer

    // space
    num_long = num_long_f(result);
    space = separate - (num_long * 2 - 1);
    for (int32_t i = 0; i < space; i++)
        printf(" ");
    num_print = result;
    // number
    for (int32_t i = 0; i < num_long - 1; i++)
    {
        t_power = ten_power(num_long - i - 1);
        printf("%ld ", num_print / t_power);
        num_print %= t_power; //
    }
    printf("%d", result % 10);
    printf("\n");
    return 0;
}