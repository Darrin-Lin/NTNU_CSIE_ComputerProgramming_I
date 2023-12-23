#include <stdio.h>
#include <stdint.h>
#include "mine.h"
int main()
{
    int32_t board[16][30] = {0};
    int32_t row, col;
    int32_t i, j;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 30; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    scanf("%d%d", &row, &col);
    hit(board, row, col);
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 30; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}