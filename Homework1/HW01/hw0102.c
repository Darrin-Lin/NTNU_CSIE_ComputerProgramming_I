#include <stdio.h>
#include <stdint.h>

int main()
{
	int32_t n1 = 0, n2 = 0;
	int32_t m1 = 0, m2 = 0, ans = 0;
	/*
			n1
		*)	n2
		------
			m1
		m2
		------
			ans
	*/
	printf("Please enter the first number: ");
	scanf("%d", &n1);
	printf("Please enter the second number: ");
	scanf("%d", &n2);
	if (n1 > 99 || n1 < 0 || n2 > 99 || n2 < 0)
	{
		printf("Wrong input, your input must between 0 ~ 99.");
		return 0;
	}
	ans = n1 * n2;
	m1 = n1 * (n2 % 10);
	m2 = n1 * (n2 / 10);
	if (n1 < 10 && n2 < 10)
	{
		if (ans < 10)
		{
			printf("  %d\n", n1);
			printf("*)%d\n", n2);
			printf("---\n");
			printf("  %d\n", ans);
		}
		else
		{
			printf("    %d\n", n1);
			printf("*)  %d\n", n2);
			printf("-----\n");
			printf("  %d %d\n", ans / 10, ans % 10);
		}
	}
	/*

	  * *				  	* *
	*)  *				*)	  *
	-----			OR	-------
	  * * (0 or **)	 	  * * *
	*/
	else if (n1 > 9 && n2 < 10)
	{
		if (ans < 10)
		{
			printf("  %d %d\n", n1 / 10, n1 % 10);
			printf("*)  %d\n", n2);
			printf("-----\n");
			printf("    %d\n", ans);
		}
		else if (ans < 100) // 11~99
		{
			printf("  %d %d\n", n1 / 10, n1 % 10);
			printf("*)  %d\n", n2);
			printf("-----\n");
			printf("  %d %d\n", ans / 10, ans % 10);
		}
		else // 100~891
		{
			printf("    %d %d\n", n1 / 10, n1 % 10);
			printf("*)    %d\n", n2);
			printf("-------\n");
			printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
		}
	}
	/*
		*				  	  *
	*)* *				*)	* *
	-----				-------
	  *	* (* or **)			* *
	  * 				  * *
	-----			OR	-------
	  * * (0 or **)	 	  * * *
	*/
	else if (n1 < 10 && n2 > 9)
	{
		if (ans < 10) // 0
		{
			printf("    %d\n", n1);
			printf("*)%d %d\n", n2 / 10, n2 % 10);
			// printf("-----\n");
			// printf("    %d\n", m1);
			// printf("  %d  \n", m2);
			printf("-----\n");
			printf("    %d\n", ans);
		}
		else if (ans < 100) // 11~99(m2<10)
		{
			if (m1 < 10)
			{
				printf("    %d\n", n1);
				printf("*)%d %d\n", n2 / 10, n2 % 10);
				printf("-----\n");
				printf("    %d\n", m1);
				printf("  %d  \n", m2);
				printf("-----\n");
				printf("  %d %d\n", ans / 10, ans % 10);
			}
			else if (m1 > 9)
			{
				printf("    %d\n", n1);
				printf("*)%d %d\n", n2 / 10, n2 % 10);
				printf("-----\n");
				printf("  %d %d\n", m1 / 10, m1 % 10);
				printf("  %d  \n", m2);
				printf("-----\n");
				printf("  %d %d\n", ans / 10, ans % 10);
			}
		}
		else // 100~891(m2>9||m1/10+m2>9)(not m1<10&&m2<10)
		{
			if (m1 < 10 && m2 > 9)
			{
				printf("      %d\n", n1);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("      %d\n", m1);
				printf("  %d %d  \n", m2 / 10, m2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1 > 9 && m2 < 10)
			{
				printf("      %d\n", n1);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("    %d %d\n", m1 / 10, m1 % 10);
				printf("    %d  \n", m2);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1 > 9 && m2 > 9)
			{
				printf("      %d\n", n1);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("    %d %d\n", m1 / 10, m1 % 10);
				printf("  %d %d  \n", m2 / 10, m2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
		}
	}
	else if (n1 > 9 && n2 > 9) // 100~9801((m1==0||m1<100||m1>99)&&(m2<100||m2>99))
	/*

		* *			  				  * *
	*)	* *						*)	  * *
	-------						---------
	  *	* * (0(1) or **(1/2)) 		* * *
	  * *	(** or *)			  *	* *
	-------		OR				---------
	  * * *			 	  		  * * * *
	*/
	{
		if (ans < 1000)
		{
			if (m1 < 10) // because 9<m2<99 m1==0
			{
				printf("    %d %d\n", n1 / 10, n1 % 10);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("      %d\n", m1);
				printf("  %d %d  \n", m2 / 10, m2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1 < 100 && m2 < 100) // need else if
			{
				printf("    %d %d\n", n1 / 10, n1 % 10);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("    %d %d\n", m1 / 10, m1 % 10);
				printf("  %d %d  \n", m2 / 10, m2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1 > 99 && m2 < 100) // need else if
			{
				printf("    %d %d\n", n1 / 10, n1 % 10);
				printf("*)  %d %d\n", n2 / 10, n2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", m1 / 100, (m1 % 100) / 10, m1 % 10);
				printf("  %d %d  \n", m2 / 10, m2 % 10);
				printf("-------\n");
				printf("  %d %d %d\n", ans / 100, (ans % 100) / 10, ans % 10);
			}
		}
		else if (ans > 999)
		{
			if (m1 < 10) // because 99<m2<999 m1==0
			{
				printf("      %d %d\n", n1 / 10, n1 % 10);
				printf("*)    %d %d\n", n2 / 10, n2 % 10);
				printf("---------\n");
				printf("        %d\n", m1);
				printf("  %d %d %d  \n", m2 / 100, (m2 % 100) / 10, m2 % 10);
				printf("---------\n");
				printf("  %d %d %d %d\n", ans / 1000, (ans % 1000) / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1 < 100 && m2 < 100) // need else if
			{
				printf("      %d %d\n", n1 / 10, n1 % 10);
				printf("*)    %d %d\n", n2 / 10, n2 % 10);
				printf("---------\n");
				printf("      %d %d\n", m1 / 10, m1 % 10);
				printf("    %d %d  \n", m2 / 10, m2 % 10);
				printf("---------\n");
				printf("  %d %d %d %d\n", ans / 1000, (ans % 1000) / 100, (ans % 100) / 10, ans % 10);
			}
			else if ( m1>99 &&m2 < 100) 
			{
				printf("      %d %d\n", n1 / 10, n1 % 10);
				printf("*)    %d %d\n", n2 / 10, n2 % 10);
				printf("---------\n");
				printf("    %d %d %d\n", m1 / 100, (m1 % 100) / 10, m1 % 10);
				printf("    %d %d  \n", m2 / 10, m2 % 10);
				printf("---------\n");
				printf("  %d %d %d %d\n", ans / 1000, (ans % 1000) / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1<100&&m2>99){
				printf("      %d %d\n", n1 / 10, n1 % 10);
				printf("*)    %d %d\n", n2 / 10, n2 % 10);
				printf("---------\n");
				printf("      %d %d\n", m1 / 10, m1 % 10);
				printf("  %d %d %d  \n", m2 / 100, (m2% 100) / 10, m2% 10);
				printf("---------\n");
				printf("  %d %d %d %d\n", ans / 1000, (ans % 1000) / 100, (ans % 100) / 10, ans % 10);
			}
			else if (m1>99&m2>99){
				printf("      %d %d\n", n1 / 10, n1 % 10);
				printf("*)    %d %d\n", n2 / 10, n2 % 10);
				printf("---------\n");
				printf("    %d %d %d\n", m1 / 100, (m1 % 100) / 10, m1 % 10);
				printf("  %d %d %d  \n", m2 / 100, (m2% 100) / 10, m2% 10);
				printf("---------\n");
				printf("  %d %d %d %d\n", ans / 1000, (ans % 1000) / 100, (ans % 100) / 10, ans % 10);
			}
		}
	}
	return 0;
}