#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma once

int32_t frac_add(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_del(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_mul(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);
int32_t frac_div(int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d);