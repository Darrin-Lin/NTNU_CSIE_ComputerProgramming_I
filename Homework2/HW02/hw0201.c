#include <stdio.h>
#include <stdint.h>

int main()
{
	double real_root_2 = 1.41421356237309504880;
	double count_root_2 = 1;							   // prec *2 +preprec /prem*2 +preprem
	uint64_t prec = 3, prem = 2, preprec = 1, preprem = 1; // start from n = 3
	uint64_t save = 0;
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
		count_root_2 = (double)prec / (double)prem;
		printf("n = 2: %.20f (%.20f)\n", count_root_2, count_root_2 - real_root_2);
	}
	if (n >= 3)
	{
		for (uint16_t i = 3; i <= n; i++)
		{
			save = prec;
			prec = 2 * prec + preprec;
			preprec = save;
			save = prem;
			prem = 2 * prem + preprem;
			preprem = save;
			// printf("%lu %lu %lu %lu\n", prec, prem, preprec, preprem);
			count_root_2 = (double)prec / (double)prem;
			printf("n = %hu: %.20f (%.20f)\n", i, count_root_2, count_root_2 - real_root_2);
		}
	}
	return 0;
}