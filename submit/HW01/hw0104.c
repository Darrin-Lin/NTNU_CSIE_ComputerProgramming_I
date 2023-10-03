#include <stdio.h>
#include <stdint.h>

int32_t spade = 0, heart = 0, diamond = 0, club = 0;
int32_t HCP = 0, in_card = 0;
int32_t fttt = 0, spadeAKQ = 0, heartAKQ = 0, rt0 = 1;
uint8_t count()
{
	scanf("%d", &in_card);
	if (in_card > 52 || in_card < 1)
	{
		printf("Error! Card out of range.\n");
		return 1;
	}
	switch ((in_card - 1) / 13)
	{
	case 0:
		spade++;
		break;
	case 1:
		heart++;
		break;
	case 2:
		diamond++;
		break;
	case 3:
		club++;
		break;
	default:
		break;
	}
	switch (in_card % 13)
	{
	case 0: // K
		HCP += 3;
		if ((in_card - 1 / 13) == 0)
			spadeAKQ++;
		if ((in_card - 1 / 13) == 1)
			heartAKQ++;
		break;
	case 1: // A
		HCP += 4;
		if ((in_card - 1 / 13) == 0)
			spadeAKQ++;
		if ((in_card - 1 / 13) == 1)
			heartAKQ++;
		break;
	case 11: // J
		HCP++;
		break;
	case 12: // Q
		HCP += 2;
		if ((in_card - 1 / 13) == 0)
			spadeAKQ++;
		if ((in_card - 1 / 13) == 1)
			heartAKQ++;
		break;
	default:
		break;
	}

	return 0;
}

int main()
{
	if (rt0)
	{
		printf("1st card: ");
		if (count())
			return 0;
		printf("2nd card: ");
		if (count())
			return 0;
		printf("3rd card: ");
		if (count())
			return 0;
		printf("4th card: ");
		if (count())
			return 0;
		printf("5th card: ");
		if (count())
			return 0;
		printf("6th card: ");
		if (count())
			return 0;
		printf("7th card: ");
		if (count())
			return 0;
		printf("8th card: ");
		if (count())
			return 0;
		printf("9th card: ");
		if (count())
			return 0;
		printf("10th card: ");
		if (count())
			return 0;
		printf("11th card: ");
		if (count())
			return 0;
		printf("12th card: ");
		if (count())
			return 0;
		printf("13th card: ");
		if (count())
			return 0;
	}
	fttt = (spade == 4 && heart == 3 && diamond == 3 && club == 3) ||
				   (spade == 3 && heart == 4 && diamond == 3 && club == 3) ||
				   (spade == 3 && heart == 3 && diamond == 4 && club == 3) ||
				   (spade == 3 && heart == 3 && diamond == 3 && club == 4)
			   ? 1
			   : 0;
	printf("---\n");
	printf("HCP: %d pts\n", HCP);
	printf("Suit: %d-%d-%d-%d\n", spade, heart, diamond, club);
	printf("The bidding choice : ");
	if (HCP <= 24 && HCP >= 22 && fttt)
		printf("2NT");
	else if (HCP >= 16)
		printf("1♣");
	else if (HCP >= 11 && HCP <= 15 && fttt)
		printf("1NT");
	else if (HCP >= 11 && HCP <= 15 && (spade >= 5 || heart >= 5))
	{
		if (spade >= heart)
			printf("1♠");
		else
			printf("1♡");
	}
	else if (HCP >= 11 && HCP <= 15 && diamond >= 4)
		printf("1♢");
	else if (HCP >= 11 && HCP <= 15 && club >= 6)
		printf("2♣");
	else if (HCP >= 11 && HCP <= 15 && club >= 5 && diamond == 0)
		printf("2♢");
	else if (HCP >= 8 && HCP <= 10 && spade == 6)
		printf("2♠");
	else if (HCP >= 8 && HCP <= 10 && heart == 6)
		printf("2♡");
	else if (HCP >= 8 && HCP <= 11 && spade == 7)
		printf("3♠");
	else if (HCP >= 8 && HCP <= 11 && heart == 7)
		printf("3♡");
	else if (HCP >= 8 && HCP <= 11 && diamond == 7)
		printf("3♢");
	else if (HCP >= 8 && HCP <= 11 && club == 7)
		printf("3♣");
	else if (HCP < 16 && ((spade == 7 && spadeAKQ == 3) || (heart == 7 && heartAKQ == 3)))
		printf("3NT");
	else
		printf("Pass");
	printf("\n");
	return 0;
}