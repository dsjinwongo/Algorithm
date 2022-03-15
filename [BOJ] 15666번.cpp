/*
* Problem: 15666
* Solver: Jinwon
* Reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(int index, int start);

int N, M;
int board[8] = { 0 };
int arr[8] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++)
		cin >> board[i];

	sort(board, board + N);

	backtrack(0, 0);

	return 0;
}

void backtrack(int index, int start)
{
	int i, pre = 0;

	if (index == M)
	{
		for (i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else
	{
		for (i = start; i < N; i++)
		{
			if (board[i] != pre)
			{
				arr[index] = board[i];
				backtrack(index + 1, i);
				pre = board[i];
			}
		}
	}
}