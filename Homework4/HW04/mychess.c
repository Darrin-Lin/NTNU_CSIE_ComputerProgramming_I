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
static void move_general(int32_t board[10][9], int32_t y, int32_t x);
static void move_horse(int32_t board[10][9], int32_t y, int32_t x);
static void move_chariot(int32_t board[10][9], int32_t y, int32_t x);
static void move_cannon(int32_t board[10][9], int32_t y, int32_t x);
static void move_soldier(int32_t board[10][9], int32_t y, int32_t x);
static void horse_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y);
static void chariot_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y, int32_t general_x, int32_t general_y);
static void cannon_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y, int32_t general_x, int32_t general_y);
static void soldier_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y);

static uint64_t num_print = 0;

int32_t checkmate(int32_t board[10][9])
{
    num_print = 0;
    if (board == NULL)
    {
        return -1;
    }
    if (check_board(board) == -1)
    {
        return -1;
    }
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == RED_GENERAL)
            {
                move_general(board, i, j);
                break;
            }
        }
    }
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == RED_HORSE)
            {
                move_horse(board, i, j);
            }
        }
    }
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == RED_CHARIOT)
            {
                move_chariot(board, i, j);
            }
        }
    }
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == RED_CANNON)
            {
                move_cannon(board, i, j);
            }
        }
    }
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == RED_SOLDIER)
            {
                move_soldier(board, i, j);
            }
        }
    }
    return 0;
}

