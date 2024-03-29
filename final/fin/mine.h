#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#pragma once

// board: game board. If the cell is a mine , the value is -2; otherwise , -1.
// row, col: implies hitting board[row][col].
// Note that the row and col should start from the top left corner and start from 0.
// Return -1 if the input is invalid and return 1 is hit the mine; otherwise return 0.

int32_t hit( int32_t board[16][30], int32_t row, int32_t col );