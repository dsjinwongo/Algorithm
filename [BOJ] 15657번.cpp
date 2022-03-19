/*
* Problem: 15657
* Solver: Jinwon
* Reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void backtrack(int index, int start);

int N, M;
int board[8];
int arr[8];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	backtrack(0, 0);

	return 0;
}

void backtrack(int index, int start)
{
	int i;
	if (index == M)
	{
		for (i = 0; i < M; i++)
			cout << board[i] << " ";
		cout << "\n";
	}
	else
	{
		for (i = start; i < N; i++)
		{
			board[index] = arr[i];
			backtrack(index + 1, i);
		}
	}
}