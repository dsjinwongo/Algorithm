/*
Problem: 9095
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int n);

int board[12] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n, i;

	board[1] = 1;
	board[2] = 2;
	board[3] = 4;
	board[4] = 7;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> n;
		cout << find(n) << "\n";
	}

	return 0;
}

int find(int n)
{
	if (board[n] == 0)
		board[n] = find(n - 1) + find(n - 2) + find(n - 3);

	return board[n];
}