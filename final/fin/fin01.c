#include <stdio.h>
#include <stdint.h>
#include "frac.h"

int main()
{
    int32_t x, y;
    int32_t a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n",frac_add(&x, &y, a, b, c, d));
    printf("%d %d\n", x, y);
    printf("%d\n",frac_del(&x, &y, a, b, c, d));
    printf("%d %d\n", x, y);
    printf("%d\n",frac_mul(&x, &y, a, b, c, d));
    printf("%d %d\n", x, y);
    printf("%d\n",frac_div(&x, &y, a, b, c, d));
    printf("%d %d\n", x, y);

    return 0;
}