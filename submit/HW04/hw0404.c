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
#include <string.h>
#include "mychess.h"
int main(int argc, char *argv[]){
    int32_t board[10][9] = {{EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, BLACK_CHARIOT, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY, BLACK_CHARIOT, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, BLACK_SOLDIER, RED_HORSE, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, RED_SOLDIER, EMPTY, BLACK_HORSE}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY} \
    };
    int32_t board2[10][9] = {{EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {RED_CHARIOT, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, BLACK_ELEPHANT, EMPTY, EMPTY}  \
    };
    int32_t board3[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, RED_HORSE, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_CANNON, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT}  \
    };
    int32_t board4[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, RED_HORSE, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_CANNON, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT}  \
    };
    int32_t board5[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CHARIOT}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {RED_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_SOLDIER, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, BLACK_CHARIOT, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY}  \
    };
    int32_t board6[10][9] = {{EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {RED_HORSE, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_SOLDIER, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, RED_CHARIOT, EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ELEPHANT, EMPTY, EMPTY}  \
    };
    int32_t board7[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_CHARIOT, RED_CANNON, RED_CANNON, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ELEPHANT, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}  \
    };
    int32_t board8[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_CHARIOT, RED_CHARIOT, RED_CANNON, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, BLACK_CANNON, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}  \
    };
    int32_t board9[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, RED_ADVISOR, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {RED_SOLDIER, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_CHARIOT, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}  \
    };
    int32_t board10[10][9] = {{EMPTY, EMPTY, EMPTY, EMPTY, RED_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {RED_SOLDIER, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, BLACK_ELEPHANT, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, RED_CANNON, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_CHARIOT, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_ADVISOR, EMPTY, EMPTY, EMPTY, EMPTY}, \
                            {EMPTY, EMPTY, EMPTY, EMPTY, BLACK_GENERAL, EMPTY, EMPTY, EMPTY, EMPTY}  \
    };
    printf("\nYour return value is %d \n", checkmate(board));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board2));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board3));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board4));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board5));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board6));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board7));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board8));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board9));
    printf("=====================\n");
    printf("\nYour return value is %d \n", checkmate(board10));
    printf("=====================\n");
    
    
    return 0;
}