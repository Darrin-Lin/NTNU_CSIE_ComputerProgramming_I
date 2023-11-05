#include "hw0304.h"

int main()
{
    int64_t inp = 0;
    int32_t wrongInput = 0; // will have bug if input ==1<<33
    printf("Please enter the disk number (2-20): ");
    scanf("%ld", &inp);
    scanf("%*[a-z-A-Z]%n", &wrongInput);
    if (wrongInput)
    {
        printf("The input is not a number!\n");
        return 1;
    }
    if (inp > 20)
    {
        printf("The number is too large!\n");
        return 1;
    }
    if (inp < 2)
    {
        printf("The number is too small!\n");
        return 1;
    }
    the_hanoi_tower((int32_t)inp);
    return 0;
}