#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "gsat.h"

#define need_space 0

void bubble_sort(int32_t *array, uint64_t n, uint64_t each_size);
void mergeSort(int32_t *array, uint64_t n, uint64_t each_size);
void mergeSort_conquer(int *array, int left, int mid, int right, int *temp);
void mergeSort_divide(int *array, int left, int right, int *temp);

int main()
{
    int32_t score_sort[6][STUDENT_NUMBER] = {0};
    for (uint64_t i = 0; i < STUDENT_NUMBER; i++)
    {
        for (uint64_t j = 0; j < 6; j++)
        {
            score_sort[j][i] = score[i][j];
        }
    }
    // bubble sort
    if(need_space)
    {
        bubble_sort((int32_t *)score_sort, 0, STUDENT_NUMBER);
        bubble_sort((int32_t *)score_sort, 1, STUDENT_NUMBER);
        bubble_sort((int32_t *)score_sort, 2, STUDENT_NUMBER);
        bubble_sort((int32_t *)score_sort, 3, STUDENT_NUMBER);
        bubble_sort((int32_t *)score_sort, 4, STUDENT_NUMBER);
        bubble_sort((int32_t *)score_sort, 5, STUDENT_NUMBER);
    }
    // merge sort
    else
    {
        mergeSort((int32_t *)score_sort, 0, STUDENT_NUMBER);
        mergeSort((int32_t *)score_sort, 1, STUDENT_NUMBER);
        mergeSort((int32_t *)score_sort, 2, STUDENT_NUMBER);
        mergeSort((int32_t *)score_sort, 3, STUDENT_NUMBER);
        mergeSort((int32_t *)score_sort, 4, STUDENT_NUMBER);
        mergeSort((int32_t *)score_sort, 5, STUDENT_NUMBER);
    }

    // for (uint64_t i = 0; i <6; i++)
    // {
    //     for (uint64_t j = 0; j < STUDENT_NUMBER; j++)
    //     {
    //         fprintf(stderr,"%d ", score_sort[i][j]);
    //     }
    //     fprintf(stderr,"\n");
    // }
    uint64_t persentage[5] = {0};
    persentage[0] = (uint64_t)(STUDENT_NUMBER * 0.88 + 0.99999);
    persentage[1] = (uint64_t)(STUDENT_NUMBER * 0.75 + 0.99999);
    persentage[2] = (uint64_t)(STUDENT_NUMBER * 0.5 + 0.99999);
    persentage[3] = (uint64_t)(STUDENT_NUMBER * 0.25 + 0.99999);
    persentage[4] = (uint64_t)(STUDENT_NUMBER * 0.12 + 0.99999);
    printf("         CHINESE | ENGLISH | MATH_A  | MATH_B  | SOCIAL  | SCIENCE\n");
    printf("TOP 12%%     %2d        %2d        %2d        %2d        %2d        %2d\n", score_sort[CHINESE][persentage[0] - 1], score_sort[ENGLISH][persentage[0] - 1], score_sort[MATH_A][persentage[0] - 1], score_sort[MATH_B][persentage[0] - 1], score_sort[SOCIAL][persentage[0] - 1], score_sort[SCIENCE][persentage[0] - 1]);
    printf("TOP 25%%     %2d        %2d        %2d        %2d        %2d        %2d\n", score_sort[CHINESE][persentage[1] - 1], score_sort[ENGLISH][persentage[1] - 1], score_sort[MATH_A][persentage[1] - 1], score_sort[MATH_B][persentage[1] - 1], score_sort[SOCIAL][persentage[1] - 1], score_sort[SCIENCE][persentage[1] - 1]);
    printf("TOP 50%%     %2d        %2d        %2d        %2d        %2d        %2d\n", score_sort[CHINESE][persentage[2] - 1], score_sort[ENGLISH][persentage[2] - 1], score_sort[MATH_A][persentage[2] - 1], score_sort[MATH_B][persentage[2] - 1], score_sort[SOCIAL][persentage[2] - 1], score_sort[SCIENCE][persentage[2] - 1]);
    printf("TOP 75%%     %2d        %2d        %2d        %2d        %2d        %2d\n", score_sort[CHINESE][persentage[3] - 1], score_sort[ENGLISH][persentage[3] - 1], score_sort[MATH_A][persentage[3] - 1], score_sort[MATH_B][persentage[3] - 1], score_sort[SOCIAL][persentage[3] - 1], score_sort[SCIENCE][persentage[3] - 1]);
    printf("TOP 88%%     %2d        %2d        %2d        %2d        %2d        %2d\n", score_sort[CHINESE][persentage[4] - 1], score_sort[ENGLISH][persentage[4] - 1], score_sort[MATH_A][persentage[4] - 1], score_sort[MATH_B][persentage[4] - 1], score_sort[SOCIAL][persentage[4] - 1], score_sort[SCIENCE][persentage[4] - 1]);
    return 0;
}
void bubble_sort(int32_t *array, uint64_t n, uint64_t each_size)
{
    for (uint64_t i = 0; i < each_size; i++)
    {
        for (uint64_t j = 0; j < each_size - i - 1; j++)
        {
            if (*(array + each_size * n + j) > *(array + each_size * n + j + 1))
            {
                int32_t temp = *(array + each_size * n + j);
                *(array + each_size * n + j) = *(array + each_size * n + j + 1);
                *(array + each_size * n + j + 1) = temp;
            }
        }
    }
    return;
}
// from wikipedia
void mergeSort_conquer(int *array, int left, int mid, int right, int *temp)
{
    int i = left;
    int j = mid + 1;
    int index = 0;
    while (i <= mid && j <= right)
    {
        if (array[i] < array[j])
        {
            temp[index++] = array[i++];
        }
        else
        {
            temp[index++] = array[j++];
        }
    }
    while (i <= mid)
    {
        temp[index++] = array[i++];
    }
    while (j <= right)
    {
        temp[index++] = array[j++];
    }
    index = 0;
    while (left <= right)
    {
        array[left++] = temp[index++];
    }
}

void mergeSort_divide(int *array, int left, int right, int *temp)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort_divide(array, left, mid, temp);
        mergeSort_divide(array, mid + 1, right, temp);
        mergeSort_conquer(array, left, mid, right, temp);
    }
}

void mergeSort(int32_t *array, uint64_t n, uint64_t each_size)
{
    int *temp = (int *)malloc(sizeof(int) * each_size);
    mergeSort_divide(array + n * each_size, 0, each_size - 1, temp);
}