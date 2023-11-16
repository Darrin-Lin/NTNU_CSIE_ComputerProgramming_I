#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define ptf printf
#define i64 int64_t
#define u64 uint64_t

int main()
{
    u64 f_degree, g_degree;
    ptf("Please enter f(x) degree: ");
    scanf("%lu", &f_degree);
    i64 f_inp[f_degree + 1];
    ptf("Please enter f(x) coefficients: ");
    for (u64 i = 0; i <= f_degree; i++)
        scanf("%ld", &f_inp[i]);
    ptf("Please enter g(x) degree: ");
    scanf("%lu", &g_degree);
    i64 g_inp[g_degree + 1];
    ptf("Please enter g(x) coefficients: ");
    for (u64 i = 0; i <= g_degree; i++)
        scanf("%ld", &g_inp[i]);
    if (f_degree == 0 && g_degree == 0)
    {
        ptf("f(x) = %ld\n", f_inp[0]);
        ptf("g(x) = %ld\n", g_inp[0]);
        ptf("(f(x)g(x))' = 0\n");
        ptf(" f(x)    0\n");
        ptf("(----)': -\n");
        ptf(" g(x)    0\n");
        return 0;
    }
    int64_t f[f_degree + 1];
    int64_t g[g_degree + 1];
    for (u64 i = 0; i <= f_degree; i++)
        f[i] = f_inp[f_degree - i];
    for (u64 i = 0; i <= g_degree; i++)
        g[i] = g_inp[g_degree - i];
    i64 f_prime[f_degree];
    for (u64 i = 0; i < f_degree; i++)
        f_prime[i] = f[i + 1] * (i + 1);
    i64 g_prime[g_degree];
    for (u64 i = 0; i < g_degree; i++)
        g_prime[i] = g[i + 1] * (i + 1);

    i64 g_sqare[g_degree * 2 + 1];
    for (u64 i = 0; i <= g_degree * 2; i++)
        g_sqare[i] = 0;
    for (u64 i = 0; i <= g_degree; i++)
        for (u64 j = 0; j <= g_degree; j++)
            g_sqare[i + j] += g[i] * g[j];
    i64 f_times_g_prime[f_degree + g_degree];
    for (u64 i = 0; i <= f_degree + g_degree; i++)
        f_times_g_prime[i] = 0;
    for (u64 i = 0; i <= f_degree; i++)
        for (u64 j = 0; j < g_degree; j++)
            f_times_g_prime[i + j] += f[i] * g_prime[j];
    for (int64_t i = 0; i < f_degree + g_degree; i++)
        fprintf(stderr, "%ld ", f_times_g_prime[i]);
    fprintf(stderr, "\n");
    i64 f_prime_times_g[f_degree + g_degree];
    for (u64 i = 0; i <= f_degree + g_degree; i++)
        f_prime_times_g[i] = 0;
    for (u64 i = 0; i < f_degree; i++)
        for (u64 j = 0; j <= g_degree; j++)
            f_prime_times_g[i + j] += f_prime[i] * g[j];
    for (int64_t i = 0; i < f_degree + g_degree; i++)
        fprintf(stderr, "%ld ", f_prime_times_g[i]);
    fprintf(stderr, "\n");
    /// print
    ptf("f(x): ");
    if (f[f_degree] == 1)
        ptf("x^%lu", f_degree);
    else if (f[f_degree] == -1)
        ptf("-x^%lu", f_degree);
    else
        ptf("%ldx^%lu", f[f_degree], f_degree);
    for (i64 i = f_degree - 1; i > 0; i--)
    {
        if (f[i] != 0)
            if (f[i] == 1)
                ptf(" + x^%lu", i);
            else if (f[i] == -1)
                ptf(" + -x^%lu", i);
            else
                ptf(" + %ldx^%lu", f[i], i);
    }
    if (f[0])
        ptf(" + %ld", f[0]);
    ptf("\n");
    ptf("g(x): ");
    if (g[g_degree] == 1)
        ptf("x^%lu", g_degree);
    else if (g[g_degree] == -1)
        ptf("-x^%lu", g_degree);
    else
        ptf("%ldx^%lu", g[g_degree], g_degree);
    for (i64 i = g_degree - 1; i > 0; i--)
    {
        if (g[i] != 0)
            if (g[i] == 1)
                ptf("x^%lu", i);
            else if (g[i] == -1)
                ptf("-x^%lu", i);
            else
                ptf(" + %ldx^%lu", g[i], i);
    }
    if (g[0])
        ptf(" + %ld", g[0]);
    ptf("\n");
    ptf("(f(x)g(x))': ");
    if (f_times_g_prime[f_degree + g_degree - 1] + f_prime_times_g[f_degree + g_degree - 1] == 1)
        ptf("x^%lu", f_degree + g_degree - 1);
    else if (f_times_g_prime[f_degree + g_degree - 1] + f_prime_times_g[f_degree + g_degree - 1] == -1)
        ptf("-x^%lu", f_degree + g_degree - 1);
    else
        ptf("%ldx^%lu", f_times_g_prime[f_degree + g_degree - 1] + f_prime_times_g[f_degree + g_degree - 1], f_degree + g_degree - 1);
    for (i64 i = f_degree + g_degree - 2; i > 1; i--)
    {
        if (f_times_g_prime[i] + f_prime_times_g[i] != 0)
            if (f_times_g_prime[i] + f_prime_times_g[i] == 1)
                ptf("+x^%lu", i);
            else if (f_times_g_prime[i] + f_prime_times_g[i] == -1)
                ptf("+-x^%lu", i);
            else
                ptf("+%ldx^%lu", f_times_g_prime[f_degree + g_degree - i] + f_prime_times_g[f_degree + g_degree - i], f_degree + g_degree - i - 1);
    }
    //// x^1
    if (f_times_g_prime[0] + f_prime_times_g[0])
        ptf("+%ld", f_times_g_prime[0] + f_prime_times_g[0]);
    ptf("\n");
    u64 ch_degree = f_degree + g_degree - 1;
    u64 m_degree = g_degree * 2;
    for (i64 i = 0; i < (ch_degree < m_degree) ? (ch_degree) : (m_degree); i--)
    {
        if (g_sqare[i] == 0 && f_times_g_prime[i] - f_prime_times_g[i] == 0)
        {
            ch_degree--;
            m_degree--;
        }
    }
    if (g_sqare[0] == 0 && g_degree == 0) // 如遇到 division by zero 情況，除法部分請當作0/0做輸出
    {
        ptf(" f(x)    0\n");
        ptf("(----)': -\n");
        ptf(" g(x)    0\n");
        return 0;
    }
    uint64_t ch = 0, m = 0;
    {

        for (i64 i = ch_degree; i > 0; i--)
        {
            int64_t ch_n = f_prime_times_g[i] - f_times_g_prime[i];
            if (ch_n)
            {
                if (ch_n < 0)
                {
                    ch++;
                }
                if (ch_n == 1)
                {
                    ch--;
                }
                else
                {
                    if (ch_n != -1)
                        while (ch_n)
                        {
                            ch++;
                            ch_n /= 10;
                        }
                }
                u64 ch_d = ch_degree - i;
                if (ch_d < 0)
                {
                    ch++;
                }
                while (ch_d)
                {
                    ch++;
                    ch_d /= 10;
                }
                ch += 2; // x^
            }
        }
        int64_t end_ch = f_prime_times_g[0] - f_times_g_prime[0];
        if (end_ch < 0)
        {
            ch++;
        }
        while (end_ch)
        {
            ch++;
            end_ch /= 10;
        }
        for (i64 i = m_degree; i > 0; i--)
        {
            int64_t m_n = g_sqare[i];
            if (m_n < 0)
            {
                m++;
            }
            if (m_n == 1)
            {
                m--;
            }
            else
            {
                if (m_n != -1)
                    while (m_n)
                    {
                        m++;
                        m_n /= 10;
                    }
            }
            u64 m_d = m_degree - i;
            if (m_d < 0)
            {
                ch++;
            }
            while (m_d)
            {
                ch++;
                m_d /= 10;
            }
            m += 2; // x^
        }
        int64_t end_m = g_sqare[0];
        if (end_m < 0)
        {
            m++;
        }
        while (end_m)
        {
            m++;
            end_m /= 10;
        }
    }
    // 1/1
    ptf(" f(x)    ");
    if (f_prime_times_g[f_degree + g_degree - 1] - f_times_g_prime[f_degree + g_degree - 1] == 1)
        ptf("x^%lu", f_degree + g_degree - 1);
    else if (f_prime_times_g[f_degree + g_degree - 1] - f_times_g_prime[f_degree + g_degree - 1] == -1)
        ptf("+-x^%lu", f_degree + g_degree - 1);
    else
        ptf("%ldx^%lu", f_prime_times_g[f_degree + g_degree - 1] - f_times_g_prime[f_degree + g_degree - 1], f_degree + g_degree - 1);
    for (i64 i = f_degree + g_degree - 2; i > f_degree + g_degree - 1 - ch_degree; i--)
        if (f_prime_times_g[i] - f_times_g_prime[i])
            if (f_prime_times_g[i] - f_times_g_prime[i] == 1)
                ptf("+x^%lu", i);
            else if (f_prime_times_g[i] - f_times_g_prime[i] == -1)
                ptf("+-x^%lu", i);
            else
                ptf("+%ldx^%lu", f_prime_times_g[i] - f_times_g_prime[i], i);
    if (f_prime_times_g[ch_degree] - f_times_g_prime[ch_degree])
        ptf("+%ld", f_prime_times_g[ch_degree] - f_times_g_prime[ch_degree]);
    ptf("\n");
    ptf("(----)': ");
    for (i64 i = 0; i < (m > ch ? m : ch); i++)
        ptf("-");
    ptf("\n");
    ptf(" g(x)    ");
    if (g_sqare[m_degree * 2])
        if (g_sqare[m_degree * 2] == 1)
            ptf("x^%lu", m_degree * 2);
        else if (g_sqare[m_degree * 2] == -1)
            ptf("-x^%lu", m_degree * 2);
        else
            ptf("%ldx^%lu", g_sqare[m_degree * 2], m_degree * 2);
    for (i64 i = m_degree * 2 - 1; i > 2 * g_degree - m_degree; i--)
        if (g_sqare[i])
            if (g_sqare[i] == 1)
                ptf("+x^%lu", i);
            else if (g_sqare[i] == -1)
                ptf("+-x^%lu", i);
            else
                ptf("+%ldx^%lu", g_sqare[i], i);
    if (g_sqare[m_degree])
        ptf("%ld", g_sqare[m_degree]);
    ptf("\n");
    return 0;
}