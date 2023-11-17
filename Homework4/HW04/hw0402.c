#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define ptf printf
#define i64 int64_t
#define u64 uint64_t

int main()
{
    i64 f_degree = 0, g_degree = 0;
    ptf("Please enter f(x) degree: ");
    scanf("%lu", &f_degree);
    if (f_degree > ((i64)1 << 32))
    {
        ptf("f(x) degree is too large.\n");
        return 0;
    }
    i64 f_inp[f_degree + 1];
    ptf("Please enter f(x) coefficients: ");
    for (u64 i = 0; i <= f_degree; i++)
    {
        scanf("%ld", &f_inp[i]);
        if (f_inp[i] > ((i64)1 << 31) - 1)
        {
            ptf("f(x) coefficient is too large.\n");
            return 0;
        }
        else if (f_inp[i] < -((i64)1 << 31))
        {
            ptf("f(x) coefficient is too small.\n");
            return 0;
        }
    }
    ptf("Please enter g(x) degree: ");
    scanf("%lu", &g_degree);
    if (g_degree > ((i64)1 << 32))
    {
        ptf("g(x) degree is too large.\n");
        return 0;
    }
    i64 g_inp[g_degree + 1];
    ptf("Please enter g(x) coefficients: ");
    for (u64 i = 0; i <= g_degree; i++)
    {
        scanf("%ld", &g_inp[i]);
        if (g_inp[i] > ((i64)1 << 31) - 1)
        {
            ptf("g(x) coefficient is too large.\n");
            return 0;
        }
        else if (g_inp[i] < -((i64)1 << 31))
        {
            ptf("g(x) coefficient is too small.\n");
            return 0;
        }
    }
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
    for (u64 i = 0; i < f_degree + g_degree; i++)
        f_times_g_prime[i] = 0;
    for (u64 i = 0; i <= f_degree; i++)
        for (u64 j = 0; j < g_degree; j++)
            f_times_g_prime[i + j] += f[i] * g_prime[j];
    // fprintf(stderr, "\n");
    // for (int64_t i = 0; i < f_degree + g_degree; i++)
    //     fprintf(stderr, "%ld ", f_times_g_prime[i]);
    // fprintf(stderr, "\n");
    i64 f_prime_times_g[f_degree + g_degree];
    for (u64 i = 0; i < f_degree + g_degree; i++)
        f_prime_times_g[i] = 0;
    for (u64 i = 0; i < f_degree; i++)
        for (u64 j = 0; j <= g_degree; j++)
            f_prime_times_g[i + j] += f_prime[i] * g[j];
    // for (int64_t i = 0; i < f_degree + g_degree; i++)
    //     fprintf(stderr, "%ld ", f_prime_times_g[i]);
    // fprintf(stderr, "\n\n");
    /// print
    ptf("f(x): ");
    if (f_degree > 1)
        if (f[f_degree] == 1)
            ptf("x^%lu", f_degree);
        else if (f[f_degree] == -1)
            ptf("-x^%lu", f_degree);
        else
            ptf("%ldx^%lu", f[f_degree], f_degree);
    for (i64 i = f_degree - 1; i > 1; i--)
    {
        if (f[i] != 0)
            if (f[i] == 1)
                ptf(" + x^%lu", i);
            else if (f[i] == -1)
                ptf(" - x^%lu", i);
            else if (f[i] > 0)
                ptf(" + %ldx^%lu", f[i], i);
            else
                ptf(" - %ldx^%lu", -f[i], i);
    }
    if (f_degree > 0)
        if (f[1])
            if (f_degree != 1)
            {
                if (f[1] == 1)
                    ptf(" + x");
                else if (f[1] == -1)
                    ptf(" - x");
                else if (f[1] > 0)
                    ptf(" + %ldx", f[1]);
                else
                    ptf(" - %ldx", -f[1]);
            }
            else
            {
                if (f[1] == 1)
                    ptf("x");
                else if (f[1] == -1)
                    ptf("-x");
                else if (f[1] > 0)
                    ptf("%ldx", f[1]);
                else
                    ptf("-%ldx", -f[1]);
            }
    if (f_degree > 0)
    {
        if (f[0])
            if (f[0] > 0)
                ptf(" + %ld", f[0]);
            else
                ptf(" - %ld", -f[0]);
    }
    else
        ptf("%ld", f[0]);
    ptf("\n");
    ptf("g(x): ");
    if (g_degree > 1)
        if (g[g_degree] == 1)
            ptf("x^%lu", g_degree);
        else if (g[g_degree] == -1)
            ptf("-x^%lu", g_degree);
        else
            ptf("%ldx^%lu", g[g_degree], g_degree);

    for (i64 i = g_degree - 1; i > 1; i--)
    {
        if (g[i] != 0)

            if (g[i] == 1)
                ptf(" + x^%lu", i);
            else if (g[i] == -1)
                ptf(" - x^%lu", i);
            else if (g[i] > 0)
                ptf(" + %ldx^%lu", g[i], i);
            else
                ptf(" - %ldx^%lu", -g[i], i);
    }
    if (g_degree > 0)
        if (g[1])
            if (g_degree != 1)
            {
                if (g[1] == 1)
                    ptf(" + x");
                else if (g[1] == -1)
                    ptf(" - x");
                else if (g[1] > 0)
                    ptf(" + %ldx", g[1]);
                else
                    ptf(" - %ldx", -g[1]);
            }
            else
            {
                if (g[1] == 1)
                    ptf("x");
                else if (g[1] == -1)
                    ptf("-x");
                else if (g[1] > 0)
                    ptf("%ldx", g[1]);
                else
                    ptf("-%ldx", -g[1]);
            }
    if (g_degree > 0)
    {
        if (g[0])
            if (g[0] > 0)
                ptf(" + %ld", g[0]);
            else
                ptf(" - %ld", -g[0]);
    }
    else
        ptf("%ld", g[0]);
    ptf("\n");
    ptf("(f(x)g(x))': ");
    if (f_degree + g_degree - 1 > 0)
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
                ptf(" + x^%lu", i);
            else if (f_times_g_prime[i] + f_prime_times_g[i] == -1)
                ptf(" - x^%lu", i);
            else if (f_times_g_prime[i] + f_prime_times_g[i] > 0)
                ptf(" + %ldx^%lu", f_times_g_prime[i] + f_prime_times_g[i], i);
            else
                ptf(" - %ldx^%lu", -f_times_g_prime[i] - f_prime_times_g[i], i);
    }
    //// x^1
    if (f_degree + g_degree - 1 > 0)
        if (f_times_g_prime[1] + f_prime_times_g[1])
            if (f_degree + g_degree - 1 > 1)
            {
                if (f_times_g_prime[1] + f_prime_times_g[1] == 1)
                    ptf(" + x");
                else if (f_times_g_prime[1] + f_prime_times_g[1] == -1)
                    ptf(" - x");
                else if (f_times_g_prime[1] + f_prime_times_g[1] > 0)
                    ptf(" + %ldx", f_times_g_prime[1] + f_prime_times_g[1]);
                else
                    ptf(" - %ldx", -f_times_g_prime[1] - f_prime_times_g[1]);
            }
            else
            {
                if (f_times_g_prime[1] + f_prime_times_g[1] == 1)
                    ptf("x");
                else if (f_times_g_prime[1] + f_prime_times_g[1] == -1)
                    ptf("-x");
                else if (f_times_g_prime[1] + f_prime_times_g[1] > 0)
                    ptf("%ldx", f_times_g_prime[1] + f_prime_times_g[1]);
                else
                    ptf("-%ldx", -f_times_g_prime[1] - f_prime_times_g[1]);
            }
    if (f_degree + g_degree - 1 > 0)
    {
        if (f_times_g_prime[0] + f_prime_times_g[0])
            if (f_times_g_prime[0] + f_prime_times_g[0] > 0)
                ptf(" + %ld", f_times_g_prime[0] + f_prime_times_g[0]);
            else
                ptf(" - %ld", -(f_times_g_prime[0] + f_prime_times_g[0]));
    }
    else
        ptf("%ld", f_times_g_prime[0] + f_prime_times_g[0]);
    ptf("\n");
    u64 ch_degree = f_degree + g_degree - 1;
    u64 m_degree = g_degree * 2;
    // 包含多項式的除法
    // function f(x) / g(x)
    u64 degree_counter_stop = (ch_degree < m_degree) ? (ch_degree) : (m_degree);
    for (i64 i = 0; i < degree_counter_stop; i--)
    {
        if (g_sqare[i] == 0 && f_prime_times_g[i] - f_times_g_prime[i] == 0)
        {
            ch_degree--;
            m_degree--;
        }
    }
    i64 ch_coefficient[ch_degree + 1];
    for (u64 i = 0; i <= ch_degree; i++)
        ch_coefficient[i] = 0;
    for (u64 i = 0; i <= ch_degree; i++)
        ch_coefficient[i] = f_prime_times_g[i + f_degree + g_degree - 1 - ch_degree] - f_times_g_prime[i + f_degree + g_degree - 1 - ch_degree];
    i64 m_coefficient[m_degree + 1];
    for (u64 i = 0; i <= m_degree; i++)
        m_coefficient[i] = 0;
    for (u64 i = 0; i <= m_degree; i++)
        m_coefficient[i] = g_sqare[i + g_degree * 2 - m_degree];
    if (g_sqare[0] == 0 && g_degree == 0) // 如遇到 division by zero 情況，除法部分請當作0/0做輸出
    {
        ptf(" f(x)    0\n");
        ptf("(----)': -\n");
        ptf(" g(x)    0\n");
        return 0;
    }
    uint64_t ch = 0, m = 0;
    {
        int32_t first_appeared = 0;
        char ch_str[100];
        for (i64 i = ch_degree; i > 1; i--)
        {
            if (first_appeared)
            {
                if (ch_coefficient[i])
                {
                    if (ch_coefficient[i] == 1)
                        sprintf(ch_str, " + x^%lu", i);
                    else if (ch_coefficient[i] == -1)
                        sprintf(ch_str, " - x^%lu", i);
                    else if (ch_coefficient[i] > 0)
                        sprintf(ch_str, " + %ldx^%lu", ch_coefficient[i], i);
                    else
                        sprintf(ch_str, " - %ldx^%lu", -f_prime_times_g[i] + f_times_g_prime[i], i);
                    ch += strlen(ch_str);
                }
            }
            else
            {
                if (ch_coefficient[i])
                {
                    if (ch_coefficient[i] == 1)
                        sprintf(ch_str, "x^%lu", i);
                    else if (ch_coefficient[i] == -1)
                        sprintf(ch_str, "-x^%lu", i);
                    else if (ch_coefficient[i] > 0)
                        sprintf(ch_str, "%ldx^%lu", ch_coefficient[i], i);
                    else
                        sprintf(ch_str, "-%ldx^%lu", -f_prime_times_g[i] + f_times_g_prime[i], i);
                    ch += strlen(ch_str);
                }
                first_appeared = 1;
            }
        }
        if (ch_degree > 0)
            if (ch_coefficient[1])
            {
                if (first_appeared)
                    if (ch_coefficient[1] == 1)
                        sprintf(ch_str, " + x");
                    else if (ch_coefficient[1] == -1)
                        sprintf(ch_str, " - x");
                    else if (ch_coefficient[1] > 0)
                        sprintf(ch_str, " + %ldx", ch_coefficient[1]);
                    else
                        sprintf(ch_str, " - %ldx", ch_coefficient[1]);
                else
                {
                    if (ch_coefficient[1] == 1)
                        sprintf(ch_str, "x");
                    else if (ch_coefficient[1] == -1)
                        sprintf(ch_str, "-x");
                    else if (ch_coefficient[1] > 0)
                        sprintf(ch_str, "%ldx", ch_coefficient[1]);
                    else
                        sprintf(ch_str, "-%ldx", ch_coefficient[1]);
                    first_appeared = 1;
                }
                ch += strlen(ch_str);
            }
        if (ch_coefficient[0])
        {
            if (ch_coefficient[0] > 0)
                if (first_appeared)
                    sprintf(ch_str, " + %ld", ch_coefficient[0]);
                else
                    sprintf(ch_str, "%ld", ch_coefficient[0]);
            else
            {
                if (first_appeared)
                    sprintf(ch_str, " - %ld", -ch_coefficient[0]);
                else
                    sprintf(ch_str, "%ld", ch_coefficient[0]);
            }
            ch += strlen(ch_str);
        }

        char m_str[100];
        if (m_degree > 1)
        {
            if (m_coefficient[m_degree] == 1)
                sprintf(m_str, "x^%lu", m_degree);
            else if (m_coefficient[m_degree] == -1)
                sprintf(m_str, "-x^%lu", m_degree);
            else
                sprintf(m_str, "%ldx^%lu", m_coefficient[m_degree], m_degree);
            m += strlen(m_str);
        }
        for (i64 i = m_degree - 1; i > 1; i--)
        {
            if (m_coefficient[i])
            {
                if (m_coefficient[i] == 1)
                    sprintf(m_str, " + x^%lu", i);
                else if (m_coefficient[i] == -1)
                    sprintf(m_str, " - x^%lu", i);
                else if (m_coefficient[i] > 0)
                    sprintf(m_str, " + %ldx^%lu", m_coefficient[i], i);
                else
                    sprintf(m_str, " - %ldx^%lu", -m_coefficient[i], i);
                m += strlen(m_str);
            }
        }

        if (m_degree > 0)
            if (m_coefficient[1])
            {
                if (m_degree != 1)
                    if (m_coefficient[1] == 1)
                        sprintf(m_str, " + x");
                    else if (m_coefficient[1] == -1)
                        sprintf(m_str, " - x");
                    else if (m_coefficient[1] > 0)
                        sprintf(m_str, " + %ldx", m_coefficient[1]);
                    else
                        sprintf(m_str, " - %ldx", -m_coefficient[1]);
                else
                {
                    if (m_coefficient[1] == 1)
                        sprintf(m_str, "x");
                    else if (m_coefficient[1] == -1)
                        sprintf(m_str, "-x");
                    else if (m_coefficient[1] > 0)
                        sprintf(m_str, "%ldx", m_coefficient[1]);
                    else
                        sprintf(m_str, "-%ldx", -m_coefficient[1]);
                }
                m += strlen(m_str);
            }
        if (m_coefficient[0])
        {
            if (m_coefficient[0] > 0)
                sprintf(m_str, " + %ld", m_coefficient[0]);
            else
                sprintf(m_str, " - %ld", -m_coefficient[0]);
            m += strlen(m_str);
        }
        //     int64_t ch_n = ch_coefficient[i];
        //     if (ch_n)
        //     {
        //         if (ch_n < 0 && fir == 0)
        //         {
        //             ch++;
        //             fir = 1;
        //         }
        //         if (ch_n == 1)
        //         {
        //             ch--;
        //         }
        //         else
        //         {
        //             if (ch_n != -1 && ch_n != 1)
        //                 while (ch_n)
        //                 {
        //                     ch++;
        //                     ch_n /= 10;
        //                 }
        //         }
        //         u64 ch_d = ch_degree - i;
        //         if (ch_d < 0)
        //         {
        //             ch++;
        //         }
        //         if (ch_d != 1)
        //         {
        //             while (ch_d)
        //             {
        //                 ch++;
        //                 ch_d /= 10;
        //             }
        //             ch += 2; // x^
        //         }
        //         ch += 3; // _+_
        //         fir = 1;
        //     }
        // }
        // if (fir)
        //     ch -= 2; // _+_ first
        // int64_t end_ch = ch_coefficient[0];
        // if (end_ch < 0 && fir == 0)
        // {
        //     ch++;
        //     fir = 1;
        // }
        // while (end_ch)
        // {
        //     ch++;
        //     end_ch /= 10;
        // }
        // fir = 0;
        // for (i64 i = m_degree; i > 0; i--)
        // {
        //     int64_t m_n = m_coefficient[i];
        //     if (m_n)
        //     {
        //         if (m_n < 0 && fir == 0)
        //         {
        //             m++;
        //             fir = 1;
        //         }
        //         else
        //         {
        //             if (m_n != -1 && m_n != 1)
        //                 while (m_n)
        //                 {
        //                     m++;
        //                     m_n /= 10;
        //                 }
        //         }
        //         u64 m_d = m_degree - i;
        //         if (m_d < 0 && fir == 0)
        //         {
        //             fir = 1;
        //             m++;
        //         }
        //         if (m_d != 1)
        //         {
        //             m++;
        //             while (m_d)
        //             {
        //                 m++;
        //                 m_d /= 10;
        //             }
        //             m += 2; // x^
        //         }
        //         m += 3; // _+_
        //         fir = 1;
        //     }
        // }
        // if (fir)
        //     m -= 2; // _+_ first
        // int64_t end_m = m_coefficient[0];
        // if (end_m < 0 && fir == 0)
        // {
        //     m++;
        //     fir = 1;
        // }
        // while (end_m)
        // {
        //     m++;
        //     end_m /= 10;
        // }
    }

    // fprintf(stderr, "\n%lu %lu\n\n", ch, m);

    // 1/1
    // may be have some bug about first coefficient
    // fprintf(stderr, "degree: %ld %ld\n", ch_degree, m_degree);

    ptf(" f(x)    ");
    int32_t first_appeared = 0;
    for (i64 i = ch_degree; i > 1; i--)
        if (first_appeared)
        {
            if (ch_coefficient[i])
                if (ch_coefficient[i] == 1)
                    ptf(" + x^%lu", i);
                else if (ch_coefficient[i] == -1)
                    ptf(" - x^%lu", i);
                else if (ch_coefficient[i] > 0)
                    ptf(" + %ldx^%lu", ch_coefficient[i], i);
                else
                    ptf(" - %ldx^%lu", -f_prime_times_g[i] + f_times_g_prime[i], i);
        }
        else
        {
            if (ch_coefficient[i])
                if (ch_coefficient[i] == 1)
                    ptf("x^%lu", i);
                else if (ch_coefficient[i] == -1)
                    ptf("-x^%lu", i);
                else if (ch_coefficient[i] > 0)
                    ptf("%ldx^%lu", ch_coefficient[i], i);
                else
                    ptf("-%ldx^%lu", -f_prime_times_g[i] + f_times_g_prime[i], i);
            first_appeared = 1;
        }
    if (ch_degree > 0)
        if (ch_coefficient[1])
            if (first_appeared)
                if (ch_coefficient[1] == 1)
                    ptf(" + x");
                else if (ch_coefficient[1] == -1)
                    ptf(" - x");
                else if (ch_coefficient[1] > 0)
                    ptf(" + %ldx", ch_coefficient[1]);
                else
                    ptf(" - %ldx", ch_coefficient[1]);
            else
            {
                if (ch_coefficient[1] == 1)
                    ptf("x");
                else if (ch_coefficient[1] == -1)
                    ptf("-x");
                else if (ch_coefficient[1] > 0)
                    ptf("%ldx", ch_coefficient[1]);
                else
                    ptf("-%ldx", ch_coefficient[1]);
                first_appeared = 1;
            }
    if (ch_coefficient[0])
        if (ch_coefficient[0] > 0)
            if (first_appeared)
                ptf(" + %ld", ch_coefficient[0]);
            else
                ptf("%ld", ch_coefficient[0]);
        else
        {
            if (first_appeared)
                ptf(" - %ld", -ch_coefficient[0]);
            else
                ptf("%ld", ch_coefficient[0]);
        }
    ptf("\n");
    ptf("(----)': ");
    for (i64 i = 0; i < (m > ch ? m : ch); i++)
        ptf("-");
    ptf("\n");
    ptf(" g(x)    ");
    // if (m_coefficient[g_degree * 2])
    if (m_coefficient[m_degree] == 1)
        ptf("x^%lu", m_degree);
    else if (m_coefficient[m_degree] == -1)
        ptf("-x^%lu", m_degree);
    else
        ptf("%ldx^%lu", m_coefficient[m_degree], m_degree);
    for (i64 i = m_degree - 1; i > 1; i--)
        if (m_coefficient[i])
            if (m_coefficient[i] == 1)
                ptf(" + x^%lu", i);
            else if (m_coefficient[i] == -1)
                ptf(" - x^%lu", i);
            else if (m_coefficient[i] > 0)
                ptf(" + %ldx^%lu", m_coefficient[i], i);
            else
                ptf(" - %ldx^%lu", -m_coefficient[i], i);
    if (m_degree > 0)
        if (m_coefficient[1])
            if (m_degree != 1)
                if (m_coefficient[1] == 1)
                    ptf(" + x");
                else if (m_coefficient[1] == -1)
                    ptf(" - x");
                else if (m_coefficient[1] > 0)
                    ptf(" + %ldx", m_coefficient[1]);
                else
                    ptf(" - %ldx", -m_coefficient[1]);
            else
            {
                if (m_coefficient[1] == 1)
                    ptf("x");
                else if (m_coefficient[1] == -1)
                    ptf("-x");
                else if (m_coefficient[1] > 0)
                    ptf("%ldx", m_coefficient[1]);
                else
                    ptf("-%ldx", -m_coefficient[1]);
            }
    if (m_coefficient[0])
        if (m_coefficient[0] > 0)
            ptf(" + %ld", m_coefficient[0]);
        else
            ptf(" - %ld", -m_coefficient[0]);
    ptf("\n");
    return 0;
}