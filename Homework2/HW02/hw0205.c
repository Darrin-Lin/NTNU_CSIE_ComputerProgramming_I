#include <stdio.h>
#include <stdint.h>
int32_t L = 0, N = 0;
int64_t width = 0, Hight = 0;
int32_t print_line()
{
	printf("*");
	for (int32_t i = 0; i < L - 2; i++)
	{
		printf("-");
	}
	printf("*");
}
int32_t print_line_space()
{
	for (int32_t i = 0; i < L + 2 * (L - 2); i++)
	{
		printf(" ");
	}
}
int main()
{

	printf("Please input the length: ");
	scanf("%d", &L);
	if (L < 3)
	{
		printf("L is less than 3.\n");
		return 1;
	}
	printf("Please input the number of layer: ");
	scanf("%d", &N);
	if (N < 1)
	{
		printf("N is less than 1.\n");
		return 1;
	}
	width = N * (3 * L - 2) + (N - 1) * (L - 2);
	Hight = ((2 * N - 1) * (L - 1)) * 2 + 1;
	if (width > 80) // max width
	{
		printf("The width of the map is larger than 80.\n");
		return 1;
	}
	int32_t H_half = 0, negavite_i = 0;
	H_half = (L - 1) * (2 * N - 1);

	for (int32_t i = 1; i <= Hight; i++) // easy to count / i row
	{
		negavite_i = Hight - i + 1;

		if (!(N % 2)) // even N
		{
			//-------------------longest-------------------                                                        // odd
			if (i % (2 * (L - 1)) == 1 && i > N * (L - 1) && negavite_i > N * (L - 1)) //*  *
			{
				printf("*");
				print_line_space();
				for (int32_t j = 0; j<N - 1; j++)
				{
					print_line();
					print_line_space();
				}
				printf("*");
			}
			//-------------------normal line-------------------
			else if (i % (L - 1) == 1) //__*-*  *-*
			{
				if (i < H_half)
				{
					if (i / (L - 1) < N)
					{
						for (int32_t j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))); j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (int32_t j = 0; j < L - 1; j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
				else if (i == H_half)
				{
					for (int32_t j = 0; j < L - 1; j++) ////////
					{
						printf(" ");
					}
					print_line();
					for (int32_t j = 0; j < N - 1; j++)
					{
						print_line_space();
						print_line();
					}
				}
				else
				{
					if (negavite_i / (L - 1) < N)
					{
						for (int32_t j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))); j++) ////////
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < negavite_i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (int32_t j = 0; j < L - 1; j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
			}
		}
		else // odd N
		{
			//-------------------longest-------------------
			if (i % (2 * (L - 1)) == L && i > N * (L - 1) && i <= Hight - N * (L - 1)) //* *-*
			{
				printf("*");
				print_line_space();
				for (int32_t j = 0; N - 1; j++)
				{
					print_line();
					print_line_space();
				}
				printf("*");
			}
			//-------------------normal line-------------------
			else if (i % (L - 1) == 1)
			{
				if (i < H_half)
				{
					if (i / (L - 1) < N)
					{
						for (int32_t j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))); j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (int32_t j = 0; j < L - 1; j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
				else
				{
					if (negavite_i / (L - 1) < N)
					{
						for (int32_t j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))); j++) ////////
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < negavite_i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (int32_t j = 0; j < L - 1; j++)
						{
							printf(" ");
						}
						print_line();
						for (int32_t j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}