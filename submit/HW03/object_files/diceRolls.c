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

static int32_t final = 0;

int32_t dice(int32_t sides)
{

    int32_t res = 0;
    res = rand() % sides + 1;
    // printf("\07");
    return res;
}

void Id6()
{
    srand(time(NULL));
    final = 0;
    int32_t result[10] = {0};
    result[0] = dice(6);
    ptf("\033[90;46m>####>\033[0m\n");
    ptf("\033[90;46m=>\033[93;46m%3d\033[90;46m>\033[0m\n", result[0]);
    ptf("\033[90;46m>####>\033[0m\n");
    ptf("result: \033[96m%d\033[0m\n", result[0]);
    return;
}

void AdX()
{
    int8_t err = 0;
    srand(time(NULL));
    final = 0;
    int32_t result[10] = {0};
    int32_t A = 0, X = 0;
    ptf("Please enter A, X: ");
    scf("%d %d", &A, &X);
    if (A > 10)
    {
        ptf("Too many dice!\n");
        err = 1;
    }
    else if (A < 0)
    {
        ptf("Are you serious?\n");
        err = 1;
    }
    if (X < 2 || X > 100)
    {
        ptf("Wrong dice!\n");
        err = 1;
    }
    if (err)
    {
        return;
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m=>\033[93;46m%3d\033[90;46m>\033[0m ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
    }
    ptf("\n");
    ptf("result: ");
    for (int32_t i = 0; i < A - 1; i++)
    {
        ptf("%d + ", result[i]);
        final += result[i];
    }
    final += result[A - 1];
    ptf("%d = \033[96m%d\033[0m\n", result[A - 1], final);
    ptf("\n");
    return;
}

void AdXkY_add_B()
{
    int8_t err = 0;
    srand(time(NULL));
    final = 0;
    int32_t result[10] = {0};
    int32_t A = 0, X = 0, Y = 0, B = 0;
    ptf("Please enter A, X, Y, B: ");
    scf("%d %d %d %d", &A, &X, &Y, &B);
    if (A > 10)
    {
        ptf("Too many dice!\n");
        err = 1;
    }
    else if (A < 0)
    {
        ptf("Are you serious?\n");
        err = 1;
    }
    if (X < 2 || X > 100)
    {
        ptf("Wrong dice!\n");
        err = 1;
    }
    if (Y < 0 || Y > A)
    {
        ptf("Wrong choose!\n");
        err = 1;
    }
    if (B < -10 || B > 10)
    {
        ptf("Wrong bouns!\n");
        err = 1;
    }
    if (err)
    {
        return;
    }
    ptf("\n");
    for (int32_t i = 1; i <= A; i++)
    {
        ptf("v%3d   ", i);
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;102m>####>\033[0m ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;102m=>\033[93;102m%3d\033[90;102m>\033[0m ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;102m>####>\033[0m ");
    }
    ptf("\n");
    ptf("Please choose %d dice from above: ", Y);
    int32_t choose[10] = {0};
    for (int32_t i = 0; i < Y; i++)
    {
        scf("%d", &choose[i]);
        if (choose[i] > A || choose[i] < 1)
        {
            ptf("Wrong input, try again!\n");
            i--;
        }
    }
    for (int32_t i = 0; i < Y; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
    }
    ptf("\n");
    for (int32_t i = 0; i < Y; i++)
    {
        ptf("\033[90;46m=>\033[93;46m%3d\033[90;46m>\033[0m ", result[choose[i] - 1]);
    }
    ptf("\n");
    for (int32_t i = 0; i < Y; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
    }
    ptf("\n");
    ptf("result: ");
    for (int32_t i = 0; i < Y; i++)
    {
        if (B < 0 && i == Y - 1)
            ptf("%d - ", result[choose[i] - 1]);
        else
            ptf("%d + ", result[choose[i] - 1]);
        final += result[i];
    }
    final += B;
    ptf("%d = \033[96m%d\033[0m\n", abs(B), final);
    ptf("\n");
}

void AdXkhHklLkcC_add_B()
{
    int8_t err = 0;
    srand(time(NULL));
    final = 0;
    int32_t result[10] = {0};
    int32_t A = 0, X = 0, H = 0, L = 0, C = 0, B = 0;
    ptf("Please enter A, X, H, L, C, B: ");
    scf("%d %d %d %d %d %d", &A, &X, &H, &L, &C, &B);
    if (A > 10)
    {
        ptf("Too many dice!\n");
        err = 1;
    }
    else if (A < 0)
    {
        ptf("Are you serious?\n");
        err = 1;
    }
    if (X < 2 || X > 100)
    {
        ptf("Wrong dice!\n");
        err = 1;
    }
    if (H < 0 || H > A)
    {
        ptf("Wrong Highest!\n");
        err = 1;
    }
    if (L < 0 || L > A||(H<=A&&L+H>A))
    {
        ptf("Wrong Lowest!\n");
        err = 1;
    }
    if (C < 0 || C > A - H - L)
    {
        ptf("Wrong Choose!\n");
        err = 1;
    }
    if (B < -10 || B > 10)
    {
        ptf("Wrong bouns!\n");
        err = 1;
    }
    if (err)
    {
        return;
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
        result[i] = dice(X);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m=>\033[93;46m%3d\033[90;46m>\033[0m ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        ptf("\033[90;46m>####>\033[0m ");
    }
    ptf("\n");
    int32_t sort[10] = {0};

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
    ptf("\033[92mHighest\033[0m %d:\n", H);
    for (int32_t i = 0; i < H; i++)
    {
        ptf("\033[94;100m>####>\033[0m ");
    }
    ptf("\n");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("\033[94;100m=>\033[92;100m%3d\033[94;100m>\033[0m ", sort[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("\033[94;100m>####>\033[0m ");
    }
    ptf("\n");
    ptf("\033[91mLowest\033[0m %d:\n", L);
    for (int32_t i = 0; i < L; i++)
    {
        ptf("\033[94;100m>####>\033[0m ");
    }
    ptf("\n");
    for (int32_t i = 0; i < L; i++)
    {
        ptf("\033[94;100m=>\033[91;100m%3d\033[94;100m>\033[0m ", sort[A - 1 - i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < L; i++)
    {
        ptf("\033[94;100m>####>\033[0m ");
    }
    ptf("\n");
    ptf("Choose %d:\n", C);
    for (int32_t i = 0; i < H; i++)
    {
        for (int32_t j = 0; j < A; j++)
        {
            if (result[j] == sort[i])
            {
                result[j] = 0;
                break;
            }
        }
    }
    for (int32_t i = 0; i < L; i++)
    {
        for (int32_t j = 0; j < A; j++)
        {
            if (result[j] == sort[A - 1 - i])
            {
                result[j] = 0;
                break;
            }
        }
    }

    int32_t minus = 0;
    for (int32_t i = 1; i <= A; i++)
    {
        if (result[i - 1] == 0)
            minus++;
        else
            ptf("v%3d   ", i - minus);
    }
    ptf("\n");
    for (int32_t i = 0; i < A - H - L; i++)
    {
        ptf("\033[90;102m>####>\033[0m ");
    }
    ptf("\n");
    for (int32_t i = 0; i < A; i++)
    {
        if (result[i] == 0)
            continue;
        else
            ptf("\033[90;102m=>\033[93;102m%3d\033[90;102m>\033[0m ", result[i]);
    }
    ptf("\n");
    for (int32_t i = 0; i < A - H - L; i++)
    {
        ptf("\033[90;102m>####>\033[0m ");
    }
    ptf("\n");
    ptf("Please choose %d dice from above: ", C);
    int32_t choose[10] = {0};
    for (int32_t i = 0; i < C; i++)
    {
        scf("%d", &choose[i]);
        if (choose[i] > A - H - L || choose[i] < 1)
        {
            ptf("Wrong input, try again!\n");
            i--;
        }
    }
    int32_t choose_result[10] = {0};
    int32_t rm = 0;
    for (int32_t i = 0; i < A; i++)
    {
        if (result[i] == 0 && rm < H + L)
        {

            rm++;
            for (int32_t j = i; j < A - 1; j++)
            {
                result[j] = result[j + 1];
            }
            result[A - rm] = 0;
            i--;
        }
    }
    for (int32_t i = 0; i < C; i++)
    {
        choose_result[i] = result[choose[i] - 1];
    }
    ptf("\n");
    ptf("result: ");
    for (int32_t i = 0; i < H; i++)
    {
        ptf("%d + ", sort[i]);
        final += sort[i];
    }
    for (int32_t i = 0; i < L; i++)
    {
        ptf("%d + ", sort[A - 1 - i]);
        final += sort[A - 1 - i];
    }
    for (int32_t i = 0; i < C; i++)
    {
        if (B < 0 && i == C - 1)
            ptf("%d - ", choose_result[i]);
        else
            ptf("%d + ", choose_result[i]);
        final += choose_result[i];
    }
    ptf("%d = \033[96m%d\033[0m\n", abs(B), final);
    ptf("\n");
}