#include "diceRolls.h"
#include <stdio.h>
#include <stdint.h>

#define TITLE "DICE ROLLS"
#define ptf printf
#define scf scanf

void rule();

int main()
{
	rule();
	int32_t action = 0;
	ptf("----------------------------------------\n");
	ptf("Your action: ");
	scf("%d", &action);

	while (action)
	{
		switch (action)
		{
		case 0: // will not active
			// goto end;
			break;

		case 1:
			Id6();
			break;
		case 2:
			AdX();
			break;
		case 3:
			AdXkY_add_B();
			break;
		case 4:
			AdXkhHklLkcC_add_B();
			break;
		case -1:
			rule();
			break;
		default:
			ptf("Not an action number!\n");
			goto end;
			break;
		}
		ptf("----------------------------------------\n");
		ptf("Your action: ");
		scf("%d", &action);
		
	}

	end:;
	ptf("Bye!\n");
	return 0;
}
void rule()
{
	ptf("Welcom to DiceRoller!\n");
	ptf("Input \033[94m0\033[0m to quit.\n");
	ptf("Input \033[94m1\033[0m to roll a dice with \033[33m6\033[0m side.\n");
	ptf("Input \033[94m2\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each.\n");
	ptf("Input \033[94m3\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each, and choose \033[33mY\033[0m dice and add \033[33mB\033[0m for the bonus.\n");
	ptf("Input \033[94m4\033[0m to roll \033[33mA\033[0m dice with \033[33mX\033[0m sides each, keeping the \033[33mH\033[0m highest, the \033[33mL\033[0m lowest, and \033[33mC\033[0m of the player’s choice and add \033[33mB\033[0m for the bonus.\n");
	ptf("Input \033[94m-1\033[0m number to see this again.\n");
	ptf("Input other number will also quit this program.\n");
	ptf("\n1:1d6\n2:AdX\n3:AdXkY+B\n4:AdXkhHklLkcC+B\n");
	ptf("\nrange:\n");
	ptf("\033[33mA\033[0m: 0~10\n");
	ptf("\033[33mX\033[0m: 2~100\n");
	ptf("\033[33mB\033[0m: -10~10\n");
	ptf("\033[33mY\033[0m: 0~A\n");
	ptf("\033[33mH\033[0m: 0~A\n");
	ptf("\033[33mL\033[0m: 0~A\n");
	ptf("\033[33mC\033[0m: 0~A-(L+H)\n");
}