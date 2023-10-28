#include <stdint.h>

void setup_girl_weight(uint32_t);
void setup_boy_weight(uint32_t);
int64_t afford_weight(int32_t x, int32_t y);
static double count(int32_t, int32_t);

static uint32_t boy_weight = 0;
static uint32_t girl_weight = 0;
static int8_t set = 0;

void setup_girl_weight(uint32_t w)
{
    if (set == 1)
        set = 2;
    else
        set = 1;
    girl_weight = w;
}
void setup_boy_weight(uint32_t w)
{
    if (set == 1)
        set = 2;
    else
        set = 1;
    boy_weight = w;
}

int64_t afford_weight(int32_t x, int32_t y) //===>y  ^x
{
    if(set!=2)
        return -1;
    if (x < 0 && y < 0)
    {
        return 0;
    }
    if (x == 0 && y == 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return (int64_t)(girl_weight / 2) + 1e-9;
    }
    if (y < 0 || y > x)
    {
        return 0;
    }
    return (int64_t)(count(x, y) + 1e-9);
}
static double count(int32_t x, int32_t y)
{
    if (x == 0 && y == 0)
    {
        return 0;
    }
    if (y < 0 || y > x)
    {
        return 0;
    }
    if (x == 1)
    {
        return (girl_weight / 2);
    }
    
    if (x % 2)
    {
        if (y == 0 || y == x)
        {
            return (girl_weight / 2 + count(x - 1, y - 1)/2 + count(x - 1, y)/2);
        }
        else
        {
            return (girl_weight + count(x - 1, y - 1)/2 + count(x - 1, y)/2);
        }
    }
    else
    {
        if (y == 0 || y == x)
        {
            return (boy_weight / 2 + count(x - 1, y - 1)/2 + count(x - 1, y)/2);
        }
        else
        {
            return (boy_weight + count(x - 1, y - 1)/2 + count(x - 1, y)/2);
        }
    }
}