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
static int32_t winning_tile = 0, self_drawn_win = 0, plqyer_wind = 0, prevailing_wind = 0;
static int32_t special_case = 0, closed_hand = 1;
static int8_t open_hand_meld[4] = {0};
static int32_t triplets = 0, kans = 0, sequences = 0; // 刻子 槓子 順子 3 4 3
static int32_t han = 0, yakuman = 0;
static int8_t yaku_flag[30] = {0};

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
				open_hand_meld[0] = 1;
				closed_hand = 0;
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
				ptf("Please input meld: ");
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
					if ((j > 0 && (meld_inp[j] != meld_inp[j - 1] + 1) || ((meld_inp[i] - 1) / 9 != (meld_inp[i - 1] - 1) / 9)) || meld_inp[i] > 27)
					{
						is_straight = 0;
					}
					if (j > 0 && meld_inp[j] != meld_inp[j - 1])
					{
						is_same = 0;
					}
				}
				ptf("Is open/closed group(1: open 0: closed):");
				scanf("%d", &inp_hand);
				if (inp_hand > 1 || inp_hand < 0)
				{
					unresonable = 1;
				}
				if (inp_hand)
				{
					closed_hand = 0;
					open_hand_meld[i] = 1;
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
				int32_t inp_pair = 0;
				scanf("%d", &inp_pair);
				if (inp_pair > 34 || inp_pair < 1)
				{
					unresonable = 1;
				}
				cards_count[inp_pair - 1]++;
				pair[i] = inp_pair;
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
		// 國士無雙(兩種)
		{
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
					yaku_flag[0] = 1;
					yakuman += 2;
					ptf("    Thirteen orphans 13 wait (2 Yakuman)\n");
					return;
				}
				else // 國士無雙
				{
					yaku_flag[1] = 1;
					yakuman++;
					ptf("    Thirteen orphans (1 Yakuman)\n");
					return;
				}
			}
		}
		// 七對子
		{
			int32_t pair_count = 0;

			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] == 2)
				{
					pair_count++;
				}
			}
			if (pair_count == 7 && closed_hand)
			{
				yaku_flag[2] = 1;
				han += 2;
				ptf("    Seven pairs (2 Han)\n");
				return;
			}
		}
	}
	// 2 Yakuman
	// Big four winds 大四喜
	{
		int8_t big_four_winds = 0;
		for (int32_t i = 0; i < 4; i++)
		{
			if (cards_count[27 + i] == 3 || cards_count[27 + i] == 4)
			{
				big_four_winds++;
			}
		}
		if (big_four_winds == 4)
		{
			yaku_flag[3] = 1;
			yakuman += 2;
			ptf("    Big four winds (2 Yakuman)\n");
		}
	}
	// Four concealed triplets single wait 四暗刻單騎
	{
		int8_t four_concealed_triplets_single_wait = 0;
		if (triplets + kans == 4 && closed_hand)
		{
			four_concealed_triplets_single_wait++;
		}
		if (four_concealed_triplets_single_wait)
		{
			yaku_flag[4] = 1;
			yakuman += 2;
			ptf("    Four concealed triplets single wait (2 Yakuman)\n");
		}
	}
	// Nine gates nine wait 純正九蓮寶燈
	{
		int8_t nine_gates_nine_wait = 0, nine_gates_nine_wait_flag = -1;

		if (closed_hand)
		{
			for (int32_t i = 0; i < 3; i++)
			{
				if (cards_count[i * 9])
				{
					for (int32_t j = 0; j < 9; j++)
					{
						if ((i * 9 + j) % 9 != 8 && (i * 9 + j) % 9 != 0 && cards_count[i * 9 + j] == 1)
						{
							nine_gates_nine_wait++;
						}
						else if ((i * 9 + j) % 9 != 8 && (i * 9 + j) % 9 != 0 && cards_count[i * 9 + j] == 2 && nine_gates_nine_wait_flag == -1)
						{
							nine_gates_nine_wait_flag = i * 9 + j + 1;
							nine_gates_nine_wait++;
						}
						else if (((i * 9 + j) % 9 == 8 && (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] == 3)
						{
							nine_gates_nine_wait_flag = i * 9 + j + 1;
							nine_gates_nine_wait++;
						}
						else if (((i * 9 + j) % 9 == 8 && (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] == 4 && nine_gates_nine_wait_flag == -1)
						{
							nine_gates_nine_wait_flag = i * 9 + j + 1;
							nine_gates_nine_wait++;
						}
					}
					if (nine_gates_nine_wait != 9)
					{
						nine_gates_nine_wait = 0;
						nine_gates_nine_wait_flag = 0;
					}
					else
						break;
				}
			}
			if (nine_gates_nine_wait_flag == winning_tile && nine_gates_nine_wait == 9)
			{
				yaku_flag[5] = 1;
				yakuman += 2;
				ptf("    Nine gates nine wait (2 Yakuman)\n");
			}
		}
	}

	// 1 Yakuman
	// All green 綠一色
	{
		int8_t all_green = 1;
		for (int32_t i = 0; i <= 33; i++)
		{
			if (!((i >= 9 && i <= 17 && i % 2 == 0) || i == 32))
			{
				all_green = 0;
				break;
			}
		}
		if (all_green)
		{
			yaku_flag[6] = 1;
			yakuman++;
			ptf("    All green (1 Yakuman)\n");
		}
	}
	// All honors 字一色
	{
		int8_t all_honors = 1;
		for (int32_t i = 0; i <= 33; i++)
		{
			if (!(i >= 27 && i <= 33))
			{
				all_honors = 0;
				break;
			}
		}
		if (all_honors)
		{
			yaku_flag[7] = 1;
			yakuman++;
			ptf("    All honors (1 Yakuman)\n");
		}
	}
	// All terminals 清老頭
	{
		int8_t all_terminals = 1;
		for (int32_t i = 0; i <= 33; i++)
		{
			if (!((i >= 0 && i <= 26) && (i % 9 == 0 || i % 9 == 8)))
			{
				all_terminals = 0;
				break;
			}
		}
		if (all_terminals)
		{
			yaku_flag[8] = 1;
			yakuman++;
			ptf("    All terminals (1 Yakuman)\n");
		}
	}
	// Big three dragons 大三元
	{
		int8_t big_three_dragons = 0;
		for (int32_t i = 0; i < 3; i++)
		{
			if (cards_count[31 + i] == 3 || cards_count[31 + i] == 4)
			{
				big_three_dragons++;
			}
		}
		if (big_three_dragons == 3)
		{
			yaku_flag[9] = 1;
			yakuman++;
			ptf("    Big three dragons (1 Yakuman)\n");
		}
	}
	// Four concealed triplets 四暗刻
	{
		int8_t four_concealed_triplets = 0;
		if (triplets + kans == 4 && closed_hand)
		{
			four_concealed_triplets++;
		}
		if (four_concealed_triplets && yaku_flag[4] == 0)
		{
			yaku_flag[10] = 1;
			yakuman++;
			ptf("    Four concealed triplets (1 Yakuman)\n");
		}
	}
	// Four kans 四槓子
	{
		int8_t four_kans = 0;
		if (kans == 4)
		{
			four_kans++;
		}
		if (four_kans)
		{
			yaku_flag[11] = 1;
			yakuman++;
			ptf("    Four kans (1 Yakuman)\n");
		}
	}
	// Little four winds 小四喜
	{
		int8_t little_four_winds = 0;
		for (int32_t i = 0; i < 4; i++)
		{
			if (cards_count[27 + i] == 3 || cards_count[27 + i] == 4)
			{
				little_four_winds++;
			}
		}
		if (little_four_winds == 3 && pair[0] >= 28 && pair[0] <= 31) // pair didn't minuse 1
		{
			yaku_flag[12] = 1;
			yakuman++;
			ptf("    Little four winds (1 Yakuman)\n");
		}
	}
	// Nine gates 九蓮寶燈
	{
		int8_t nine_gates = 0;
		for (int32_t i = 0; i < 3; i++)
		{
			if (cards_count[i * 9])
			{
				for (int32_t j = 0; j < 9; j++)
				{
					if ((i * 9 + j) % 9 != 8 && (i * 9 + j) % 9 != 0 && cards_count[i * 9 + j] > 1)
					{
						nine_gates++;
					}

					else if (((i * 9 + j) % 9 == 8 && (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] > 3)
					{
						nine_gates++;
					}
				}
				if (nine_gates != 9)
				{
					nine_gates = 0;
				}
				else
					break;
			}
		}
		if (nine_gates == 9 && yaku_flag[5] == 0)
		{
			yaku_flag[13] = 1;
			yakuman++;
			ptf("    Nine gates (1 Yakuman)\n");
		}
	}

	if (yakuman)
	{
		return;
	}
	// Han

	// 6 Han
	// Flush 清一色 (6 or 5 Han)
	{
		int8_t flush[3] = {1, 1, 1};
		for (int32_t i = 0; i <= 33; i++)
		{
			if (cards_count[i] && i > 8)
			{
				flush[0] = 0;
			}
			if (cards_count[i] && (i > 17 || i < 9))
			{
				flush[1] = 0;
			}
			if (cards_count[i] && (i < 18 || i > 26))
			{
				flush[2] = 0;
			}
		}
		if (flush[0] || flush[1] || flush[2])
		{
			yaku_flag[14] = 1;
			if (closed_hand)
			{
				han += 6;
				ptf("    Flush (6 Han)\n");
			}
			else
			{
				han += 5;
				ptf("    Flush (5 Han)\n");
			}
		}
	}

	// 3 Han
	// Half-flush 混一色 (3 or 2 Han)
	{
		int8_t half_flush[3] = {1, 1, 1};
		for (int32_t i = 0; i <= 26; i++)
		{
			if (cards_count[i] && i > 8)
			{
				half_flush[0] = 0;
			}
			if (cards_count[i] && (i > 17 || i < 9))
			{
				half_flush[1] = 0;
			}
			if (cards_count[i] && i < 18)
			{
				half_flush[2] = 0;
			}
		}
		if (half_flush[0] || half_flush[1] || half_flush[2] && yaku_flag[14] == 0)
		{
			yaku_flag[15] = 1;
			if (closed_hand)
			{
				han += 3;
				ptf("    Half-flush (3 Han)\n");
			}
		}
	}
	// Terminal in each set 純全帶么九 (3 or 2 Han)
	{
		int8_t terminal_in_each_set = 1;
		for (int32_t i = 0; i < 4; i++)
		{
			if (!(melds[i][0] % 9 == 0 || melds[i][2] % 9 == 8))
			{
				terminal_in_each_set = 0;
				break;
			}
		}
		for (int32_t i = 0; i < 7; i++)
		{
			if (cards_count[27 + i])
			{
				terminal_in_each_set = 0;
				break;
			}
		}
		if (terminal_in_each_set && ((pair[0] % 9 == 0 || pair[0] % 9 == 8) && pair[0] < 28))
		{
			yaku_flag[16] = 1;
			if (closed_hand)
			{
				han += 3;
				ptf("    Terminal in each set (3 Han)\n");
			}
		}
	}

	// 2 Han
	// All triplets 對對和 (2 Han)
	{
		if (sequences == 0)
		{
			yaku_flag[17] = 1;
			han += 2;
			ptf("    All triplets (2 Han)\n");
		}
	}
	// All terminals and honors 混老頭 (2 Han)
	{
		int8_t all_terminals_and_honors = 1;
		for (int32_t i = 0; i <= 33; i++)
		{
			if (!(((i >= 0 && i <= 26) && (i % 9 == 0 || i % 9 == 8)) || (i >= 27 && i <= 33)))
			{
				all_terminals_and_honors = 0;
				break;
			}
		}
		if (all_terminals_and_honors)
		{
			yaku_flag[18] = 1;
			han += 2;
			ptf("    All terminals and honors (2 Han)\n");
		}
	}
	// Half-flush 混一色 (3 or 2 Han)
	{
		if (yaku_flag[15] == 1 && closed_hand == 0)
		{
			han += 2;
			ptf("    Half-flush (2 Han)\n");
		}
	}
	// Little three dragons 小三元 (2 Han)
	{
		int8_t little_three_dragons = 0;
		for (int32_t i = 0; i < 3; i++)
		{
			if (cards_count[31 + i] == 3 || cards_count[31 + i] == 4)
			{
				little_three_dragons++;
			}
		}
		if (little_three_dragons == 2 && (pair[0] >= 32 && pair[0] <= 34)) // pair didn't minuse 1
		{
			yaku_flag[19] = 1;
			han += 2;
			ptf("    Little three dragons (2 Han)\n");
		}
	}
	// Straight 一氣通貫 (2 or 1 Han)
	{
		int8_t straight[3] = {1, 1, 1};
		for (int32_t i = 0; i < 9; i++)
		{
			if (cards_count[i])
			{
				straight[0] = 0;
			}
			if (cards_count[i + 9])
			{
				straight[1] = 0;
			}
			if (cards_count[i + 18])
			{
				straight[2] = 0;
			}
		}
		if (straight[0] || straight[1] || straight[2])
		{
			yaku_flag[20] = 1;
			if (closed_hand)
			{
				han += 2;
				ptf("    Straight (2 Han)\n");
			}
		}
	}
	// Terminal in each set 純全帶么九 (3 or 2 Han)
	{
		if (yaku_flag[16] && closed_hand == 0)
		{
			han += 2;
			ptf("    Terminal in each set (2 Han)\n");
		}
	}
	// Terminal or honor in each set 混全帶九 (2 or 1 Han)
	{
		int8_t termianl_or_honor_in_each_set = 1;
		for (int32_t i = 0; i < 4; i++)
		{
			if (!(melds[i][0] % 9 == 0 || melds[i][2] % 9 == 8))
			{
				termianl_or_honor_in_each_set = 0;
				break;
			}
			else if (melds[i][0] % 9 == 0 || melds[i][2] % 9 == 8)
			{
				termianl_or_honor_in_each_set++;
			}
		}
		if (termianl_or_honor_in_each_set > 1)
		{
			termianl_or_honor_in_each_set = 1;
			for (int32_t i = 0; i < 7; i++)
			{
				if (cards_count[27 + i])
				{
					termianl_or_honor_in_each_set++;
					break;
				}
			}
		}
		if (termianl_or_honor_in_each_set == 2)
		{
			yaku_flag[21] = 1;
			if (closed_hand)
			{
				han += 3;
				ptf("    Terminal in each set (3 Han)\n");
			}
		}
	}
	// Three colour triplets 三色同刻 (2 Han)
	{
		int8_t three_colour_triplets[3] = {0};
		if (triplets + kans > 3)
		{
			for (int32_t i = 0; i < 4; i++)
			{
				if (melds[i][0] == melds[i][1] && melds[i][0] < 28)
				{
					three_colour_triplets[(melds[i][0] - 1) / 9]++;
				}
			}
		}
		if (three_colour_triplets[0] && three_colour_triplets[1] && three_colour_triplets[2])
		{
			yaku_flag[22] = 1;
			han += 2;
			ptf("    Three colour triplets (2 Han)\n");
		}
	}
	// Three colour straights 三色同順 (2 or Han)
	{
		int8_t three_colour_straights = 0;
		int8_t three_colour_straights_count[4] = {0};
		int8_t color[3] = {0};
		int8_t num = -1;
		if (sequences >= 3)
		{
			for (int32_t i = 0; i < 4; i++)
			{
				if (melds[i][0] + 1 == melds[i][1] && melds[i][0] < 28)
				{
					three_colour_straights_count[i] = melds[i][0];
					color[(melds[i][0] - 1) / 9]++;
				}
			}
		}
		if (color[0] && color[1] && color[2])
		{
			int8_t counter[9] = {0};
			for (int32_t i = 0; i < 4; i++)
			{
				if (three_colour_straights_count[i])
				{
					counter[(three_colour_straights_count[i] - 1) % 9]++;
				}
			}
			for (int32_t i = 0; i < 9; i++)
			{
				if (counter[i] >= 3)
				{
					three_colour_straights = 1;
					break;
				}
			}
		}
		if (three_colour_straights)
		{
			yaku_flag[23] = 1;
			han += 2;
			ptf("    Three colour straights (2 Han)\n");
		}
	}
	// Three kans 三槓子 (2 Han)
	{
		if (kans == 3)
		{
			yaku_flag[24] = 1;
			han += 2;
			ptf("    Three kans (2 Han)\n");
		}
	}
	// Two sets of identical sequences 二盃口 (2 Han)
	{
		if (sequences == 4)
		{
			int8_t two_sets_of_identical_sequences = 0;
			for (int32_t i = 0; i < 34; i++)
			{
				if (cards_count[i] == 2)
				{
					two_sets_of_identical_sequences++;
				}
			}
			if (two_sets_of_identical_sequences == 7 && closed_hand)
			{
				yaku_flag[25] = 1;
				han += 2;
				ptf("    Two sets of identical sequences (2 Han)\n");
			}
		}
	}

	// 1 Han
	// All simples 斷么九 (1 Han)
	{
		int8_t all_simples = 1;
		for (int32_t i = 0; i <= 33; i++)
		{
			if (cards_count[i] && (i % 9 == 0 || i % 9 == 8 || i > 26))
			{
				all_simples = 0;
				break;
			}
		}
		if (all_simples)
		{
			yaku_flag[26] = 1;
			han++;
			ptf("    All simples (1 Han)\n");
		}
	}
	// No-points hand 平和 (1 Han) **********
	{
		if (sequences == 4)
		{
			int8_t no_points_hand = 1;
			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] && i > 26)
				{
					no_points_hand = 0;
					break;
				}
			}
			int8_t winning_tile_flag = 0;
			for (int32_t i = 0; i < 4; i++)
			{
				if (melds[i][0] == winning_tile || melds[i][2] == winning_tile)
				{
					winning_tile_flag++;
					break;
				}
			}
			if (no_points_hand && closed_hand && winning_tile_flag)
			{
				yaku_flag[27] = 1;
				han++;
				ptf("    No-points hand (1 Han)\n");
			}
		}
	}
	// One set of identical sequences 一盃口 (1 Han)
	{
		if (sequences == 4)
		{
			int8_t one_set_of_identical_sequences = 0;
			int8_t counter[27] = {0};
			for (int32_t i = 0; i < 4; i++)
			{
				if (melds[i][0] + 1 == melds[i][1] && melds[i][2] < 27)
				{
					counter[melds[i][0] - 1]++;
				}
			}
			for (int32_t i = 0; i < 27; i++)
			{
				if (counter[i] >= 2)
				{
					one_set_of_identical_sequences = 1;
					break;
				}
			}
			if (one_set_of_identical_sequences && yaku_flag[25] == 0)
			{
				yaku_flag[28] = 1;
				han++;
				ptf("    One set of identical sequences (1 Han)\n");
			}
		}
	}
	// Honors(役牌)**********
	//  tiles of White(白) or Green(發) or Red(中)
	{
		if (cards_count[31] == 3 || cards_count[32] == 3 || cards_count[33] == 3)
		{
			yaku_flag[29] = 1;
			han++;
			if (cards_count[31] == 3)
			{
				ptf("    Honors: White (1 Han)\n");
			}
			else if (cards_count[32] == 3)
			{
				ptf("    Honors: Green (1 Han)\n");
			}
			else if (cards_count[33] == 3)
			{
				ptf("    Honors: Red (1 Han)\n");
			}
		}
	}
	// Player’s wind of East(東風) South(南風) West(西風) North(北風)
	{
		if (cards_count[winning_tile - 1] == 3)
		{
			yaku_flag[29] = 1;
			han++;
			ptf("    Honors: Player's wind (1 Han)\n");
		}

		// Prevailing wind of East(東風) South(南風) West(西風) North(北風)
		{
			if (cards_count[winning_tile - 1] == 3)
			{
				yaku_flag[29] = 1;
				han++;
				ptf("    Honors: Prevailing wind (1 Han)\n");
			}
		}

		// Straight 一氣通貫 (2 or 1 Han)
		{
			if (yaku_flag[20] == 1 && closed_hand == 0)
			{
				han++;
				ptf("    Straight (1 Han)\n");
			}
		}
		// Terminal or honor in each set 混全帶九 (2 or 1 Han)
		{
			if (yaku_flag[21] == 1 && closed_hand == 0)
			{
				han++;
				ptf("    Terminal or honor in each set (1 Han)\n");
			}
		}
		// Three colour straights 三色同順 (2 or Han)
		{
			if (yaku_flag[23] == 1 && closed_hand == 0)
			{
				han++;
				ptf("    Three colour straights (1 Han)\n");
			}
		}
	}
}
// Pin: 1~9 (0~8)
// So: 10~18 (9~17)
// Wan: 19~27 (18~26)
// wind ( 東南西北 ): 28~31 (27~30)
// 白發中: 32~34 (31~33)

