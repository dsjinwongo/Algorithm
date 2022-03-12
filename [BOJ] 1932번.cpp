/*
Problem: 1932
Solver: Jinwon
Reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> board[500];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j, temp;

	cin >> N;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			cin >> temp;
			board[i].push_back(temp);
		}
	}

	for (i = N - 2; i >= 0; i--)
		for (j = 0; j <= i; j++)
			board[i][j] += max(board[i+1][j], board[i+1][j + 1]);

	cout << board[0][0];

	return 0;
}