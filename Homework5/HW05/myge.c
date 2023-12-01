#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int32_t gaussian_elimination(int32_t n, int32_t *pA, int32_t *py, int32_t **px);

int32_t gaussian_elimination(int32_t n, int32_t *pA, int32_t *py, int32_t **px)
{
    if (pA == NULL || py == NULL || px == NULL)
    {
        return -1;
    }
    if (n <= 0)
    {
        return -1;
    }
    int32_t A[n][n];
    int32_t y[n];
    for (int32_t i = 0; i < n; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            A[i][j] = 0;
        }
        y[i] = 0;
    }
    int32_t *ptr_x = NULL; // return px=ptr_x
    ptr_x = (int32_t *)calloc(n, sizeof(int32_t));
    *(px) = ptr_x;
    for (int32_t i = 0; i < n; i++)
    {
        y[i] = *(py + i);
        for (int32_t j = 0; j < n; j++)
        {
            A[i][j] = *(pA + i * n + j);
        }
    }
    // uint32_t not_one_solution = 0;
    // reduce echelon form
    for (int32_t i = 0; i < n; i++)
    {
        if (A[i][i] == 0)
        {
            for (int32_t j = i + 1; j < n; j++)
            {
                if (A[j][i] != 0)
                {
                    for (int32_t k = 0; k < n; k++)
                    {
                        int32_t temp = A[i][k];
                        A[i][k] = A[j][k];
                        A[j][k] = temp;
                    }
                    int32_t temp = y[i];
                    y[i] = y[j];
                    y[j] = temp;
                    break;
                }
                // if (j == n - 1 && A[j][i] == 0)
                // {
                //     not_one_solution = (uint32_t)not_one_solution + 1;
                // }
            }
        }
        else
        {
            for (int32_t j = i + 1; j < n; j++)
            {
                double temp = A[j][i] / A[i][i];
                for (int32_t k = 0; k < n; k++)
                {
                    A[j][k] = A[j][k] - temp * A[i][k];
                }
                y[j] = y[j] - temp * y[i];
            }
        }
    }
    for(int32_t i = 0; i < n; i++)
    {
        if (A[i][i] == 0 && y[i] != 0)
        {
            *(px) = NULL;
            return 0;
        }
        
    }
    for (int32_t i = 0; i < n; i++)
    {
        if (A[i][i] == 0 && y[i] == 0)
        {
            *(px) = NULL;
            return 2;
        }
    }
    
    // if (not_one_solution)
    // {
        // if (y[not_one_solution - 1] != 0)
        // {
        //     *(px) = NULL;
        //     return 0;
        // }
        // else
        // {
        //     *(px) = NULL;
        //     return 2;
        // }
    // }
    // print error message
    fprintf(stderr, "A:\n");
    for (int32_t i = 0; i < n; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            fprintf(stderr, "%d ", A[i][j]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "y:\n");
    for (int32_t i = 0; i < n; i++)
    {
        fprintf(stderr, "%d\n", y[i]);
    }
    // print error message

    // reduce row echelon form
    for (int32_t i = 0; i < n; i++) // set leading 1
    {
        if (A[i][i] != 1)
        {
            for (int32_t j = i + 1; j < n; j++)
            {
                A[i][j] = A[i][j] / A[i][i];
            }
            y[i] /= A[i][i];
            A[i][i] = 1;
        }
    }
    // print error message
    fprintf(stderr, "A:\n");
    for (int32_t i = 0; i < n; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            fprintf(stderr, "%d ", A[i][j]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "y:\n");
    for (int32_t i = 0; i < n; i++)
    {
        fprintf(stderr, "%d\n", y[i]);
    }
    // print error message
    for (int32_t i = n-1; i >0; i--) // set 0
    {
        for (int32_t j = i - 1; j >= 0; j--)
        {
            y[j] = y[j] - A[j][i] * y[i];
            A[j][i] = 0;
        }
    }
    for (int32_t i = 0; i < n; i++)
    {
        *(ptr_x + i) = y[i];
    }
    // print error message
    fprintf(stderr, "A:\n");
    for (int32_t i = 0; i < n; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            fprintf(stderr, "%d ", A[i][j]);
        }
        fprintf(stderr, "\n");
    }
    fprintf(stderr, "y:\n");
    for (int32_t i = 0; i < n; i++)
    {
        fprintf(stderr, "%d\n", y[i]);
    }
    // print error message
    return 1;
}
