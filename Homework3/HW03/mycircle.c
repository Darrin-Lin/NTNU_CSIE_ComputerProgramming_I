#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#define pi 3.141592653589793238462643383279502884L

int32_t set_radius(double r);
double get_circle_circumference();
double get_circle_area();
double get_tangent_area(double x);
double get_inner_regular_polygon_area(int32_t n);
double get_outer_regular_polygon_area(int32_t n);

static double radius = 0;
static int8_t radius_set = 0;
int32_t set_radius(double r)
{   radius = r;
    radius_set = r<=0?0:1;
    return r<=0?-1:0;
}
double get_circle_circumference()
{
    if(radius_set==0)
        return -1;
    else
    {
        return (double)((double)2*pi*radius);
    }
}
double get_circle_area()
{
    if(radius_set==0)
        return -1;
    else
    {
        return (double)((double)pi*radius*radius);
    }
}
double get_tangent_area(double x)
{
    if(radius_set==0)
        return -1;
    else if (/*input not reasonable*/)
        return -2;
    else if (/*can't form a triangle*/)
        return -3;
    else
    {
        return /*area*/;
    }
    
}
double get_inner_regular_polygon_area(int32_t n)
{
    if(radius_set==0)
        return -1;
    else if (n<3)
        return -2;
    else
    {
        return /*area*/;
    }
    
}
double get_outer_regular_polygon_area(int32_t n)
{
    if(radius_set==0)
        return -1;
    else if (n<3)
        return -2;
    else
    {
        return /*area*/;
    }
}
