#include <stdio.h>
#include <stdint.h>

#define ptf printf
// Pin: 1~9
// So: 11~18
// Wan: 21~27
// wind ( 東南西北 ): 28~31
// 白發中: 31~34

static int32_t melds[27] = {0};
static int32_t meld_list[14] = {0};
static int32_t winning_tile = 0, self_drawn_win = 0, plqyer_wind = 0, prevailing_wind = 0;
static int32_t han = 0, yakuman = 0;
static int32_t yaku_flag[33] = {0};

static void count_yaku();

int main()
{
    ptf("Please input meld: ");
    int32_t inp = 0;
    int32_t inp_count = 0, meld_count = 0;
    int32_t cards_count[34] = {0};
    int32_t full_card = 1;
    while (inp_count < 14)
    {
        scanf("%d", &inp);

        while (inp && inp_count < 14)
        {

            if (inp < 0 || inp > 34)
            {
                goto unresonable_case;
            }
            cards_count[inp - 1]++;
            if (cards_count[inp - 1] > 4)
            {
                goto unresonable_case;
            }
            melds[meld_count] = inp;
            meld_list[inp_count] = inp;
            inp_count++;
            meld_count++;
            scanf("%d", &inp);
        }
        if (inp == 0)
        {
            full_card = 0;
            melds[meld_count] = 0;
            meld_count++;
        }
        if (!full_card)
        {
            ptf("Is open group(1: YES 0: NO): ");
        }
    }
    ptf("Please input winning tile:"); //
    scanf("%d", &winning_tile);
    ptf("Is Self-drawn win?(1: YES 0: NO): "); //
    scanf("%d", &self_drawn_win);
    if (self_drawn_win > 1 || self_drawn_win < 0)
    {
        goto unresonable_case;
    }
    ptf("Player's wind(0:E 1:S 2:W 3:N): "); //
    scanf("%d", &plqyer_wind);
    if (plqyer_wind > 3 || plqyer_wind < 0)
    {
        goto unresonable_case;
    }
    ptf("Prevailing wind(0:E 1:S 2:W 3:N): "); //
    scanf("%d", &prevailing_wind);
    if (prevailing_wind > 3 || prevailing_wind < 0)
    {
        goto unresonable_case;
    }
    // 二盃口比七對子優先
    count_yaku();
    // unresonable case
    ptf("The Score is...\n");

    ptf("Toltal: ");
    ptf("%d Han\n", han);
    ptf("%d Yakuman\n", yakuman);
    if (0)
    {
    unresonable_case:
        ptf("The Score is... Unreasonable case Total: 0 Han\n");
        return 1;
    }

    return 0;
}
static void count_yaku()
{
}