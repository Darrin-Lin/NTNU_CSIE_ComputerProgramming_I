#include <stdio.h>
#include <stdint.h>

#define i32 int32_t

i32 L = 0, N = 0;
int64_t width = 0, Hight = 0;
i32 print_line()
{
	printf("*");
	for (i32 i = 0; i < L - 2; i++)
	{
		printf("-");
	}
	printf("*");
}
i32 print_line_space()
{
	for (i32 i = 0; i < L + 2 * (L - 2); i++)
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
	double H_half = 0;
	i32 negavite_i = 0;
	H_half = ((double)L - 1.0) * (2.0 * (double)N - 1.0);

	for (i32 i = 1; i <= Hight; i++) // easy to count / i row
	{
		negavite_i = Hight - i + 1;

		if (!(N % 2)) // even N
		{
			//-------------------longest-------------------                                                        // odd
			if (i % (2 * (L - 1)) == 1 && i > N * (L - 1) && negavite_i > N * (L - 1)) //*  *
			{
				printf("*");
				print_line_space();
				for (i32 j = 0; j < N - 1; j++)
				{
					print_line();
					print_line_space();
				}
				printf("*");
			}
			//-------------------normal line-------------------
			else if (i % (L - 1) == 1) //__*-*  *-*
			{
				if ((double)i < H_half)
				{
					if (i / (L - 1) < N)
					{
						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))); j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (i32 j = 0; j < L - 1; j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
				else if ((double)i == H_half)
				{
					for (i32 j = 0; j < L - 1; j++) ////////
						printf(" ");
					print_line();
					for (i32 j = 0; j < N - 1; j++)
					{
						print_line_space();
						print_line();
					}
				}
				else
				{
					if (negavite_i / (L - 1) < N)
					{
						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))); j++) ////////
							printf(" ");
						print_line();
						for (i32 j = 0; j < negavite_i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (i32 j = 0; j < L - 1; j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
			}
			//-------------------slash---------------------
			else
			{
				i32 i_mod_m_1_st1 = 0; // start from 1

				if ((double)i < H_half)
				{
					if (i % (L - 1) == 0)
						i_mod_m_1_st1 = L - 1;
					else
						i_mod_m_1_st1 = i % (L - 1);
					if (i / (L - 1) < N) // _/_+\_/_*n +
					{

						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))) - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < i / (L - 1); j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
					else if ((i / (L - 1)) % 2) // odd(\)
					{
						for (i32 j = 0; j < i_mod_m_1_st1 - 1; j++)
							printf(" ");
						printf("\\");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("/");
					}
					else // even(/)
					{
						for (i32 j = 0; j < L - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L - 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
				}
				else // negitive
				{
					if (negavite_i % (L - 1) == 0)
						i_mod_m_1_st1 = L - 1;
					else
						i_mod_m_1_st1 = negavite_i % (L - 1);
					if (negavite_i / (L - 1) < N) // _/_+\_/_*n +
					{

						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))) - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < negavite_i / (L - 1); j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
					else if ((negavite_i / (L - 1)) % 2) // odd(\)
					{
						for (i32 j = 0; j < i_mod_m_1_st1 - 1; j++)
							printf(" ");
						printf("\\");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("/");
					}
					else // even(/)
					{
						for (i32 j = 0; j < L - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L - 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
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
				for (i32 j = 0; j < N - 1; j++)
				{
					print_line();
					print_line_space();
				}
				printf("*");
			}
			//-------------------normal line-------------------
			else if (i % (L - 1) == 1)
			{
				if ((double)i < H_half)
				{
					if (i / (L - 1) < N)
					{
						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))); j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (i32 j = 0; j < L - 1; j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < N - 1; j++)
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
						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))); j++) ////////
							printf(" ");
						print_line();
						for (i32 j = 0; j < negavite_i / (L - 1); j++)
						{
							print_line_space();
							print_line();
						}
					}
					else
					{
						for (i32 j = 0; j < L - 1; j++)
							printf(" ");
						print_line();
						for (i32 j = 0; j < N - 1; j++)
						{
							print_line_space();
							print_line();
						}
					}
				}
			}
			//-------------------slash-------------------
			else
			{
				i32 i_mod_m_1_st1 = 0; // start from 1

				if ((double)i < H_half)
				{
					if (i % (L - 1) == 0)
						i_mod_m_1_st1 = L - 1;
					else
						i_mod_m_1_st1 = i % (L - 1);
					if (i / (L - 1) < N) // _/_+\_/_*n +
					{

						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (i / (L - 1))) - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < i / (L - 1); j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
					else if ((i / (L - 1)) % 2) // odd(/)
					{
						for (i32 j = 0; j < L - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L - 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
					else // even(\)
					{
						for (i32 j = 0; j < i_mod_m_1_st1 - 1; j++)
							printf(" ");
						printf("\\");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("/");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("\\");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("/");
					}
				}
				else // negitive
				{
					if (negavite_i % (L - 1) == 0)
						i_mod_m_1_st1 = L - 1;
					else
						i_mod_m_1_st1 = negavite_i % (L - 1);
					if (negavite_i / (L - 1) < N) // _/_+\_/_*n +
					{

						for (i32 j = 0; j < (L - 1) * ((2 * N - 1) - 2 * (negavite_i / (L - 1))) - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("\\");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < negavite_i / (L - 1); j++)
						{
							printf("/");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("\\");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("/");
					}
					else if ((negavite_i / (L - 1)) % 2) // odd(/)
					{
						for (i32 j = 0; j < L - (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						printf("\\");
						for (i32 j = 0; j < L - 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("/");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("\\");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("/");
					}
					else // even(/)
					{
						for (i32 j = 0; j < i_mod_m_1_st1 - 1; j++)
							printf(" ");
						printf("/");
						for (i32 j = 0; j < L + 2 * (i_mod_m_1_st1 - 1); j++)
							printf(" ");
						for (i32 j = 0; j < N - 1; j++)
						{
							printf("\\");
							for (i32 k = 0; k < L + 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
							printf("/");
							for (i32 k = 0; k < L - 2 * (i_mod_m_1_st1 - 1); k++)
								printf(" ");
						}
						printf("\\");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}