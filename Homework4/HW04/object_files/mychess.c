#include <stdint.h>
#include <stdio.h>

#define EMPTY (0)
#define RED_GENERAL (1)
#define RED_ADVISOR (2)
#define RED_ELEPHANT (3)
#define RED_HORSE (4)
#define RED_CHARIOT (5)
#define RED_CANNON (6)
#define RED_SOLDIER (7)
#define BLACK_GENERAL (11)
#define BLACK_ADVISOR (12)
#define BLACK_ELEPHANT (13)
#define BLACK_HORSE (14)
#define BLACK_CHARIOT (15)
#define BLACK_CANNON (16)
#define BLACK_SOLDIER (17)

// Return -1 if the board is invalid;
// otherwise , print all red side possible move to checkmate the black general and return the possible move number.
// Note the print should follow the piece order.
int32_t checkmate(int32_t board[10][9]);
static int32_t check_board(int32_t board[10][9]);

static int32_t red_chess[7] = {0};
static int32_t black_chess[7] = {0};

int32_t checkmate(int32_t board[10][9])
{
    if (check_board(board))
    {
        return -1;
    }
}

static int32_t check_board(int32_t board[10][9])
{
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] != EMPTY)
            {
                if (board[i][j] < 10)
                {
                    red_chess[board[i][j] - 1]++;
                    if (board[i][j] == RED_GENERAL)
                    {
                        if (!(i == 0 || i == 1 || i == 2))
                        {
                            return -1;
                        }
                        else if (!(j == 3 || j == 4 || j == 5))
                        {
                            return -1;
                        }
                    }
                    if (board[i][j] == RED_ADVISOR)
                    {
                        if (!(((i == 0 || i == 2) && (j == 3 || j == 5)) || ((i == 1) && (j == 4))))
                        {

                            return -1;
                        }
                    }
                    if (board[i][j] == RED_ELEPHANT)
                    {
                        if (!(((i == 0 || i == 4) && (j == 2 || j == 6)) || ((i == 2) && (j == 0 || j == 4 || j == 8))))
                        {
                            return -1;
                        }
                    }
                    if(board[i][j]==RED_SOLDIER)
                    {
                        if((i<=4&&i%2)||i<3)
                        {
                            return -1;
                        }
                    }
                }
                else
                {
                    black_chess[board[i][j] - 11]++;
                    if (board[i][j] == BLACK_GENERAL)
                    {
                        if (!(i == 7 || i == 8 || i == 9))
                        {
                            return -1;
                        }
                        else if (!(j == 3 || j == 4 || j == 5))
                        {
                            return -1;
                        }
                    }
                    if (board[i][j] == BLACK_ADVISOR)
                    {
                        if (!(((i == 7 || i == 9) && (j == 3 || j == 5)) || ((i == 8) && (j == 4))))
                        {
                            return -1;
                        }
                    }
                    if (board[i][j] == BLACK_ELEPHANT)
                    {
                        if (!(((i == 5 || i == 9) && (j == 2 || j == 6)) || ((i == 7) && (j == 0 || j == 4 || j == 8))))
                        {
                            return -1;
                        }
                    }
                    if(board[i][j]==BLACK_SOLDIER)
                    {
                        if((i>=5&&i%2)||i>6)
                        {
                            return -1;
                        }
                    }   
                }
            }
        }
        // check number of chess
        {
            if (red_chess[0] != 1 || black_chess[0] != 1)
            {
                return -1;
            }
            if (red_chess[1] > 2 || black_chess[1] > 2)
            {
                return -1;
            }
            if (red_chess[2] > 2 || black_chess[2] > 2)
            {
                return -1;
            }
            if (red_chess[3] > 2 || black_chess[3] > 2)
            {
                return -1;
            }
            if (red_chess[4] > 2 || black_chess[4] > 2)
            {
                return -1;
            }
            if (red_chess[5] > 2 || black_chess[5] > 2)
            {
                return -1;
            }
            if (red_chess[6] > 5 || black_chess[6] > 5)
            {
                return -1;
            }
        }
    }
    return 0;
}