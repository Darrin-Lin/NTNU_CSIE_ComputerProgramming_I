#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define twoPower31 2147483648 // becauce can't use bitwise operator so cnn't use 1<<32
#define ptf printf

void BinaryForm(int32_t);

int main()
{
    static int64_t inp = 0;
    static int32_t wrongInput = 0; // will have bug if input ==1<<33
    ptf("Please enter the number: ");
    scanf("%ld", &inp);
    scanf("%*[a-z-A-Z]%n", &wrongInput);
    if (wrongInput)
    {
        ptf("The input is not a number!\n");
        return 1;
    }
    if (inp > twoPower31 - 1)
    {
        ptf("The number is too large!\n");
        return 1;
    }
    if (inp < -twoPower31)
    {
        ptf("The number is too small!\n");
        return 1;
    }
    // fprintf(stderr, "%d", ~-2);
    BinaryForm((int)inp);

    return 0;
}

void BinaryForm(int32_t in)
{
    {
        int8_t b0 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0, b5 = 0, b6 = 0, b7 = 0, b8 = 0, b9 = 0, b10 = 0, b11 = 0, b12 = 0, b13 = 0, b14 = 0, b15 = 0, b16 = 0, b17 = 0, b18 = 0, b19 = 0, b20 = 0, b21 = 0, b22 = 0, b23 = 0, b24 = 0, b25 = 0, b26 = 0, b27 = 0, b28 = 0, b29 = 0, b30 = 0, b31 = 0;
        int8_t negative = 0;
        if (in < 0)
        {
            negative = 1;
            in = -in - 1;
            b31 = 1;
            b0 = 1, b1 = 1, b2 = 1, b3 = 1, b4 = 1, b5 = 1, b6 = 1, b7 = 1, b8 = 1, b9 = 1, b10 = 1, b11 = 1, b12 = 1, b13 = 1, b14 = 1, b15 = 1, b16 = 1, b17 = 1, b18 = 1, b19 = 1, b20 = 1, b21 = 1, b22 = 1, b23 = 1, b24 = 1, b25 = 1, b26 = 1, b27 = 1, b28 = 1, b29 = 1, b30 = 1;
        }
        {
            b0 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b1 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b2 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b3 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b4 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b5 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b6 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b7 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b8 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b9 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b10 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b11 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b12 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b13 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b14 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b15 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b16 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b17 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b18 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b19 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b20 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b21 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b22 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b23 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b24 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b25 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b26 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b27 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b28 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b29 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
            b30 = in % 2 && !negative || !(in % 2) && negative ? 1 : 0;
            in = in / 2;
        }
        ptf("%d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d\n", b31, b30, b29, b28, b27, b26, b25, b24, b23, b22, b21, b20, b19, b18, b17, b16, b15, b14, b13, b12, b11, b10, b9, b8, b7, b6, b5, b4, b3, b2, b1, b0);
    }
    // 32bit
    /*
    int32_t i = 0;
    int32_t negative = 0;
    start:;
    if(in>0)
    {
        if(in<0&&i==0)
        {
            negative = 1;
            ptf("1");
            in = -in;
        }
        else if(i==0)
        {
            ptf("0");
        }
        else
        {
            if(negative)
            {
                ptf("%d",!(in%2));
                in = in/2;
            }
            else
            {
                ptf("%d",in%2);
                in = in/2;
            }
            ptf("%d",in%2);
            in = in/2;
        }
        i++;
        goto start;
    }
    */
}