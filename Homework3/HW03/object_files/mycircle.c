#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define pi 3.141592653589793238462643383279502884

int32_t set_radius(double r);
double get_circle_circumference();
double get_circle_area();
double get_tangent_area(double x);
double get_inner_regular_polygon_area(int32_t n);
double get_outer_regular_polygon_area(int32_t n);

static double radius = 0;
static int8_t radius_set = 0;
static double y = 0;
static double compare_double = 1e-6;

int32_t set_radius(double r)
{
    radius = r <= 0 ? radius : r;
    radius_set = radius <= 0 ? 0 : 1;
    return r <= 0 ? -1 : 0;
}
double get_circle_circumference()
{
    if (radius_set == 0)
        return -1;
    else
    {
        return 2.0 * pi * radius;
    }
}
double get_circle_area()
{
    if (radius_set == 0)
        return -1;
    else
    {
        return pi * radius * radius;
    }
}
double get_tangent_area(double x)
{
    if (radius_set == 0)
        return -1;
    else if (fabs(x) - radius > -1 * compare_double)
        return -2;
    else if (fabs(fabs(x) - radius) < compare_double || fabs(x) < compare_double)
        return -3;
    else
    {
        y = sqrt(radius * radius - x * x);
        //m=-y/x _y_=m(0-x)+y=2y _x_=(0-y)/m+x=2x
        return (2*y)*(2*x)/2;
    }
}
double get_inner_regular_polygon_area(int32_t n)
{
    if (radius_set == 0)
        return -1;
    else if (n < 3)
        return -2;
    else
    {   
        return get_circle_area()/(((double)n/(2.0*pi))*sin(2.0*pi/(double)n));;
    }
}
double get_outer_regular_polygon_area(int32_t n)
{
    if (radius_set == 0)
        return -1;
    else if (n < 3)
        return -2;
    else
    {
        return get_circle_area() /((pi/(double)n)/tan(pi/(double)n));
    }
}
