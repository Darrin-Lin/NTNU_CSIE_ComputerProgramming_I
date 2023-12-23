#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// board: game board. If the cell is a mine , the value is -2; otherwise , -1.
// row, col: implies hitting board[row][col].
// Note that the row and col should start from the top left corner and start from 0.
// Return -1 if the input is invalid and return 1 is hit the mine; otherwise return 0.

int32_t hit(int32_t board[16][30], int32_t row, int32_t col);

static int8_t check_board(int32_t board[16][30]);
static int8_t open_cell(int32_t board[16][30], int32_t row, int32_t col);

int32_t hit(int32_t board[16][30], int32_t row, int32_t col)
{
    {
        if (board == NULL)
        {
            return -1;
        }
        if (check_board(board) == -1)
        {
            return -1;
        }
        if (row < 0 || row >= 16 || col < 0 || col >= 30)
        {
            return -1;
        }
        if (board[row][col] == -2)
        {
            return 1;
        }
        else if (board[row][col] == -1)
        {
            open_cell(board, row, col);
            return 0;
        }
        return 0;
    }
}
static int8_t check_board(int32_t board[16][30])
{
    int32_t i, j;
    for (i = 0; i < 16; i++)
    {
        for (j = 0; j < 30; j++)
        {
            if (board[i][j] > 8 || board[i][j] < -2)
            {
                return -1;
            }
        }
    }
    return 0;
}

static int8_t open_cell(int32_t board[16][30], int32_t row, int32_t col)
{
    if (board[row][col] != -1)
    {
        return 0;
    }
    int32_t i, j;
    int32_t count = 0;
    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = col - 1; j <= col + 1; j++)
        {
            if (i < 0 || i >= 16 || j < 0 || j >= 30)
            {
                continue;
            }
            if (board[i][j] == -2)
            {
                count++;
            }
        }
    }
    board[row][col] = count;
    if (count == 0)
    {
        for (i = row - 1; i <= row + 1; i++)
        {
            for (j = col - 1; j <= col + 1; j++)
            {
                if (i < 0 || i >= 16 || j < 0 || j >= 30)
                {
                    continue;
                }
                open_cell(board, i, j);
            }
        }
    }
    return 0;
}