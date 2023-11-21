#include <stdio.h>
#include <stdint.h>

#define ptf printf

int32_t meld[14] = {0};

int main()
{
    ptf("Please input meld: ");
    int32_t inp = 0;
    int32_t inp_count = 0;
    int32_t cards_count[34] = {0};
    int32_t winning_tile = 0, self_drawn_win = 0, plqyer_wind = 0, prevailing_wind = 0;
    while (inp_count < 14)
    {
        scanf("%d", &inp);
        while (inp && inp_count < 14)
        {
            meld[inp_count] = inp;
            if (inp < 0 || inp > 34)
            {
                goto unresonable_case;
            }
            cards_count[inp-1]++;
            if(cards_count[inp-1] > 4)
            {
                goto unresonable_case;
            }
            inp_count++;
            scanf("%d", &inp);
        }
        ptf("Is open group(1: YES 0: NO): "); //
    }
    ptf("Please input winning tile:"); //
    scanf("%d", &winning_tile);
    ptf("Is Self-drawn win?(1: YES 0: NO): "); //
    scanf("%d", &self_drawn_win);
    if(self_drawn_win>1 || self_drawn_win<0)
    {
        goto unresonable_case;
    }
    ptf("Player's wind(0:E 1:S 2:W 3:N): "); //
    scanf("%d", &plqyer_wind);
    if (plqyer_wind>3 || plqyer_wind<0)
    {
        goto unresonable_case;
    }
    ptf("Prevailing wind(0:E 1:S 2:W 3:N): "); //
    scanf("%d", &prevailing_wind);
    if (prevailing_wind>3 || prevailing_wind<0)
    {
        goto unresonable_case;
    }

    // unresonable case
    if (0)
    {
    unresonable_case:
        ptf("The Score is... Unreasonable case Total: 0 Han\n");
        return 0;
    }
    return 0;
}