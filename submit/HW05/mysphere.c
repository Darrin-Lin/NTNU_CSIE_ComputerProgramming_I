#include <stdint.h>
// #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ax + by + cz = d
int32_t get_cap_area(double r, double a, double b, double c, double d, double *pArea);

int32_t get_cap_area(double r, double a, double b, double c, double d, double *pArea)
{
    if (pArea == NULL)
    {
        return -1;
    }
    if (r <= 0)
    {
        return -1;
    }
    double distance = 0;
    if (a == b && b == c && c == 0)
    {
        return 0;
    }
    // distance = fabs(a * 0 + b * 0 + c * 0 - d) / sqrt(a * a + b * b + c * c);
    distance = fabs(d) / sqrt(a * a + b * b + c * c);
    if (distance == r)
    {
        *pArea = 0;
        return 1;
    }
    else if (distance > r)
    {
        *pArea = 0;
        return 1;
    }
    else
    {
        double area = 0;
        area = M_PI * (r * r - distance * distance);
        area = (int)(area * 100 + 0.5) / 100.0;
        *pArea = area;
        return 1;
    }
}