/*
Problem: 9663
Solver: Jinwon
Reference: https://chanhuiseok.github.io/posts/baek-1/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int row);
bool promising(int row, int index);

int N, num;
int board[16] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	cin >> N;

	num = 0;
	backtrack(1);

	cout << num;

	return 0;
}

void backtrack(int row)
{
	int i;
	for (i = 1; i <= N; i++)
		if (promising(row, i))
		{
			board[row] = i;

			if (row < N)
				backtrack(row + 1);
			else
				num++;
		}
}

bool promising(int row, int index)
{
	int i, colspan;
	for (i = 1; i < row; i++)
	{
		if (board[i] == index)
			return false;

		colspan = board[i] > index ? board[i] - index : index - board[i];
		if (row - i == colspan)
			return false;
	}

	return true;
}