/*
0// Thirteen orphans 13 wait [*]
1// Thirteen orphans [*]
2// Seven pairs (no Two sets of identical sequences)(Closed hands only) [*]

2 Yakuman

3// Big four winds
4// Four concealed triplets single wait
5// Nine gates nine wait
//// Thirteen orphans 13 wait [*]

1 Yakuman

6// All green
7// All honors
8// All terminals
9// Big three dragons
10// Four concealed triplets
11// Four kans
12// Little four winds
13// Nine gates
//// Thirteen orphans [*]

6 Han

14// Flush (no open group)

5 Han

14// Flush (have open group)

3 Han

15// Half-flush (no open group)
16// Terminal in each set (no open group)

2 Han

17// All triplets
18// All terminals and honors
15// Half-flush (have open group)
19// Little three dragons
//// Seven pairs (no Two sets of identical sequences)(Closed hands only) [*]
20// Straight (no open group)(Closed hands only)
16// Terminal in each set (have open group)
21// Terminal or honor in each set (no open group)
22// Three colour triplets
23// Three colour straights (no open group)(Closed hands only)
24// Three kans
25// Two sets of identical sequences (Closed hands only)

1 Han

26// All simples
27// No-points hand (Closed hands only)
28// One set of identical sequences (Closed hands only)
29//Honor(役牌)
	tiles of White(白) or Green(發) or Red(中)
	Player’s wind of East(東風) South(南風) West(西風) North(北風)
	Prevailing wind of East(東風) South(南風) West(西風) North(北風)
20// Straight (have open group)(Closed hand only)
21// Terminal or honor in each set (have open group)
23// Three colour straights (have opne group)


*/