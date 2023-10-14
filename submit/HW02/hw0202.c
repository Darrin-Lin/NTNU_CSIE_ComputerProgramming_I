#include <stdio.h>
#include <stdint.h>
int64_t num_long_f(uint64_t x)
{
	int64_t l = 0;
	if (x == 0)
		l++;
	while (x)
	{
		l++;
		x /= 10;
	}
	return l;
}
int64_t ten_power(uint32_t u)
{
	int64_t ten_n = 1;
	for (int64_t i = 0; i < u; i++)
		ten_n *= 10;
	return ten_n;
}
int main()
{
	int64_t inp1 = 0, inp2 = 0;
	int64_t longest = 0;
	uint64_t answer = 0;
	int64_t separate = 0, space = 0, num_long = 0, num_print = 0, t_power = 0;
	int64_t count_num = 0,count_inp2=2,inp2_long=0;
	printf("Please enter the first  number: ");
	scanf("%ld", &inp1);
	printf("Please enter the second number: ");
	scanf("%ld", &inp2);
	if (inp1 < 0 || inp2 < 0)
	{
		printf("Invalid input\n");
		return 1;
	}
	answer = inp1 * inp2;
	if (inp1 && inp2)
		longest = num_long_f(answer);
	else if (inp1)
		longest = num_long_f(inp1);
	else
		longest = num_long_f(inp2);
	separate = longest * 2 + 1;

	// 1_ for loop + last number
	// n1
	// space
	num_long = num_long_f(inp1);
	space = separate - (num_long * 2 - 1);
	for (int64_t i = 0; i < space; i++)
		printf(" ");
	num_print = inp1;
	// number
	for (int64_t i = 0; i < num_long - 1; i++)
	{
		t_power = ten_power(num_long - i - 1);
		printf("%ld ", num_print / t_power);
		num_print %= t_power; //
	}
	printf("%ld", inp1 % 10);

	// n2
	// space
	num_long = num_long_f(inp2);
	space = separate - (num_long * 2 - 1);
	printf("\n");
	printf("*)");
	for (int64_t i = 0; i < space - 2; i++)
		printf(" ");
	num_print = inp2;
	// number
	for (int64_t i = 0; i < num_long - 1; i++)
	{
		t_power = ten_power(num_long - i - 1);
		printf("%ld ", num_print / t_power);
		num_print %= t_power; //
	}
	printf("%ld", inp2 % 10);
	printf("\n");
	//-----
	for (int64_t i = 0; i < separate; i++)
		printf("-");
	printf("\n");
	// counting
	if (answer&&inp2>9)
	{
		inp2_long = num_long_f(inp2);
		count_inp2=inp2;
		for (int64_t i = 0; i < inp2_long; i++)
		{
			count_num=(count_inp2%10)*inp1;
			count_inp2/=10;
			num_long = num_long_f(count_num);
			//space
			space = separate - (num_long * 2 - 1) - (i * 2);
			for (int64_t j = 0; j < space; j++)
				printf(" ");
			num_print = count_num;
			// number
			for (int64_t j = 0; j < num_long - 1; j++)
			{
				t_power = ten_power(num_long - j - 1);
				printf("%ld ", num_print / t_power);
				num_print %= t_power; //
			}
			printf("%ld", num_print % 10);
			for (int64_t j = 0; j < i * 2; j++)
				printf(" ");
			printf("\n");
		}

		//-----
		for (int64_t i = 0; i < separate; i++)
			printf("-");
		printf("\n");
	}
	// answer

	// space
	num_long = num_long_f(answer);
	space = separate - (num_long * 2 - 1);
	for (int64_t i = 0; i < space; i++)
		printf(" ");
	num_print = answer;
	// number
	for (int64_t i = 0; i < num_long - 1; i++)
	{
		t_power = ten_power(num_long - i - 1);
		printf("%ld ", num_print / t_power);
		num_print %= t_power; //
	}
	printf("%ld", answer % 10);
	printf("\n");
	return 0;
}