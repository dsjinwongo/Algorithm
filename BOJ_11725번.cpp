/*
Problem: 11725
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int node);

vector<int> board[1000001];
int parent[100001] = { 0 };
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, a, b;

	cin >> N;

	for (i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}

	parent[1] = 1;
	DFS(1);

	for (i = 2; i <= N; i++)
		cout << parent[i] << "\n";

	return 0;
}

void DFS(int node)
{
	while (!board[node].empty())
	{
		if (parent[board[node].back()] == 0)
		{
			parent[board[node].back()] = node;
			DFS(board[node].back());
		}

		board[node].pop_back();
	}
}