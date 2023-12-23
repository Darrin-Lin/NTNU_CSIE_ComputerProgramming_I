#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int32_t frac_add(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_del(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_mul(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_div(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);

static int64_t gcd(int64_t a, int64_t b);

static int64_t gcd(int64_t a, int64_t b)
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
    int64_t temp_x = (int64_t)a * d + (int64_t)b * c;
    int64_t temp_y = (int64_t)b * d;
    int64_t g = gcd(temp_x, temp_y);
    temp_x /= g;
    temp_y /= g;
    if (temp_x > INT32_MAX || temp_x < INT32_MIN || temp_y > INT32_MAX || temp_y < INT32_MIN)
    {
        return -1;
    }
    if (temp_y < 0)
    {
        temp_x *= -1;
        temp_y *= -1;
    }
    *x = (int32_t)temp_x;
    *y = (int32_t)temp_y;
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
    int64_t temp_x = (int64_t)a * d - (int64_t)b * c;
    int64_t temp_y = (int64_t)b * d;
    int64_t g = gcd(temp_x, temp_y);
    temp_x /= g;
    temp_y /= g;
    if (temp_x > INT32_MAX || temp_x < INT32_MIN || temp_y > INT32_MAX || temp_y < INT32_MIN)
    {
        return -1;
    }
    if (temp_y < 0)
    {
        temp_x *= -1;
        temp_y *= -1;
    }
    *x = (int32_t)temp_x;
    *y = (int32_t)temp_y;
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
    int64_t temp_x = (int64_t)a * c;
    int64_t temp_y = (int64_t)b * d;
    int64_t g = gcd(temp_x, temp_y);
    temp_x /= g;
    temp_y /= g;
    if (temp_x > INT32_MAX || temp_x < INT32_MIN || temp_y > INT32_MAX || temp_y < INT32_MIN)
    {
        return -1;
    }
    if (temp_y < 0)
    {
        temp_x *= -1;
        temp_y *= -1;
    }
    *x = (int32_t)temp_x;
    *y = (int32_t)temp_y;
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
    int64_t temp_x = (int64_t)a * d;
    int64_t temp_y = (int64_t)b * c;
    int64_t g = gcd(temp_x, temp_y);
    temp_x /= g;
    temp_y /= g;
    if (temp_x > INT32_MAX || temp_x < INT32_MIN || temp_y > INT32_MAX || temp_y < INT32_MIN)
    {
        return -1;
    }
    if (temp_y < 0)
    {
        temp_x *= -1;
        temp_y *= -1;
    }
    *x = (int32_t)temp_x;
    *y = (int32_t)temp_y;
    return 0;
}