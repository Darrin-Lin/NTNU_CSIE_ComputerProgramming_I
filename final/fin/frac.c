#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int32_t frac_add(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_del(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_mul(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_div(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);

static int32_t gcd(int32_t a, int32_t b);

static int32_t gcd(int32_t a, int32_t b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int32_t frac_add(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (x == NULL || y == NULL)
    {
        return -1;
    }
    if (b == 0 || d == 0)
    {
        return -1;
    }
    *x = a * d + b * c;
    *y = b * d;
    int32_t g = gcd(*x, *y);
    *x /= g;
    *y /= g;
    return 0;
}

int32_t frac_del(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (x == NULL || y == NULL)
    {
        return -1;
    }
    if (b == 0 || d == 0)
    {
        return -1;
    }
    *x = a * d - b * c;
    *y = b * d;
    int32_t g = gcd(*x, *y);
    *x /= g;
    *y /= g;
    return 0;
}

int32_t frac_mul(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (x == NULL || y == NULL)
    {
        return -1;
    }
    if (b == 0 || d == 0)
    {
        return -1;
    }
    *x = a * c;
    *y = b * d;
    int32_t g = gcd(*x, *y);
    *x /= g;
    *y /= g;
    return 0;
}

int32_t frac_div(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d)
{
    if (x == NULL || y == NULL)
    {
        return -1;
    }
    if (b == 0 || d == 0)
    {
        return -1;
    }
    if (c == 0)
    {
        return -1;
    }
    *x = a * d;
    *y = b * c;
    int32_t g = gcd(*x, *y);
    *x /= g;
    *y /= g;
    return 0;
}