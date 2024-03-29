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
static int32_t winning_tile = 0, player_wind = 0, prevailing_wind = 0;
static int32_t special_case = 0, closed_hand = 1;
static int8_t open_hand_meld[4] = {0};
static int32_t triplets = 0, kans = 0, sequences = 0; // 3 4 3
static int32_t melds_kind[4] = {0};
static int32_t han = 0, yakuman = 0;
static int8_t yaku_flag[31] = {0};

static void bubble_sort(int32_t *array, uint64_t size);
static void count_yaku();

int main()
{
	ptf("Please input meld: ");
	int32_t inp = 0;
	int32_t inp_count = 0, meld_count = 0;
	int8_t unresonable = 0;
	static int32_t meld_inp[14] = {0};
	int32_t errinp = 0;

	scanf("%d", &inp);
	// inp_count++;
	while (inp_count < 13 && inp)
	{
		if (inp > 34 || inp < 0)
		{
			// fprintf(stderr, "inp: %d\n", inp);
			goto unresonable_case;
		}
		meld_inp[inp_count] = inp;
		scanf("%d", &inp);
		inp_count++;
	}

	if (inp_count == 13)
	{
		meld_inp[inp_count] = inp;
		scanf("%d", &inp);

		if (inp)
		{
			// fprintf(stderr, "inp: %d\n", inp);
			goto unresonable_case;
		}
	}
	scanf("%*[^\n]%n", &errinp);
	if (errinp)
	{
		// fprintf(stderr, "errinp: %d\n", errinp);
		goto unresonable_case;
	}
	if (inp_count == 13)
	{
		special_case = 1;
		bubble_sort(meld_inp, 14); ////
		for (int32_t i = 0; i < 14; i++)
		{
			cards_count[meld_inp[i] - 1]++;
			if(cards_count[meld_inp[i] - 1] > 4)
			{
				// fprintf(stderr, "cards_count[%d]: %d\n", meld_inp[i] - 1, cards_count[meld_inp[i] - 1]);
				goto unresonable_case;
			}
		}
		int8_t checker = 0;
		// checker
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
					thirteen_orphans_flag = i * 9 + 1;
				}
				if (cards_count[(i + 1) * 9 - 1] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[(i + 1) * 9 - 1] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = (i + 1) * 9;
				}
				if (cards_count[27 + i] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[27 + i] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = 27 + i + 1;
				}
				if (cards_count[31 + i] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[31 + i] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = 31 + i + 1;
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
				checker = 1;
			}
		// Seven pairs
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
				checker = 1;
			}
		}
		if (checker==0)
		{
			// fprintf(stderr, "checker: %d\n", checker);
			goto unresonable_case;
		}
	}
	else
	{
		if (inp_count < 3 || inp_count > 4)
		{
			// fprintf(stderr, "inp_count: %d\n", inp_count);
			goto unresonable_case;
		}
		bubble_sort(meld_inp, inp_count);
		int32_t is_same = 1, is_straight = 1;
		for (int32_t i = 0; i < inp_count; i++)
		{
			cards_count[meld_inp[i] - 1]++;
			if (cards_count[meld_inp[i] - 1] > 4)
			{
				goto unresonable_case;
			}
			melds[0][i] = meld_inp[i];
			if (i > 0 && ((meld_inp[i] != meld_inp[i - 1] + 1) || ((meld_inp[i] - 1) / 9 != (meld_inp[i - 1] - 1) / 9)) || meld_inp[i] > 27)
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
			// fprintf(stderr, "is_same: %d is_straight: %d\n", is_same, is_straight);
			goto unresonable_case;
		}
		if (is_straight && inp_count == 4)
		{
			// fprintf(stderr, "is_straight: %d inp_count: %d\n", is_straight, inp_count);
			goto unresonable_case;
		}
		if (is_same && inp_count == 3)
		{
			melds_kind[0] = 1;
			triplets++;
		}
		if (is_same && inp_count == 4)
		{
			melds_kind[0] = 2;
			kans++;
		}
		if (is_straight && inp_count == 3)
		{
			melds_kind[0] = 3;
			sequences++;
		}
		ptf("Is open group(1: YES 0: NO): ");
		int32_t inp_hand = 0;
		scanf("%d", &inp_hand);
		if (inp_hand > 1 || inp_hand < 0)
		{
			// fprintf(stderr, "inp_hand: %d\n", inp_hand);
			goto unresonable_case;
		}
		if (inp_hand)
		{
			open_hand_meld[0] = 1;
			closed_hand = 0;
		}

		meld_count++;
		for (int32_t i = 1; i < 4; i++)
		{
			is_same = 1, is_straight = 1;
			inp_count = 0;
			ptf("Please input meld: ");
			scanf("%d", &inp);
			while (inp && inp_count < 4)
			{
				if (inp > 34 || inp < 0)
				{
					// fprintf(stderr, "%d inp: %d\n", i, inp);
					goto unresonable_case;
				}
				meld_inp[inp_count] = inp;

				scanf("%d", &inp);
				inp_count++;
			}
			scanf("%*[^\n]%n", &errinp);
			if (errinp)
			{
				// fprintf(stderr, "%d errinp: %d\n", i, errinp);
				goto unresonable_case;
			}
			if (inp_count < 3 || inp_count > 4)
			{
				// fprintf(stderr, "%d inp_count: %d\n", i, inp_count);
				goto unresonable_case;
			}
			bubble_sort(meld_inp, inp_count);
			for (int32_t j = 0; j < inp_count; j++)
			{
				cards_count[meld_inp[j] - 1]++;
				if (cards_count[meld_inp[j] - 1] > 4)
				{
					// fprintf(stderr, "%d cards_count[%d]: %d\n", i, meld_inp[j] - 1, cards_count[meld_inp[j] - 1]);
					goto unresonable_case;
				}
				melds[i][j] = meld_inp[j];
				if ((j > 0 && (meld_inp[j] != meld_inp[j - 1] + 1 || (meld_inp[j] - 1) / 9 != (meld_inp[j - 1] - 1) / 9)) || meld_inp[j] > 27)
				{
					is_straight = 0;
				}
				if (j > 0 && meld_inp[j] != meld_inp[j - 1])
				{
					is_same = 0;
				}
			}
			if (!(is_same || is_straight))
			{
				// fprintf(stderr, "%d is_same: %d is_straight: %d\n", i, is_same, is_straight);
				goto unresonable_case;
			}
			if (is_straight && inp_count == 4)
			{
				// fprintf(stderr, "%d is_straight: %d inp_count: %d\n", i, is_straight, inp_count);
				goto unresonable_case;
			}
			if (is_same && inp_count == 3)
			{
				melds_kind[i] = 1;
				triplets++;
			}
			if (is_same && inp_count == 4)
			{
				melds_kind[i] = 2;
				kans++;
			}
			if (is_straight && inp_count == 3)
			{
				melds_kind[i] = 3;
				sequences++;
			}
			ptf("Is open group(1: YES 0: NO): ");
			scanf("%d", &inp_hand);
			if (inp_hand > 1 || inp_hand < 0)
			{
				// fprintf(stderr, "%d inp_hand: %d\n", i, inp_hand);
				goto unresonable_case;
			}
			if (inp_hand)
			{
				closed_hand = 0;
				open_hand_meld[i] = 1;
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
				// fprintf(stderr, "inp_pair: %d\n", inp_pair);
				goto unresonable_case;
			}
			cards_count[inp_pair - 1]++;
			pair[i] = inp_pair;
			// inp_count++;
		}
		scanf("%*[^\n]%n", &errinp);
		if (errinp)
		{
			// fprintf(stderr, "errinp: %d\n", errinp);
			goto unresonable_case;
		}
		if (pair[0] != pair[1])
		{
			// fprintf(stderr, "pair[0]: %d pair[1]: %d\n", pair[0], pair[1]);
			goto unresonable_case;
		}
	}

	for (int32_t i = 0; i < 33; i++)
	{
		if (cards_count[i] > 4)
		{
			// fprintf(stderr, "cards_count[%d]: %d\n", i, cards_count[i]);
			goto unresonable_case;
		}
	}
	ptf("Please input winning tile: "); //
	scanf("%d", &winning_tile);
	if (cards_count[winning_tile - 1] == 0)
	{
		// fprintf(stderr, "winning_tile: %d %d\n", winning_tile, cards_count[winning_tile - 1]);
		goto unresonable_case;
	}
	if (!special_case)
	{
		for (int32_t i = 0; i < 4; i++)
		{
			if (melds_kind[i] == 2)

				if (melds[i][0] == winning_tile)
				{
					// fprintf(stderr, "melds[%d][0],kind: %d %d\n", i, melds[i][0], melds_kind[i]);
					goto unresonable_case;
					break;
				}
		}
	}
	/* self drwan win
	ptf("Is Self-drawn win?(1: YES 0: NO): "); //
	scanf("%d", &self_drawn_win);
	if (self_drawn_win > 1 || self_drawn_win < 0)
	{
		// fprintf(stderr, "self_drawn_win: %d\n", self_drawn_win);
		goto unresonable_case;
	}

	if (!special_case && unresonable == 0)
	{
		if (self_drawn_win)
		{
			if (cards_count[winning_tile - 1] == 1)
			{
				for (int32_t i = 0; i < 4; i++)
				{
					for (int32_t j = 0; j < 3; j++)
					{
						if (melds[i][j] == winning_tile && open_hand_meld[i] == 1)
						{
							// fprintf(stderr, "melds[%d][%d]: %d\n", i, j, melds[i][j]);
							goto unresonable_case;
						}
					}
				}
			}
			else
			{
				int8_t flag[4] = {0};
				int8_t flag_count = 0;
				for (int32_t i = 0; i < 4; i++)
				{
					for (int32_t j = 0; j < 3; j++)
					{
						if (melds[i][j] == winning_tile)
						{
							if (melds_kind[i] == 2)
							{
								// fprintf(stderr, "melds_kind[%d]: %d\n", i, melds_kind[i]);
								goto unresonable_case;
								break;
							}
							flag[i] = 1;
							flag_count++;
							break;
						}
					}
				}
				if (flag_count == 1)
				{
					for (int32_t i = 0; i < 4; i++)
					{
						if (flag[i] == 1)
						{
							if (open_hand_meld[i] == 1)
							{
								// fprintf(stderr, "melds %d\n", i);
								goto unresonable_case;
								break;
							}
						}
					}
				}
			}
		}
	}*/
	ptf("Player's wind(0:E 1:S 2:W 3:N): "); //
	scanf("%d", &player_wind);
	if (player_wind > 3 || player_wind < 0)
	{
		// fprintf(stderr, "player_wind: %d\n", player_wind);
		goto unresonable_case;
	}
	ptf("Prevailing wind(0:E 1:S 2:W 3:N): "); //
	scanf("%d", &prevailing_wind);
	if (prevailing_wind > 3 || prevailing_wind < 0)
	{
		// fprintf(stderr, "prevailing_wind: %d\n", prevailing_wind);
		goto unresonable_case;
	}
	// if (unresonable)
	// {
	// 	goto unresonable_case;
	// }
	// unresonable case
	ptf("\nThe Score is...\n");
	count_yaku();
	if (yakuman + han == 0 && special_case)
	{
		ptf("    Unreasonable case\n");
	}
	else if (yakuman + han == 0)
	{
		ptf("    No Yaku\n");
	}
	ptf("Total: ");

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
		else
		{
			ptf("%d Han\n", han);
		}
	}
	if (0)
	{
	unresonable_case:
		ptf("\nThe Score is...\n    Unreasonable case\nTotal: 0 Han\n");
		return 1;
	}

	return 0;
}
static void bubble_sort(int32_t *array, uint64_t size)
{
	if (array == NULL)
	{
		return;
	}
	for (uint64_t i = 0; i < size; i++)
	{
		for (uint64_t j = 0; j < size - i - 1; j++)
		{
			if (*(array + j) > *(array + j + 1))
			{
				int32_t temp = *(array + j);
				*(array + j) = *(array + j + 1);
				*(array + j + 1) = temp;
			}
		}
	}
	return;
}