static int32_t check_board(int32_t board[10][9])
{
    if (board == NULL)
    {
        return -1;
    }
    int32_t red_chess[7] = {0};
    int32_t black_chess[7] = {0};
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            // fprintf(stderr, "%2d ", board[i][j]);
            if (board[i][j] != EMPTY)
            {
                if (board[i][j] < 10)
                {
                    red_chess[board[i][j] - 1]++;
                    if (board[i][j] == RED_GENERAL)
                    {
                        if (!(i == 0 || i == 1 || i == 2))
                        {
                            // fprintf(stderr, "RG\n");
                            return -1;
                        }
                        else if (!(j == 3 || j == 4 || j == 5))
                        {
                            // fprintf(stderr, "RG\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == RED_ADVISOR)
                    {
                        if (!(((i == 0 || i == 2) && (j == 3 || j == 5)) || ((i == 1) && (j == 4))))
                        {
                            // fprintf(stderr, "RA\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == RED_ELEPHANT)
                    {
                        if (!(((i == 0 || i == 4) && (j == 2 || j == 6)) || ((i == 2) && (j == 0 || j == 4 || j == 8))))
                        {
                            // fprintf(stderr, "RE\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == RED_SOLDIER)
                    {
                        if ((i >= 3 && j % 2) || i < 3)
                        {
                            // fprintf(stderr, "RS\n");
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
                            // fprintf(stderr, "BG\n");
                            return -1;
                        }
                        else if (!(j == 3 || j == 4 || j == 5))
                        {
                            // fprintf(stderr, "BG\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == BLACK_ADVISOR)
                    {
                        if (!(((i == 7 || i == 9) && (j == 3 || j == 5)) || ((i == 8) && (j == 4))))
                        {
                            // fprintf(stderr, "BA\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == BLACK_ELEPHANT)
                    {
                        if (!(((i == 5 || i == 9) && (j == 2 || j == 6)) || ((i == 7) && (j == 0 || j == 4 || j == 8))))
                        {
                            // fprintf(stderr, "BE\n");
                            return -1;
                        }
                    }
                    if (board[i][j] == BLACK_SOLDIER)
                    {
                        if ((i <= 6 && j % 2) || i > 6)
                        {
                            // fprintf(stderr, "BS\n");
                            return -1;
                        }
                    }
                }
            }
        }
        // fprintf(stderr, "\n");
    }
    // check number of chess
    {
        if (red_chess[0] != 1 || black_chess[0] != 1)
        {
            // fprintf(stderr, "RG||BG\n");
            return -1;
        }
        if (red_chess[1] > 2 || black_chess[1] > 2)
        {
            // fprintf(stderr, "RA||BA\n");
            return -1;
        }
        if (red_chess[2] > 2 || black_chess[2] > 2)
        {
            // fprintf(stderr, "RE||BE\n");
            return -1;
        }
        if (red_chess[3] > 2 || black_chess[3] > 2)
        {
            // fprintf(stderr, "RH||BH\n");
            return -1;
        }
        if (red_chess[4] > 2 || black_chess[4] > 2)
        {
            // fprintf(stderr, "RC||BC\n");
            return -1;
        }
        if (red_chess[5] > 2 || black_chess[5] > 2)
        {
            // fprintf(stderr, "RCa||BCa\n");
            return -1;
        }
        if (red_chess[6] > 5 || black_chess[6] > 5)
        {
            // fprintf(stderr, "RS||BS\n");
            return -1;
        }
    }

    return 0;
}

static void move_general(int32_t board[10][9], int32_t y, int32_t x)
{
    if (board == NULL)
    {
        return;
    }
    int32_t next_x = 0, next_y = 0;

    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == BLACK_GENERAL)
            {
                if ((x == 3 || x == 4) && (board[y][x + 1] / 10 || board[y][x + 1] == EMPTY))
                {
                    next_x = x + 1;
                    if (j == next_x)
                    {
                        int32_t flag = 0;
                        for (int32_t k = next_y + 1; k < i; k++)
                        {
                            if (board[k][j] != EMPTY)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            num_print++;
                            printf("%lu) Move General from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
                        }
                    }
                }
                if ((x == 4 || x == 5) && (board[y][x - 1] / 10 || board[y][x - 1] == EMPTY))
                {
                    next_x = x - 1;
                    if (j == next_x)
                    {
                        int32_t flag = 0;
                        for (int32_t k = next_y + 1; k < i; k++)
                        {
                            if (board[k][j] != EMPTY)
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            num_print++;
                            printf("%lu) Move General from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
                        }
                    }
                }
            }
        }
    }
    return;
}

static void horse_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y)
{
    if (board == NULL)
    {
        return;
    }
    if (next_x - 1 >= 0 && next_y - 2 >= 0 && board[next_y - 2][next_x - 1] == BLACK_GENERAL && board[next_y - 1][next_x] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x + 1 < 9 && next_y - 2 >= 0 && board[next_y - 2][next_x + 1] == BLACK_GENERAL && board[next_y - 1][next_x] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x - 2 >= 0 && next_y - 1 >= 0 && board[next_y - 1][next_x - 2] == BLACK_GENERAL && board[next_y][next_x - 1] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x + 2 < 9 && next_y - 1 >= 0 && board[next_y - 1][next_x + 2] == BLACK_GENERAL && board[next_y][next_x + 1] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x - 2 >= 0 && next_y + 1 < 10 && board[next_y + 1][next_x - 2] == BLACK_GENERAL && board[next_y][next_x - 1] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x + 2 < 9 && next_y + 1 < 10 && board[next_y + 1][next_x + 2] == BLACK_GENERAL && board[next_y][next_x + 1] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x - 1 >= 0 && next_y + 2 < 10 && board[next_y + 2][next_x - 1] == BLACK_GENERAL && board[next_y + 1][next_x] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x + 1 < 9 && next_y + 2 < 10 && board[next_y + 2][next_x + 1] == BLACK_GENERAL && board[next_y + 1][next_x] == EMPTY)
    {
        num_print++;
        printf("%lu) Move Horse from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }

    return;
}
static void move_horse(int32_t board[10][9], int32_t y, int32_t x)
{
    if (board == NULL)
    {
        return;
    }
    int32_t next_x = 0, next_y = 0;
    if (x - 1 >= 0 && y - 2 >= 0 && (board[y - 2][x - 1] / 10 == 1 || board[y - 2][x - 1] == EMPTY) && board[y - 1][x] == EMPTY)
    {
        next_x = x - 1;
        next_y = y - 2;
        // fprintf(stderr, "a");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x + 1 < 9 && y - 2 >= 0 && (board[y - 2][x + 1] / 10 == 1 || board[y - 2][x + 1] == EMPTY) && board[y - 1][x] == EMPTY)
    {
        next_x = x + 1;
        next_y = y - 2;
        // fprintf(stderr, "b");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x - 2 >= 0 && y - 1 >= 0 && (board[y - 1][x - 2] / 10 == 1 || board[y - 1][x - 2] == EMPTY) && board[y][x - 1] == EMPTY)
    {
        next_x = x - 2;
        next_y = y - 1;
        // fprintf(stderr, "c");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x + 2 < 9 && y - 1 >= 0 && (board[y - 1][x + 2] / 10 == 1 || board[y - 1][x + 2] == EMPTY) && board[y][x + 1] == EMPTY)
    {
        next_x = x + 2;
        next_y = y - 1;
        // fprintf(stderr, "d");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x - 2 >= 0 && y + 1 < 10 && (board[y + 1][x - 2] / 10 == 1 || board[y + 1][x - 2] == EMPTY) && board[y][x - 1] == EMPTY)
    {
        next_x = x - 2;
        next_y = y + 1;
        // fprintf(stderr, "e");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x + 2 < 9 && y + 1 < 10 && (board[y + 1][x + 2] / 10 == 1 || board[y + 1][x + 2] == EMPTY) && board[y][x + 1] == EMPTY)
    {
        next_x = x + 2;
        next_y = y + 1;
        // fprintf(stderr, "f");
        horse_checkmate(board, next_x, next_y, x, y);
    }
    if (x - 1 >= 0 && y + 2 < 10 && (board[y + 2][x - 1] / 10 == 1 || board[y + 2][x - 1] == EMPTY) && board[y + 1][x] == EMPTY)
    {
        next_x = x - 1;
        next_y = y + 2;
        // fprintf(stderr, "g");
        horse_checkmate(board, next_x, next_y, x, y);
    }

    if (x + 1 < 9 && y + 2 < 10 && (board[y + 2][x + 1] / 10 == 1 || board[y + 2][x + 1] == EMPTY) && board[y + 1][x] == EMPTY)
    {
        next_x = x + 1;
        next_y = y + 2;
        // fprintf(stderr, "h");
        horse_checkmate(board, next_x, next_y, x, y);
    }

    return;
}

static void chariot_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y, int32_t general_x, int32_t general_y)
{
    if (board == NULL)
    {
        return;
    }
    if (next_x == general_x)
    {
        int32_t flag = 0;
        if (general_y > y)
        {
            for (int32_t k = next_y + 1; k < general_y; k++)
            {
                if (board[k][general_x] != EMPTY)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                num_print++;
                printf("%lu) Move Chariot from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
        else
        {
            for (int32_t k = next_y - 1; k > general_y; k--)
            {
                if (board[k][general_x] != EMPTY)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                num_print++;
                printf("%lu) Move Chariot from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
    }
    else if (next_y == general_y)
    {
        int32_t flag = 0;
        if (general_x > x)
        {
            for (int32_t k = next_x + 1; k < general_x; k++)
            {
                if (board[general_y][k] != EMPTY)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                num_print++;
                printf("%lu) Move Chariot from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
        else
        {
            for (int32_t k = next_x - 1; k > general_x; k--)
            {
                if (board[general_y][k] != EMPTY)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                num_print++;
                printf("%lu) Move Chariot from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
    }
    return;
}
static void move_chariot(int32_t board[10][9], int32_t y, int32_t x)
{
    if (board == NULL)
    {
        return;
    }
    int32_t next_x = 0, next_y = 0;
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == BLACK_GENERAL)
            {
                if (i == y)
                {
                    if (j > x)
                    {
                        for (int32_t k = x + 1; k < j; k++)
                        {
                            if (board[y][k] / 10 == 0)
                            {
                                break;
                            }
                            else if (board[y][k] / 10)
                            {
                                next_x = k;
                                next_y = y;
                                chariot_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                            // else
                            // {
                            //     next_x = k;
                            //     next_y = y;
                            //     chariot_checkmate(board, next_x, next_y, x, y, j, i);
                            // }
                        }
                    }
                    else
                    {
                        for (int32_t k = x - 1; k > j; k--)
                        {
                            if (board[y][k] / 10 == 0)
                            {
                                break;
                            }
                            else if (board[y][k] / 10)
                            {
                                next_x = k;
                                next_y = y;
                                chariot_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                            // else
                            // {
                            //     next_x = k;
                            //     next_y = y;
                            //     chariot_checkmate(board, next_x, next_y, x, y, j, i);
                            // }
                        }
                    }
                }
                else if (j == x)
                {
                    if (i > y)
                    {
                        for (int32_t k = y + 1; k < i; k++)
                        {
                            if (board[k][x] / 10 == 0)
                            {
                                break;
                            }
                            else if (board[k][x] / 10)
                            {
                                next_x = x;
                                next_y = k;
                                chariot_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                            // else
                            // {
                            //     next_x = x;
                            //     next_y = k;
                            //     chariot_checkmate(board, next_x, next_y, x, y, j, i);
                            // }
                        }
                    }
                    else
                    {
                        for (int32_t k = y - 1; k > i; k--)
                        {
                            if (board[k][x] / 10 == 0)
                            {
                                break;
                            }
                            else if (board[k][x] / 10)
                            {
                                next_x = x;
                                next_y = k;
                                chariot_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                            // else
                            // {
                            //     next_x = x;
                            //     next_y = k;
                            //     chariot_checkmate(board, next_x, next_y, x, y, j, i);
                            // }
                        }
                    }
                }
                else
                {
                    int32_t flag = 0;
                    for (int32_t k = x + 1; k < j; k++)
                    {
                        if (board[y][k] != EMPTY)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0 && (board[y][j] / 10 || board[y][j] == EMPTY))
                    {
                        next_x = j;
                        next_y = y;
                        chariot_checkmate(board, next_x, next_y, x, y, j, i);
                    }
                    flag = 0;
                    for (int32_t k = y + 1; k < i; k++)
                    {
                        if (board[k][x] != EMPTY)
                        {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0 && (board[i][x] / 10 || board[i][x] == EMPTY))
                    {
                        next_x = x;
                        next_y = i;
                        chariot_checkmate(board, next_x, next_y, x, y, j, i);
                    }
                }
            }
        }
    }
    return;
}

static void cannon_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y, int32_t general_x, int32_t general_y)
{
    if (board == NULL)
    {
        return;
    }
    if (next_x == general_x)
    {
        int32_t flag = 0;
        if (general_y > y)
        {
            for (int32_t k = next_y + 1; k < general_y; k++)
            {
                if (board[k][general_x] != EMPTY)
                {
                    flag++;
                }
            }
            if (flag == 1)
            {
                num_print++;
                printf("%lu) Move Cannon from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
        else
        {
            for (int32_t k = next_y - 1; k > general_y; k--)
            {
                if (board[k][general_x] != EMPTY)
                {
                    flag++;
                }
            }
            if (flag == 1)
            {
                num_print++;
                printf("%lu) Move Cannon from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
    }
    else if (next_y == general_y)
    {
        int32_t flag = 0;
        if (general_x > x)
        {
            for (int32_t k = next_x + 1; k < general_x; k++)
            {
                if (board[general_y][k] != EMPTY)
                {
                    flag++;
                }
            }
            if (flag == 1)
            {
                num_print++;
                printf("%lu) Move Cannon from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
        else
        {
            for (int32_t k = next_x - 1; k > general_x; k--)
            {
                if (board[general_y][k] != EMPTY)
                {
                    flag++;
                }
            }
            if (flag == 1)
            {
                num_print++;
                printf("%lu) Move Cannon from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
            }
        }
    }
    return;
}
static void move_cannon(int32_t board[10][9], int32_t y, int32_t x)
{

    if (board == NULL)
    {
        return;
    }
    int32_t next_x = 0, next_y = 0;
    int32_t flag = 0;
    for (int32_t i = 0; i < 10; i++)
    {
        for (int32_t j = 0; j < 9; j++)
        {
            if (board[i][j] == BLACK_GENERAL)
            {
                if (i == y)
                {
                    if (j > x)
                    {
                        flag = 0;
                        for (int32_t k = x + 1; k < j; k++)
                        {
                            if (board[y][k] != EMPTY)
                            {
                                flag++;
                            }
                            if (flag == 2)
                            {
                                next_x = k;
                                next_y = y;
                                cannon_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                    else
                    {
                        flag = 0;
                        for (int32_t k = x - 1; k > j; k--)
                        {
                            if (board[y][k] != EMPTY)
                            {
                                flag++;
                            }
                            if (flag == 2)
                            {
                                next_x = k;
                                next_y = y;
                                cannon_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                }
                else if (j == x)
                {
                    if (i > y)
                    {
                        flag = 0;
                        for (int32_t k = y + 1; k < i; k++)
                        {
                            if (board[k][x] != EMPTY)
                            {
                                flag++;
                            }
                            if (flag == 2)
                            {
                                next_x = x;
                                next_y = k;
                                cannon_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                    else
                    {
                        flag = 0;
                        for (int32_t k = y - 1; k > i; k--)
                        {
                            if (board[k][x] != EMPTY)
                            {
                                flag++;
                            }
                            if (flag == 2)
                            {
                                next_x = x;
                                next_y = k;
                                cannon_checkmate(board, next_x, next_y, x, y, j, i);
                                break;
                            }
                        }
                        if (flag == 0)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                }
                else
                {
                    flag = 0;
                    if (j > x)
                    {
                        for (int32_t k = x + 1; k < j; k++)
                        {
                            if (board[y][k] != EMPTY)
                            {
                                flag++;
                            }
                        }
                        if (flag == 1 && (board[y][j] / 10))
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                        if (flag == 0)
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                    else
                    {
                        for (int32_t k = x - 1; k > j; k--)
                        {
                            if (board[y][k] != EMPTY)
                            {
                                flag++;
                            }
                        }
                        if (flag == 1 && (board[y][j] / 10))
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                        if (flag == 0)
                        {
                            next_x = j;
                            next_y = y;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                    flag = 0;
                    if (i > y)
                    {
                        for (int32_t k = y + 1; k < i; k++)
                        {
                            if (board[k][x] != EMPTY)
                            {
                                flag++;
                            }
                        }
                        if (flag == 1 && board[i][x] / 10)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                        if (flag == 0)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                    else
                    {
                        for (int32_t k = y - 1; k > i; k--)
                        {
                            if (board[k][x] != EMPTY)
                            {
                                flag++;
                            }
                        }
                        if (flag == 1 && board[i][x] / 10)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                        if (flag == 0)
                        {
                            next_x = x;
                            next_y = i;
                            cannon_checkmate(board, next_x, next_y, x, y, j, i);
                        }
                    }
                }
            }
        }
    }
    return;
}

static void soldier_checkmate(int32_t board[10][9], int32_t next_x, int32_t next_y, int32_t x, int32_t y)
{
    if (board == NULL)
    {
        return;
    }
    if (next_x - 1 >= 0 && board[next_y][next_x - 1] == BLACK_GENERAL)
    {
        num_print++;
        printf("%lu) Move Soldier from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_x + 1 < 9 && board[next_y][next_x + 1] == BLACK_GENERAL)
    {
        num_print++;
        printf("%lu) Move Soldier from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    else if (next_y + 1 < 10 && board[next_y + 1][next_x] == BLACK_GENERAL)
    {
        num_print++;
        printf("%lu) Move Soldier from (%d,%d) to (%d,%d)\n", num_print, y, x, next_y, next_x);
    }
    return;
}
static void move_soldier(int32_t board[10][9], int32_t y, int32_t x)
{
    if (board == NULL)
    {
        return;
    }
    if (y < 5)
        return;
    if (y >= 7 && (x == 0 || x == 8))
        return;
    if (y == 6 && (x <= 1 || x >= 7))
        return;
    if (y == 5 && (x <= 2 || x >= 6))
        return;
    int32_t next_x = 0, next_y = 0;
    if (x - 1 >= 0 && (board[y][x - 1] / 10 || board[y][x - 1] == EMPTY))
    {
        next_x = x - 1;
        next_y = y;
        soldier_checkmate(board, next_x, next_y, x, y);
    }
    if (x + 1 < 9 && (board[y][x + 1] / 10 || board[y][x + 1] == EMPTY))
    {
        next_x = x + 1;
        next_y = y;
        soldier_checkmate(board, next_x, next_y, x, y);
    }
    if (y + 1 < 10 && (board[y + 1][x] / 10 || board[y + 1][x] == EMPTY))
    {
        next_x = x;
        next_y = y + 1;
        soldier_checkmate(board, next_x, next_y, x, y);
    }
    return;
}