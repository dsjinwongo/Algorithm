/*
Problem: 2579
Solver: Jinwon
Reference: https://mygumi.tistory.com/100
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(int index);

vector<int> STAIR, BOARD;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int NUM, i, successiveNum, tempOne, tempTwo, index;

	cin >> NUM;

	for (i = 0; i < NUM; i++)
	{
		cin >> tempOne;
		STAIR.push_back(tempOne);
	}

	BOARD.assign(NUM, 0);

	index = NUM - 1;

	if (index == 0)
		cout << STAIR[0];
	else if (index == 1)
		cout << STAIR[0] + STAIR[1];
	else if (index == 2)
		cout << max(STAIR[2] + STAIR[1], STAIR[2] + STAIR[0]);
	else
		cout << max(STAIR[index] + STAIR[index - 1] + dp(index - 3), STAIR[index] + dp(index - 2));

	return 0;
}

int dp(int index)
{
	if (index == 0)
		return STAIR[0];
	else if (index == 1)
		return STAIR[0] + STAIR[1];
	else if (index == 2)
		return max(STAIR[2] + STAIR[1], STAIR[2] + STAIR[0]);
	else if (BOARD[index] != 0)
		return BOARD[index];

	BOARD[index] = max(STAIR[index] + STAIR[index - 1] + dp(index - 3), STAIR[index] + dp(index - 2));

	return BOARD[index];
}