static void count_yaku()
{
	if (special_case)
	{
		// Thirteen orphans (Two kinds)
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
					thirteen_orphans_flag = i * 9 + 1;
				}
				if (cards_count[(i + 1) * 9 - 1] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[(i + 1) * 9 - 1] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = (i + 1) * 9;
				}
				if (cards_count[27 + i] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[27 + i] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = 27 + i + 1;
				}
				if (cards_count[31 + i] == 1)
				{
					thirteen_orphans++;
				}
				else if (cards_count[31 + i] == 2 && !thirteen_orphans_flag)
				{
					thirteen_orphans++;
					thirteen_orphans_flag = 31 + i + 1;
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
				if (winning_tile == thirteen_orphans_flag) // Thirteen orphans 13 wait
				{
					yaku_flag[0] = 1;
					yakuman += 2;
					ptf("    Thirteen orphans 13 wait (2 Yakuman)\n");
					return;
				}
				else // Thirteen orphans
				{
					yaku_flag[1] = 1;
					yakuman++;
					ptf("    Thirteen orphans (1 Yakuman)\n");
					return;
				}
			}
		}
		// Seven pairs
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
				// ptf("    Seven pairs (2 Han)\n");
				// return;
			}

			if (yaku_flag[2])
			{
				// All honors
				{
					int8_t all_honors = 1;
					for (int32_t i = 0; i <= 33; i++)
					{
						if (cards_count[i] && i < 27)
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
						return;
					}
				}
				// Flush (6 Han)
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
						han += 6;
						ptf("    Flush (6 Han)\n");
					}
				}
				// Half-flush (3 Han)
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
					if ((half_flush[0] || half_flush[1] || half_flush[2]) && yaku_flag[14] == 0)
					{
						yaku_flag[15] = 1;
						han += 3;
						ptf("    Half-flush (3 Han)\n");
					}
				}
				// All terminals and honors (2 Han)
				{
					int8_t all_terminals_and_honors = 1;
					for (int32_t i = 0; i <= 33; i++)
					{
						if (cards_count[i] && !(((i >= 0 && i <= 26) && (i % 9 == 0 || i % 9 == 8)) || (i >= 27 && i <= 33)))
						{
							all_terminals_and_honors = 0;
							break;
						}
					}
					if (all_terminals_and_honors)
					{
						yaku_flag[19] = 1;
						han += 2;
						ptf("    All terminals and honors (2 Han)\n");
					}
				}
				// Seven pairs (2 Han)
				ptf("    Seven pairs (2 Han)\n");
				// All simples (1 Han)
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
						yaku_flag[27] = 1;
						han++;
						ptf("    All simples (1 Han)\n");
					}
				}
			}
		}
	}
	else
	{
		// 2 Yakuman
		// Big four winds
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
		// Four concealed triplets single wait
		{
			int8_t four_concealed_triplets_single_wait = 0;
			if (triplets + kans == 4 && closed_hand && winning_tile == pair[0])
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
		// Nine gates nine wait
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
							else if (((i * 9 + j) % 9 == 8 || (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] == 3)
							{
								nine_gates_nine_wait++;
							}
							else if (((i * 9 + j) % 9 == 8 || (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] == 4 && nine_gates_nine_wait_flag == -1)
							{
								nine_gates_nine_wait_flag = i * 9 + j + 1;
								nine_gates_nine_wait++;
							}
						}
						if (nine_gates_nine_wait != 9)
						{
							nine_gates_nine_wait = 0;
							nine_gates_nine_wait_flag = -1;
						}
						else
							break;
					}
				}
				if (nine_gates_nine_wait_flag == winning_tile && nine_gates_nine_wait == 9 && closed_hand)
				{
					yaku_flag[5] = 1;
					yakuman += 2;
					ptf("    Nine gates nine wait (2 Yakuman)\n");
				}
			}
		}

		// 1 Yakuman
		// All green
		{
			int8_t all_green = 1;
			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] && !((i >= 9 && i <= 17 && (i % 2 == 0 || i == 11)) || i == 32))
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
		// All honors
		{
			int8_t all_honors = 1;
			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] && i < 27)
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
		// All terminals
		{
			int8_t all_terminals = 1;
			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] && (i > 26 || !(i % 9 == 0 || i % 9 == 8)))
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
		// Big three dragons
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
		// Four concealed triplets
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
		// Four kans
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
		// Little four winds
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
		// Nine gates
		{
			int8_t nine_gates = 0;
			for (int32_t i = 0; i < 3; i++)
			{
				if (cards_count[i * 9])
				{
					for (int32_t j = 0; j < 9; j++)
					{
						if ((i * 9 + j) % 9 != 8 && (i * 9 + j) % 9 != 0 && cards_count[i * 9 + j] >= 1)
						{
							nine_gates++;
						}

						else if (((i * 9 + j) % 9 == 8 || (i * 9 + j) % 9 == 0) && cards_count[i * 9 + j] >= 3)
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
			if (nine_gates == 9 && yaku_flag[5] == 0 && closed_hand)
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
		// Flush (6 or 5 Han)
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
		// Half-flush (3 or 2 Han)
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
			if ((half_flush[0] || half_flush[1] || half_flush[2]) && yaku_flag[14] == 0)
			{
				yaku_flag[15] = 1;
				if (closed_hand)
				{
					han += 3;
					ptf("    Half-flush (3 Han)\n");
				}
			}
		}
		// Terminal in each set (3 or 2 Han)
		{
			int8_t terminal_in_each_set = 1;
			for (int32_t i = 0; i < 4; i++)
			{
				if (!((melds[i][0] - 1) % 9 == 0 || (melds[i][2] - 1) % 9 == 8))
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
			if (terminal_in_each_set && (((pair[0] - 1) % 9 == 0 || (pair[0] - 1) % 9 == 8) && pair[0] < 28))
			{
				yaku_flag[16] = 1;
				if (closed_hand)
				{
					han += 3;
					ptf("    Terminal in each set (3 Han)\n");
				}
			}
		}
		// Two sets of identical sequences (3 Han)
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
					else if (cards_count[i] == 4)
					{
						two_sets_of_identical_sequences += 2;
					}
				}
				if (two_sets_of_identical_sequences == 7 && closed_hand)
				{
					yaku_flag[17] = 1;
					han += 3;
					ptf("    Two sets of identical sequences (3 Han)\n");
				}
			}
		}
		// 2 Han
		// All terminals and honors (2 Han)
		{
			int8_t all_terminals_and_honors = 1;
			for (int32_t i = 0; i <= 33; i++)
			{
				if (cards_count[i] && !(((i >= 0 && i <= 26) && (i % 9 == 0 || i % 9 == 8)) || (i >= 27 && i <= 33)))
				{
					all_terminals_and_honors = 0;
					break;
				}
			}
			if (all_terminals_and_honors)
			{
				yaku_flag[19] = 1;
				han += 2;
				ptf("    All terminals and honors (2 Han)\n");
			}
		}
		// All triplets (2 Han)
		{
			if (sequences == 0)
			{
				yaku_flag[18] = 1;
				han += 2;
				ptf("    All triplets (2 Han)\n");
			}
		}

		// Half-flush (3 or 2 Han)
		{
			if (yaku_flag[15] == 1 && closed_hand == 0)
			{
				han += 2;
				ptf("    Half-flush (2 Han)\n");
			}
		}
		// Little three dragons (2 Han)
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
				yaku_flag[20] = 1;
				han += 2;
				ptf("    Little three dragons (2 Han)\n");
			}
		}
		// Straight (2 or 1 Han)
		{
			int8_t straight[3] = {1, 1, 1};
			for (int32_t i = 0; i < 9; i++)
			{
				if (cards_count[i] == 0)
				{
					straight[0] = 0;
				}
				if (cards_count[i + 9] == 0)
				{
					straight[1] = 0;
				}
				if (cards_count[i + 18] == 0)
				{
					straight[2] = 0;
				}
			}
			if (straight[0] || straight[1] || straight[2])
			{
				yaku_flag[21] = 1;
				if (closed_hand)
				{
					han += 2;
					ptf("    Straight (2 Han)\n");
				}
			}
		}
		// Terminal in each set (3 or 2 Han)
		{
			if (yaku_flag[16] && closed_hand == 0)
			{
				han += 2;
				ptf("    Terminal in each set (2 Han)\n");
			}
		}
		// Terminal or honor in each set (2 or 1 Han)
		{
			int8_t termianl_or_honor_in_each_set = 1;
			for (int32_t i = 0; i < 4; i++)
			{
				if (!((melds[i][0] - 1) % 9 == 0 || (melds[i][2] - 1) % 9 == 8 || melds[i][0] > 27))
				{
					termianl_or_honor_in_each_set = 0;
					break;
				}
				// else if ((melds[i][0] - 1) % 9 == 0 || (melds[i][2] - 1) % 9 == 8 || melds[i][0] > 27)
				// {
				// 	termianl_or_honor_in_each_set++;
				// }
			}
			if (!(pair[0] > 27 || (pair[0] - 1) % 9 == 0 || (pair[0] - 1) % 9 == 8))
			{
				termianl_or_honor_in_each_set = 0;
			}
			// if (termianl_or_honor_in_each_set > 1)
			// {
			// 	// termianl_or_honor_in_each_set = 1;
			// 	for (int32_t i = 0; i < ; i++)
			// 	{

			// 	}
			// }
			if (termianl_or_honor_in_each_set && yaku_flag[16] == 0 && yaku_flag[19] == 0)
			{
				yaku_flag[22] = 1;
				if (closed_hand)
				{
					han += 3;
					ptf("    Terminal or honor in each set (2 Han)\n");
				}
			}
		}
		// Three colour triplets (2 Han)
		{
			int8_t three_colour_triplets[3][9] = {0};
			int8_t three_colour_triplets_flag = 0;
			if (triplets + kans >= 3)
			{
				for (int32_t i = 0; i < 4; i++)
				{
					if (melds_kind[i] < 3 && melds[i][0] < 28)
					{
						three_colour_triplets[(melds[i][0] - 1) / 9][(melds[i][0] - 1) % 9]++;
					}
				}
			}
			for (int32_t i = 0; i < 9; i++)
			{
				if (three_colour_triplets[0][i] && three_colour_triplets[1][i] && three_colour_triplets[2][i])
				{
					three_colour_triplets_flag++;
					break;
				}
			}
			if (three_colour_triplets_flag)
			{
				yaku_flag[23] = 1;
				han += 2;
				ptf("    Three colour triplets (2 Han)\n");
			}
		}
		// Three colour straights (2 or Han)
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
				yaku_flag[24] = 1;
				han += 2;
				ptf("    Three colour straights (2 Han)\n");
			}
		}
		// Three concealed triplets (2 Han)
		{
			int8_t three_concealed_triplets = 0;
			if (triplets + kans == 3 && closed_hand)
			{
				three_concealed_triplets = 3;
			}
			else if (triplets + kans == 4)
			{
				for (int32_t i = 0; i < 4; i++)
				{
					if (melds[i][0] == melds[i][1] && open_hand_meld[i] == 0)
					{
						three_concealed_triplets++;
					}
				}
			}
			if (three_concealed_triplets == 3 && yaku_flag[4] == 0)
			{
				yaku_flag[25] = 1;
				han += 2;
				ptf("    Three concealed triplets (2 Han)\n");
			}
		}

		// Three kans (2 Han)
		{
			if (kans == 3)
			{
				yaku_flag[26] = 1;
				han += 2;
				ptf("    Three kans (2 Han)\n");
			}
		}

		// 1 Han
		// All simples (1 Han)
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
				yaku_flag[27] = 1;
				han++;
				ptf("    All simples (1 Han)\n");
			}
		}
		// No-points hand (1 Han) **********
		{
			if (sequences == 4)
			{
				int8_t no_points_hand = 1;
				for (int32_t i = 0; i <= 33; i++)
				{
					if (cards_count[i] && (i == prevailing_wind + 26 || i == player_wind + 26 || i > 30))
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
					yaku_flag[28] = 1;
					han++;
					ptf("    No-points hand (1 Han)\n");
				}
			}
		}
		// One set of identical sequences (1 Han)
		{
			if (sequences >= 2)
			{
				int8_t one_set_of_identical_sequences = 0;
				int8_t counter[27] = {0};
				for (int32_t i = 0; i < 4; i++)
				{
					if (melds_kind[i] == 3)
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
				if (one_set_of_identical_sequences && yaku_flag[17] == 0)
				{
					yaku_flag[29] = 1;
					han++;
					ptf("    One set of identical sequences (1 Han)\n");
				}
			}
		}
		// Honer**********
		//  tiles of White or Green or Red
		{

			if (cards_count[32] >= 3)
			{
				yaku_flag[30] = 1;
				han++;
				ptf("    Honer: Green (1 Han)\n");
			}

			// Player’s wind of East South West North

			if (cards_count[27 + player_wind] >= 3)
			{
				yaku_flag[30] = 1;
				han++;
				ptf("    Honer: Player's wind (1 Han)\n");
			}

			// Prevailing wind of East South West North
			{
				if (cards_count[27 + prevailing_wind] >= 3)
				{
					yaku_flag[30] = 1;
					han++;
					ptf("    Honer: Prevailing wind (1 Han)\n");
				}
			}
			if (cards_count[33] >= 3)
			{
				yaku_flag[30] = 1;
				han++;
				ptf("    Honer: Red (1 Han)\n");
			}
			if (cards_count[31] >= 3)
			{
				yaku_flag[30] = 1;
				han++;
				ptf("    Honer: White (1 Han)\n");
			}
		}
		// Straight (2 or 1 Han)
		{
			if (yaku_flag[21] == 1 && closed_hand == 0)
			{
				han++;
				ptf("    Straight (1 Han)\n");
			}
		}
		// Terminal or honor in each set (2 or 1 Han)
		{
			if (yaku_flag[22] == 1 && closed_hand == 0)
			{
				han++;
				ptf("    Terminal or honor in each set (1 Han)\n");
			}
		}
		// Three colour straights (2 or Han)
		{
			if (yaku_flag[24] == 1 && closed_hand == 0)
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
// wind ( ESWN ): 28~31 (27~30)
// White Green Red: 32~34 (31~33)

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
17// Two sets of identical sequences (Closed hands only)

2 Han


18// All terminals and honors
19// All triplets
15// Half-flush (have open group)
20// Little three dragons
//// Seven pairs (no Two sets of identical sequences)(Closed hands only) [*]
21// Straight (no open group)(Closed hands only)
16// Terminal in each set (have open group)
22// Terminal or honor in each set (no open group)
23// Three colour triplets
24// Three colour straights (no open group)(Closed hands only)
25// Three concealed triplets
26// Three kans


1 Han

27// All simples
28// No-points hand (Closed hands only)
29// One set of identical sequences (Closed hands only)
30// Honor
	tiles of White or Green or Red
	Player’s wind of East South West North
	Prevailing wind of East South West North
21// Straight (have open group)(Closed hand only)
22// Terminal or honor in each set (have open group)
24// Three colour straights (have opne group)


*/