/*
Problem: 11660
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, temp, N, M;
	vector<vector<int>> board;
	pair<int, int> dot1, dot2;

	cin >> N >> M;

	board.assign(N + 1, vector<int>(N + 1, 0));
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> temp;
			board[i][j] = temp + board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1];
		}
	}

	while (M--)
	{
		cin >> dot1.first >> dot1.second >> dot2.first >> dot2.second;

		cout << board[dot2.first][dot2.second] - board[dot2.first][dot1.second - 1] - board[dot1.first - 1][dot2.second] + board[dot1.first - 1][dot1.second - 1] << "\n";
	}

	return 0;
}