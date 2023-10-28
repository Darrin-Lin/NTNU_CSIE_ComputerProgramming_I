#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <time.h>

#define ptf printf
#define scf scanf

int32_t dice(int32_t);
void Id6();
void AdX();
void AdXkY_add_B();
void AdXkhHklLkcC_add_B();

static int32_t result[10] = {0};
static int32_t final = 0;

int32_t dice(int32_t sides)
{
    srand(time(NULL));
    int32_t result;
    result = rand() % sides + 1;
    return result;
}

void Id6()
{
    result[0] = dice(6);
    ptf("==^==>\n");
    ptf("=>%3d>\n", result[0]);
    ptf("==v==>\n");
    ptf("result: %d\n", result[0]);
}

void AdX()
{
    int32_t A = 0, X = 0;
    ptf("Please enter A, X: ");
    scf("%d %d", &A, &X);
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==^==> ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("=>%3d> ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==v==> ");
    }
    ptf("\n");
    ptf("result: ");
    for (int32_t i = 0; i < A - 1; i++)
    {
        ptf("%d +", result[i]);
        final += result[i];
    }
    final += result[A - 1];
    ptf("%d = %d\n", result[A - 1], final);
    ptf("\n");
}

void AdXkY_add_B()
{
    int32_t A = 0, X = 0, Y = 0, B = 0;
    ptf("Please enter A, X, Y, B: ");
    scf("%d %d %d %d", &A, &X, &Y, &B);
    ptf("\n");
    for (int32_t i = 1; i <= A; i++)
    {
        ptf("v%3d   ",i);
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==^==> ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("=>%3d> ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==v==> ");
    }
    ptf("\n");
    ptf("Please choose %d dice from above: ", Y);
    int32_t choose[Y] = {0};
    for (int32_t i = 0; i < Y; i++)
        scf("%d", &choose[i]);
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==^==> ");
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("=>%3d> ", result[choose[i] - 1]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==v==> ");
    }
    ptf("result: ");
    for (int32_t i = 0; i < Y; i++)
    {
        if (B < 0 && i == Y - 1)
            ptf("%d -", result[choose[i] - 1]);
        else
            ptf("%d +", result[choose[i] - 1]);
        final += result[i];
    }
    final += B;
    ptf("%d = %d\n", abs(B), final);
    ptf("\n");
}

void AdXkhHklLkcC_add_B()
{
    int32_t A = 0, X = 0, H = 0, L = 0, C = 0, B = 0;
    ptf("Please enter A, X, H, L, C, B: ");
    scf("%d %d %d %d %d %d", &A, &X, &H, &L, &C, &B);
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==^==> ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("=>%3d> ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("==v==> ");
    }
    ptf("\n");
    int32_t sort[A] = {0};

    for (int32_t i = 0; i < A; i++)
    {
        sort[i] = result[i];
    }
    for (int32_t i = 0; i < A; i++)
    {
        for (int32_t j = 0; j < A; j++)
        {
            if (sort[i] > sort[j])
            {
                int32_t temp = sort[i];
                sort[i] = sort[j];
                sort[j] = temp;
            }
        }
    }
    ptf("Highest %d:\n", H);
    for (int32_t i = 0; i < H; i++)
    {
        ptf("==^==> ");
    }
    ptf("\n");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("=>%3d> ", sort[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("==v==> ");
    }
    ptf("\n");
    ptf("Lowest %d:\n", L);
    for (int32_t i = 0; i < L; i++)
    {
        ptf("==^==> ");
    }
    ptf("\n");
    for (int32_t i = 0; i < L; i++)
    {
        ptf("=>%3d> ", sort[A - 1 - i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < L; i++)
    {
        ptf("==v==> ");
    }
    ptf("Choose %d:\n", C);
    for(int32_t i = 0; i < A; i++)
    {
        for(int32_t j = 0; j < H; j++)
        {
            if(result[i] == sort[j])
            {
                result[i] = 0;
                break;
            }
        }
    }
    for(int32_t i = 0; i < A; i++)
    {
        for(int32_t j = 0; j < L; j++)
        {
            if(result[i] == sort[A-1-j])
            {
                result[i] = 0;
                break;
            }
        }
    }
    int32_t minus = 0;
     for (int32_t i = 1; i <= A; i++)
    {
        if(result[i] == 0)
            minus++;
        else
            ptf("v%3d   ",i-minus);
    }
    ptf("\n");
    for (int32_t i = 0; i < A-H-L; i++)
    {
        ptf("==^==> ");
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        if(result[i] == 0)
            continue;
        else
        ptf("=>%3d> ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A-H-L; i++)
    {
        ptf("==v==> ");
    }
    ptf("\n");
    ptf("Please choose %d dice from above: ", C);
    int32_t choose[C] = {0};
    for (int32_t i = 0; i < C; i++)
        scf("%d", &choose[i]);
    int32_t choose_result[C] = {0};
    int32_t plus= 0;
    for (int32_t i = 0; i < C; i++)
    {
        if(result[choose[i] - 1+plus] == 0)
        {
            plus++;
            i--;
            continue;
        }
        choose_result[i] = result[choose[i] - 1+plus];
    }
    ptf("\n");
    ptf("result: ");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("%d +", sort[i]);
        final += sort[i];
    }
    for(int32_t i = 0; i < L; i++)
    {
        ptf("%d +", sort[A-1-i]);
        final += sort[A-1-i];
    }
    for (int32_t i = 0; i < C; i++)
    {
        if (B < 0 && i == C - 1)
            ptf("%d -", choose_result[i]);
        else
            ptf("%d +", choose_result[i]);
        final += choose_result[i];
    }
    ptf("%d = %d\n", abs(B), final);
    ptf("\n");
}