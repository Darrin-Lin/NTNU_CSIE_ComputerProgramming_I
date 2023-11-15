#include <stdio.h>
#include <stdint.h>

#define ptf printf

int main()
{
    uint32_t f_degree, g_degree;
    ptf("Please enter f(x) degree: ");
    scanf("%u", &f_degree);
    int32_t f[f_degree + 1];
    ptf("Please enter f(x) coefficients: ");
    for (uint32_t i = 0; i <= f_degree; i++)
        scanf("%d", &f[i]);
    ptf("Please enter g(x) degree: ");
    scanf("%u", &g_degree);
    int32_t g[g_degree + 1];
    ptf("Please enter g(x) coefficients: ");
    for (uint32_t i = 0; i <= g_degree; i++)
        scanf("%d", &g[i]);
    int32_t f_prime[f_degree];
    for (uint32_t i = 0; i < f_degree; i++)
        f_prime[i] = f[i + 1] * (i + 1);
    int32_t g_prime[g_degree];
    for (uint32_t i = 0; i < g_degree; i++)
        g_prime[i] = g[i + 1] * (i + 1);
    int32_t g_sqare[g_degree * 2 + 1];
    for (uint32_t i = 0; i <= g_degree * 2; i++)
        g_sqare[i] = 0;
    for (uint32_t i = 0; i <= g_degree; i++)
        for (uint32_t j = 0; j <= g_degree; j++)
            g_sqare[i + j] += g[i] * g[j];
    int32_t f_times_g_prime[f_degree + g_degree];
    for (uint32_t i = 0; i <= f_degree + g_degree; i++)
        f_times_g_prime[i] = 0;
    for (uint32_t i = 0; i <= f_degree; i++)
        for (uint32_t j = 0; j <= g_degree; j++)
            f_times_g_prime[i + j] += f[i] * g_prime[j];
    int32_t f_prime_times_g[f_degree + g_degree];
    for (uint32_t i = 0; i <= f_degree + g_degree; i++)
        f_prime_times_g[i] = 0;
    for (uint32_t i = 0; i <= f_degree; i++)
        for (uint32_t j = 0; j <= g_degree; j++)
            f_prime_times_g[i + j] += f_prime[i] * g[j];
    /// print
    printf("f(x): ");
    for (int32_t i = 0; i < f_degree; i++)
    {
        if (f[i] != 0)
            printf("%dx^%d + ", f[i], f_degree - i);
    }
    printf("%d\n", f[f_degree]);
    printf("g(x): ");
    for (int32_t i = 0; i < g_degree-1; i++)
    {
        if (g[i] != 0)
            printf("%dx^%d + ", g[i], g_degree - i-1);
    }
    printf("%d\n", g[g_degree]);
    printf("(f(x)g(x))': ");
    for (int32_t i = 0; i < f_degree + g_degree-1; i++)
    {
        if (f_times_g_prime[i] +f_prime_times_g[i]!= 0)
            printf("%dx^%d + ", f_times_g_prime[i] +f_prime_times_g[i], f_degree + g_degree - i-1);
    }
    printf("%d\n", f_times_g_prime[f_degree + g_degree]);
    printf(" f(x)    ");
    printf("(----)': ");
    
    printf(" g(x)    ");
    return 0;
}