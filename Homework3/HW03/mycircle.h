#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#pragma once

int32_t set_radius(double r);
double get_circle_circumference();
// double get_circle_area();
double get_circle_area(double x);
double get_inner_regular_polygon_area(int32_t n);
double get_outer_regular_polygon_area(int32_t n);
