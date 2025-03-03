#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void check_bingo(int check, int& bingo_num, int& bingo, int num)
{
	if (check == 1)
	{
		bingo_num++;
		if (bingo_num == 3)
			bingo = num + 1;
	}
}

int main()
{
	int bingo_board[5][5];
	int i, j, k, num, check, bingo, bingo_num;
	int* iter;
	bingo_num = 0;

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			cin >> bingo_board[i][j];

	for (i = 0; i < 25; i++)
	{
		cin >> num;
		if (bingo_num == 3)
			continue;
		iter = find(&bingo_board[0][0], &bingo_board[4][5], num);
		if (iter != &bingo_board[4][5])
			*iter = -1;
		if (i > 10)
		{
			for (j = 0; j < 5; j++)
			{
				check = 1;
				for (k = 0; k < 5; k++)
					if (bingo_board[j][k] != -1)
						check = 0;
				check_bingo(check, bingo_num, bingo, i);

				check = 1;
				for (k = 0; k < 5; k++)
					if (bingo_board[k][j] != -1)
						check = 0;
				check_bingo(check, bingo_num, bingo, i);
			}
			check = 1;
			for (k = 0; k < 5; k++)
				if (bingo_board[k][k] != -1)
					check = 0;
			check_bingo(check, bingo_num, bingo, i);

			check = 1;
			for (k = 0; k < 5; k++)
				if (bingo_board[k][4 - k] != -1)
					check = 0;
			check_bingo(check, bingo_num, bingo, i);

			if (bingo_num < 3)
				bingo_num = 0;
		}
	}
	cout << bingo;
}