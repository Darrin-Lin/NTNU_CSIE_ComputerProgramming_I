#include <stdio.h>
#include <stdint.h>

#define ptf printf
// Pin: 1~9 (0~8)
// So: 10~18 (9~17)
// Wan: 19~27 (18~26)
// wind ( 東南西北 ): 28~31 (27~30)
// 白發中: 32~34 (31~33)

static int32_t melds[4][4] = {0};
static int32_t cards_count[33] = {0};
static int32_t pair[2] = {0};
static int32_t winning_tile = 0, self_drawn_win = 0, plqyer_wind = 0, prevailing_wind = 0, special_case = 0, open_hand = 0;
static int32_t triplets = 0, kans = 0, sequences = 0; // 刻子 槓子 順子 3 4 3
static int32_t han = 0, yakuman = 0;
// static int32_t yaku_flag[33] = {0};

static void count_yaku();

int main()
{
	ptf("Please input meld: ");
	int32_t inp = 0;
	int32_t inp_count = 0, meld_count = 0;
	int8_t unresonable = 0;
	static int32_t meld_inp[14] = {0};
	int32_t errinp = 0;
	while (inp_count < 14)
	{
		scanf("%d", &inp);
		inp_count++;
		while (inp_count < 14 && inp)
		{
			if (inp > 34 || inp < 0)
			{
				unresonable = 1;
			}
			meld_inp[inp_count] = inp;
			scanf("%d", &inp);
			inp_count++;
		}
		scanf("%*[^\n]%n", &errinp);
		if (errinp)
		{
			unresonable = 1;
		}
		if (inp_count == 14)
		{
			special_case = 1;
		}
		else
		{
			ptf("Is open/closed group(1: open 0: closed):");
			int32_t inp_hand = 0;
			scanf("%d", &inp_hand);
			if (inp_hand > 1 || inp_hand < 0)
			{
				unresonable = 1;
			}
			if (inp_hand)
			{
				open_hand++;
			}
			if (inp_count < 3 || inp_count > 4)
			{
				unresonable = 1;
			}
			int32_t is_same = 1, is_straight = 1;
			for (int32_t i = 0; i < inp_count; i++)
			{
				cards_count[meld_inp[i] - 1]++;
				melds[0][i] = meld_inp[i];
				if ((i > 0 && (meld_inp[i] != meld_inp[i - 1] + 1) || ((meld_inp[i] - 1) / 9 != (meld_inp[i - 1] - 1) / 9)) || meld_inp[i] > 27)
				{
					is_straight = 0;
				}

				if (i > 0 && meld_inp[i] != meld_inp[i - 1])
				{
					is_same = 0;
				}
			}
			if (!(is_same || is_straight))
			{
				unresonable = 1;
			}
			if (is_straight && inp_count == 4)
			{
				unresonable = 1;
			}
			if (is_same && inp_count == 3)
			{
				triplets++;
			}
			if (is_same && inp_count == 4)
			{
				kans++;
			}
			if (is_straight && inp_count == 3)
			{
				sequences++;
			}
			is_same = 1, is_straight = 1;
			meld_count++;
			for (int32_t i = 1; i < 4; i++)
			{
				inp_count = 0;
				scanf("%d", &inp);
				while (inp && inp_count < 4)
				{
					if (inp > 34 || inp < 0)
					{
						unresonable = 1;
					}
					meld_inp[inp_count] = inp;
					scanf("%d", &inp);
					inp_count++;
				}
				scanf("%*[^\n]%n", &errinp);
				if (errinp)
				{
					unresonable = 1;
				}
				if (inp_count < 3 || inp_count > 4)
				{
					unresonable = 1;
				}
				for (int32_t j = 0; j < inp_count; j++)
				{
					cards_count[meld_inp[j] - 1]++;
					melds[i][j] = meld_inp[j];
				}
				ptf("Is open/closed group(1: open 0: closed):");
				scanf("%d", &inp_hand);
				if (inp_hand > 1 || inp_hand < 0)
				{
					unresonable = 1;
				}
				if (inp_hand)
				{
					open_hand++;
				}
				for (int32_t i = 0; i < inp_count; i++)
				{
					cards_count[meld_inp[i] - 1]++;
					melds[0][i] = meld_inp[i];
					if ((i > 0 && (meld_inp[i] != meld_inp[i - 1] + 1) || ((meld_inp[i] - 1) / 9 != (meld_inp[i - 1] - 1) / 9)) || meld_inp[i] > 27)
					{
						is_straight = 0;
					}
					if (i > 0 && meld_inp[i] != meld_inp[i - 1])
					{
						is_same = 0;
					}
				}
				if (!(is_same || is_straight))
				{
					unresonable = 1;
				}
				if (is_straight && inp_count == 4)
				{
					unresonable = 1;
				}
				if (is_same && inp_count == 3)
				{
					triplets++;
				}
				if (is_same && inp_count == 4)
				{
					kans++;
				}
				if (is_straight && inp_count == 3)
				{
					sequences++;
				}
				is_same = 1, is_straight = 1;
				meld_count++;
			}
			ptf("Please input pair: ");
			for (int32_t i = 0; i < 2; i++)
			{
				scanf("%d", &inp);
				if (inp > 34 || inp < 1)
				{
					unresonable = 1;
				}
				cards_count[inp - 1]++;
				pair[i] = inp;
				inp_count++;
			}
			scanf("%*[^\n]%n", &errinp);
			if (errinp)
			{
				unresonable = 1;
			}
			if (pair[0] != pair[1])
			{
				unresonable = 1;
			}
		}
	}
	for (int64_t i = 0; i < 33; i++)
	{
		if (cards_count[i] > 4)
		{
			unresonable = 1;
		}
	}
	ptf("Please input winning tile:"); //
	scanf("%d", &winning_tile);
	ptf("Is Self-drawn win?(1: YES 0: NO): "); //
	scanf("%d", &self_drawn_win);
	if (self_drawn_win > 1 || self_drawn_win < 0)
	{
		unresonable = 1;
	}
	ptf("Player's wind(0:E 1:S 2:W 3:N): "); //
	scanf("%d", &plqyer_wind);
	if (plqyer_wind > 3 || plqyer_wind < 0)
	{
		unresonable = 1;
	}
	ptf("Prevailing wind(0:E 1:S 2:W 3:N): "); //
	scanf("%d", &prevailing_wind);
	if (prevailing_wind > 3 || prevailing_wind < 0)
	{
		unresonable = 1;
	}
	if (unresonable)
	{
		goto unresonable_case;
	}
	// 二盃口比七對子優先
	// unresonable case
	ptf("The Score is...\n");
	count_yaku();
	if (han == 0)
	{
		ptf("    No Yaku\n");
	}
	ptf("Toltal: ");

	if (yakuman)
	{
		ptf("%d Yakuman\n", yakuman);
	}
	else
	{
		if (han > 13)
		{
			ptf("%d Han (Kazoe-yakuman)\n", han);
		}
		ptf("%d Han\n", han);
	}
	if (0)
	{
	unresonable_case:
		ptf("The Score is...\n    Unreasonable case\nTotal: 0 Han\n");
		return 1;
	}

	return 0;
}
static void count_yaku()
{
	if (special_case)
	{
		int32_t closed_hand = 1;
		if (open_hand)
		{
			closed_hand = 0;
		}

		int32_t thirteen_orphans = 0, thirteen_orphans_flag = 0;
		for (int32_t i = 0; i < 3; i++)
		{
			if (cards_count[i * 9] == 1)
			{
				thirteen_orphans++;
			}
			else if (cards_count[i * 9] == 2 && !thirteen_orphans_flag)
			{
				thirteen_orphans++;
				thirteen_orphans_flag == i * 9 + 1;
			}
			if (cards_count[(i + 1) * 9 - 1] == 1)
			{
				thirteen_orphans++;
			}
			else if (cards_count[(i + 1) * 9 - 1] == 2 && !thirteen_orphans_flag)
			{
				thirteen_orphans++;
				thirteen_orphans_flag == (i + 1) * 9;
			}
			if (cards_count[27 + i] == 1)
			{
				thirteen_orphans++;
			}
			else if (cards_count[27 + i] == 2 && !thirteen_orphans_flag)
			{
				thirteen_orphans++;
				thirteen_orphans_flag == 27 + i + 1;
			}
			if (cards_count[31 + i] == 1)
			{
				thirteen_orphans++;
			}
			else if (cards_count[31 + i] == 2 && !thirteen_orphans_flag)
			{
				thirteen_orphans++;
				thirteen_orphans_flag == 31 + i + 1;
			}
		}
		if (cards_count[30] == 1)
		{
			thirteen_orphans++;
		}
		else if (cards_count[30] == 2 && !thirteen_orphans_flag)
		{
			thirteen_orphans++;
			thirteen_orphans_flag == 31;
		}
		if (thirteen_orphans == 13)
		{
			if (winning_tile == thirteen_orphans_flag) // 國士無雙十三面
			{
				yakuman += 2;
				ptf("    Thirteen orphans 13 wait (2 Yakuman)\n");
				return;
			}
			else // 國士無雙
			{
				yakuman++;
				ptf("    Thirteen orphans (1 Yakuman)\n");
				return;
			}
		}

		// 七對子
		int32_t pair_count = 0;

		for (int32_t i = 0; i < 33; i++)
		{
			if (cards_count[i] == 2)
			{
				pair_count++;
			}
		}
		if (pair_count == 7 && closed_hand)
		{
			ptf("    Seven pairs (2 Han)\n");
			han += 2;
			return;
		}
	}
	// 2 Yakuman
	// Big four winds

	if (yakuman)
	{
		return;
	}
	// Han
}

