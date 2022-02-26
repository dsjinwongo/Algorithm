/*
Problem: 11724
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int n);

int N, M;
vector<int> board[1001];
int visited[1001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, a, b, count;

	cin >> N >> M;

	for (i = 0; i < M; i++)
	{
		cin >> a >> b;
		board[a].push_back(b);
		board[b].push_back(a);
	}

	count = 0;
	for(i=1;i<=N;i++)
	{
		if (visited[i] == 0)
		{
			count++;
			visited[i] = 1;
			DFS(i);
		}
	}

	cout << count;

	return 0;
}

void DFS(int node)
{
	int temp;
	while (!board[node].empty())
	{
		temp = board[node].back();
		if (visited[temp] == 0)
		{
			visited[temp] = 1;
			DFS(temp);
		}

		board[node].pop_back();
	}
}