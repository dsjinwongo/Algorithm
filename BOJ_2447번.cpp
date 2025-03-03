/*
Problem: 2447
Solver: Jinwon
Reference: https://cryptosalamander.tistory.com/38
*/

#include <iostream>
#include <vector>

using namespace std;

void countingStar(int pattern);

vector<vector<char>> board;
int num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;

	cin >> num;
	board.assign(num, vector<char>(num, '*'));

	countingStar(num);

	for (i = 0; i < num; i++)
	{
		for (j = 0; j < num; j++)
			cout << board[i][j];
		cout << "\n";
	}

	return 0;
}

void countingStar(int pattern)
{
	int i, j;
	for (i = 0; i < num; i++)
		for (j = 0; j < num; j++)
			if ((i / (num / pattern)) % 3 == 1 && (j / (num / pattern)) % 3 == 1)
				board[i][j] = ' ';

	if (pattern != 1)
		countingStar(pattern / 3);
}