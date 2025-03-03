/*
Problem: 15652
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void duplicateSequence(int index, int start);

int N, M;
int board[8] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	duplicateSequence(0, 1);

	return 0;
}

void duplicateSequence(int index, int start)
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
		for (i = start; i <= N; i++)
		{
			board[index] = i;
			duplicateSequence(index + 1, i);
		}
	}
}
