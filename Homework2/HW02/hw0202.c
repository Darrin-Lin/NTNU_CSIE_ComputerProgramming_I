#include <stdio.h>
#include <stdint.h>
int32_t log_10_f(uint64_t x)
{
    int32_t log_num = 0;
    while (x >= 10)
    {
        log_num++;
        x /= 10;
    }
    return log_num;
}
int32_t ten_power(uint32_t x)
{
    int32_t result = 1;
    for (int32_t i = 0; i < x; i++)
        result *= 10;
    return result;
}
int main()
{
    int64_t inp1 = 0, inp2 = 0;
    int32_t longest = 0;
    uint64_t result = 0;
    int32_t separate = 0, space = 0, num_long = 0,num_print=0,t_power=0;
    printf("Please enter the first number: ");
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
        longest = log_10_f(result);
    else if (inp1)
        longest = log_10_f(inp1);
    else
        longest = log_10_f(inp2);
    separate = longest * 2 + 1;

    // 1_ for loop + last number
    // n1
    num_long = log_10_f(inp1);
    space=separate - (num_long* 2 - 1);
    for (int32_t i = 0; i < space; i++)
        printf(" ");
    for (int32_t i = 0; i < log_10_f(inp1)-1; i++)
    {
        t_power=ten_power(num_long);
        printf("%ld ", inp1 / t_power);
        inp1 %= t_power;//
    }
    return 0;
}