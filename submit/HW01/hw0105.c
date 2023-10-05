#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main()
{
	uint8_t sucess = 1;
	// char mail='\0';
	int32_t beforeAt = 0, domain = 0;
	int32_t hw = 0, p = 0, general = 0, title = 0,hwp_finish=0;
	int32_t left = 0;
	char space;
	int32_t content_scores = 0, negative = 0;
	int32_t errorD = 0, errorS = 0;
	printf("Please enter the sender address      > ");
	scanf("%*[a-z-A-Z-0-9]@%n", &beforeAt); // can't address analyse
	scanf("ntnu.edu.tw%n", &domain);		// 11
	if (!domain)
		scanf("gapps.ntnu.edu.tw%n", &domain); // 17
	if (!domain)
		scanf("csie.ntnu.edu.tw%n", &domain); // 16
	if (!domain)
		scanf("cool%n", &domain); // because csie. same will eat //4
	scanf("%*[^\n]%n", &errorD);  // left a \n
	char x;
	scanf("%c", &x); // eat \n

	// subject

	printf("Please enter the email subjectc      > ");
	// scanf("[general]%n %*[^\n]%n", &general,&title);
	// if (!general)
	// 	scanf("hw%d][p%d] %*[^\n]%n", &hw, &p,&title);

	scanf("[%n", &left);// if hw]
	if (left){
		scanf("general]%n", &general); // if enter without title error
		if (!general)
			scanf("hw%d][p%d]%n", &hw, &p,&hwp_finish);
	}
	if (general || (hw && p))
	{
		scanf("%c", &space);
		scanf("%*[^\n]%n", &title);
	}
	else
		scanf("%*[^\n]");
	scanf("%c", &x); // eat \n

	// email content score
	printf("Please enter the email content score > ");
	scanf("-%n", &negative);
	scanf("%*[0-9]%n", &content_scores); // will it have 0001?
	scanf("%*[^\n]%n", &errorS);

	// print
	printf("===============================================================================\n");
	printf("\nSender Address Test : ");
	if (beforeAt == 0)
	{
		sucess = 0;
		printf("Failed, local-part is invalid");
	}
	else if (domain == 0)
	{
		sucess = 0;
		printf("Faild, domain is not authorized");
	}
	else if (errorD)
	{
		sucess = 0;
		printf("Faild, domain is not authorized"); /////
	}
	else
	{
		printf("Passed");
	}
	printf("\nEmail Subject Test  : ");
	if (sucess == 0)
	{
		printf("-");
	}
	else if (!left)
	{
		sucess = 0;
		printf("Failed, no category");
	}
	else if ((hw <= 0 || hw >= 10 || p <= 0 || p >= 10) && general == 0)
	{
		sucess = 0;
		printf("Failed, no category");
	}
	else if (general == 0 && (hw == 0 || p == 0)) // else if
	{
		sucess = 0;
		printf("Failed, no category");
	}
	else if(!general&&hwp_finish!=8)
	{
		sucess = 0;
		printf("Failed, no category");
	}
	else if (title == 0)
	{
		sucess = 0;
		printf("Failed, title is empty");
	}
	else if (space != ' ') // no space
	{
		sucess = 0;
		printf("Failed, no space");
	}
	else
	{
		printf("Passed");
	}

	printf("\nEmail Content Test  : ");
	if (sucess == 0)
	{
		printf("-");
	}
	else if (negative)
	{
		sucess = 0;
		printf("Failed, out of range");
	}
	else if (content_scores > 19) // 10^19? 10^20
	{
		sucess = 0;
		printf("Failed, out of range");
	}
	else if (content_scores < (int)log10(title) + 11)
	{
		sucess = 0;
		printf("Failed, too low");
	}
	else if (errorS)
	{
		sucess = 0;
		printf("Failed, not interger");
	}
	else
	{
		printf("Passed");
	}
	printf("\n-------------------------------------------------------------------------------\n\n");
	if (sucess)
	{
		printf("Assigned to ");
		if (general)
		{
			printf("TA QB");
		}
		else
		{
			switch ((hw * p) % 5)
			{
			case 0:
				printf("Kaname Madoka");
				break;
			case 1:
				printf("Akemi Homura");
				break;
			case 2:
				printf("Miki Sayaka");
				break;
			case 3:
				printf("Tomoe Mami");
				break;
			case 4:
				printf("Sakura Kyoko");
				break;
			default:
				break;
			}
		}
	}
	else
	{
		printf("Rejected");
	}
	printf("\n");
	return 0;
}