/*
2 Yakuman

Big four winds
Four concealed triplets single wait
Nine gates nine wait
// Thirteen orphans 13 wait [*]

1 Yakuman

All green
All honors
All terminals
Big three dragons
Four concealed triplets
Four kans
Little four winds
Nine gates
// Thirteen orphans [*]

6 Han

Flush (no open group)

5 Han

Flush (have open group)

3 Han

Half-flush (no open group)
Terminal in each set (no open group)

2 Han

All triplets
All terminals and honors
Half-flush (have open group)
Little three dragons
// Seven pairs (no Two sets of identical sequences)(Closed hands only) [*]
Straight (no open group)(closed hands only)
Terminal in each set (have open group)
Terminal or honor in each set (no open group)
Three colour triplets
Three colour straights (no open group)(Closed hands only)
Three kans
Two sets of identical sequences (Closed hands only)

1 Han

All simples
No-points hand (Closed hands only)
One set of identical sequences (Closed hands only)
Honor(役牌) tiles of White(白) or Green(發) or Red(中)
Player’s wind of East(東風) South(南風) West(西風) North(北風)
Prevailing wind of East(東風) South(南風) West(西風) North(北風)
Terminal or honor in each set (have open group)
Three colour straights (have opne group)
Straight (have open group)(Closed hand only)

*/