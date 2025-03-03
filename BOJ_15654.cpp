/*
* Problem: 15654
* Solver: Jinwon
* Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void backtrack(int index);

int N, M;
int board[8] = { 0 };
int arr[8] = { 0 };
bool visitied[10001] = { false };

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

	backtrack(0);

	return 0;
}

void backtrack(int index)
{
	int i;

	if (index == M)
	{
		for (i = 0; i < M; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			if (!visitied[board[i]])
			{
				visitied[board[i]] = true;
				arr[index] = board[i];
				backtrack(index + 1);
				visitied[board[i]] = false;
			}
		}
	}
}