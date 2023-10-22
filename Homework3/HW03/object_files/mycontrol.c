#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

void initialize(double x, double y, double a);
int32_t forward(double length);
int32_t clock_turn(double x);
int32_t counterclock_turn(double x);
int32_t print();

#define pi 3.141592653589793238462643383279502884
#define compare_double 1e-6

static double x_value = 0, y_value = 0, radian = 0;
static int8_t init = 0;

void initialize(double x, double y, double a)
{
    init = 1;
    x_value = x;
    radian = a;
    y_value = y;
    return;
}
int32_t forward(double length)
{
    if (!init)
        return -1;
    x_value += length * cos(radian);
    y_value += length * sin(radian);
    return 0;
}
int32_t clock_turn(double x)
{
    if (!init)
        return -1;
    radian -= x;
    return 0;
}
int32_t counterclock_turn(double x)
{
    if (!init)
        return -1;
    radian += x;
    return 0;
}
int32_t print()
{
    if (!init)
        return -1;
    if (radian - 2 * pi > compare_double)
        radian = fmod(radian, 2 * pi);
    else if (radian < 0)
        radian = fmod(radian, 2 * pi)+2*pi;
            printf("position : (%.2f,%.2f), angle : %.2f", x_value, y_value, radian / pi);
    return 0;
}