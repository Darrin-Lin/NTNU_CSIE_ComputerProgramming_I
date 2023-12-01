#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int32_t statistics(int32_t *pData, int32_t size, double *pMean, double *pVariance, double *pStd);

int32_t statistics(int32_t *pData, int32_t size, double *pMean, double *pVariance, double *pStd)
{
    if(pData == NULL || pMean == NULL || pVariance == NULL || pStd == NULL)
    {
        return -1;
    }
    if(size <= 0)
    {
        return -1;
    }
    int64_t sum = 0;
    double mean;
    double variance;
    double std;

    for (size_t i = 0; i < size; i++)
    {
        sum += (int64_t) * (pData + i);
    }

    mean = (double)sum / (double)size;

    double sum_mean = 0;

    for (int32_t i = 0; i < size; i++)
    {
        double x_mu = (double)*(pData + i) - mean;
        sum_mean += (x_mu * x_mu);
    }

    variance = sum_mean / (double)size;

    std = sqrt(variance);

    *pMean = mean;
    *pVariance = variance;
    *pStd = std;

    return 0;
}