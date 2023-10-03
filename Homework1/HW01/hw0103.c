#include <stdio.h>
#include <stdint.h>
int main()
{
	int32_t ax = 0, ay = 0, bx = 0, by = 0; //(double)a
	int32_t x = 0, y = 0;
	double area = 0, xi = 0, yi = 0, save = 0; //(xi,0),(0,yi)
	printf("Please enter the point A (x,y): ");
	scanf("%d,%d", &ax, &ay);
	printf("Please enter the point B (x,y): ");
	scanf("%d,%d", &bx, &by);
	if (ax == bx && ay == by)
	{
		printf("Error! They are the same point.\n");
		return 0;
	}
	else if (ax == bx || ay == by)
	{ // can don't use esle
		printf("Error! Line AB is horizontal or vertical.\n");
		return 0;
	}
	else if ((ax == 0 && ay == 0) || (bx == 0 && by == 0))
	{
		printf("Error! Line AB across the origin.\n");
		return 0;
	}

	if (ax * by == ay * bx)
	{
		printf("Error! Line AB across the origin.\n");
		return 0;
	}

	x = ax - bx;
	y = ay - by;
	yi = -1 * (double)ax / x * y + (double)ay;
	xi = -1 * (double)ay / y * x + (double)ax;
	area = xi * yi / 2;
	if (area < 0)
		area *= -1;
	area += 1e-9;
	// printf("%.50f\n", area * 1000);
	if ((int)(double)(area * 1000) % 10 > 4)
		area += 0.01;
	printf("Area: %.2f\n", area);
	return 0;
}