#include <stdio.h>
#include <stdint.h>

int main()
{
	double real_root_2 = 1.41421356237309504880;
	double count_root_2 = 0;
	uint16_t n = 0;
	printf(" Please enter n (16-bits unsigned): ");
	scanf("%hu", &n);
	if (n == 0)
	{
		printf("n = 0: 0.00000000000000000000 (-1.41421356237309504880)\n");
		return 0;
	}
	if (n >= 1)
		printf("n = 1: 1.00000000000000000000 (-0.41421356237309504880)\n");
	if (n >= 2)
	{
		for (uint16_t i = 2; i <= n; i++)
		{
            count_root_2=0;
			for(int j = 1;j<i;j++)
            {
                count_root_2 = 1.0/(2.0+count_root_2);
            }
            count_root_2++;
			printf("n = %hu: %.20f (%.20f)\n", i, count_root_2, count_root_2 - real_root_2);
		}
	}
	return 0;
}