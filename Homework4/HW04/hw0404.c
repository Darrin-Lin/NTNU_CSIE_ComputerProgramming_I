// #include <stdio.h>
// #include <stdint.h>
// #include "mychess.h"

// int main()
// {
//     int32_t board[10][9] = {
//     {0, 0, 0, 1, 0, 0, 0, 0, 0},
//     {0, 0, 15, 0, 17, 0, 0, 15, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 17, 0, 17, 4, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 0, 0, 0, 0, 0},
//     {0, 0, 0, 0, 11, 0, 7, 0, 14},
//     {0, 0, 0, 0, 0, 0, 0, 5, 0},
//     {0, 0, 0, 12, 0, 12, 0, 0, 0}
//     };
//     checkmate(board);
//     return 0;
// }
#include <stdio.h>
#include <stdint.h>
#include "mychess.h"
int main()
{
    int32_t board[10][9] = {{EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                            {EMPTY, EMPTY, BLACK_CHARIOT, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY, BLACK_CHARIOT, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, BLACK_SOLDIER, RED_HORSE, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, RED_SOLDIER, EMPTY, BLACK_HORSE},
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT, EMPTY},
                            {EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY}};
    int32_t board2[10][9] = {{EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY},
                             {RED_CHARIOT, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY},
                             {EMPTY, BLACK_CHARIOT, EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, BLACK_ELEPHANT, EMPTY, EMPTY}};
    int32_t board3[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_HORSE, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, BLACK_CANNON, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_SOLDIER, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT}};
    int32_t board4[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {RED_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY},
                             {EMPTY, EMPTY, BLACK_CHARIOT, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY}};
    int32_t board5[10][9] = {{EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {RED_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, EMPTY, RED_SOLDIER, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY},
                             {EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                             {EMPTY, RED_CHARIOT, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ELEPHANT, EMPTY, EMPTY}};
    printf("Test Case #1: \n");
    printf("%d", checkmate(board));
    printf("=====================\n");
    printf("Test Case #2: \n");
    printf("%d", checkmate(board2));
    printf("=====================\n");
    printf("Test Case #3: \n");
    printf("%d", checkmate(board3));
    printf("=====================\n");
    printf("Test Case #4: \n");
    printf("%d", checkmate(board4));
    printf("=====================\n");
    printf("Test Case #5: \n");
    printf("%d", checkmate(board5));
    printf("=====================\n");

    return 0;
}