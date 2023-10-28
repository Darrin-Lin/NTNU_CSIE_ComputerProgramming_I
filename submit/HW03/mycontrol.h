#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

#pragma once

void initialize(double x, double y, double a);
int32_t forward(double length);
int32_t clock_turn(double x);
int32_t counterclock_turn(double x);
int32_t print();
