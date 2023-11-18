#include <stdio.h>
#include <stdint.h>

#define ptf printf

int32_t meld[14] = {0};

int main()
{
    ptf("Please input meld: ");
    int32_t inp = 0;
    int32_t inp_count = 0;
    while (inp_count < 14)
    {
        scanf("%d", inp);
        while (inp&&inp_count<14)
        {
            meld[inp_count] = inp;
            inp_count++;
            scanf("%d", inp);
        }
        ptf("Is open/closed group (1: open 0: closed): ");//
        ptf("Is open group(1: YES 0: NO): ");//
        ptf("Please input winning tile:")//

        scanf("%d")
    }

    return 0;
}