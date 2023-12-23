#include <stdio.h>
#include <stdint.h>
#include "firewall.h"

int main()
{
    
    int32_t *ptr = NULL;
    ptr = calloc(25, sizeof(int32_t));
    ptr = realloc(ptr, 20 * sizeof(int32_t));
    free(ptr);
    return 0;
}