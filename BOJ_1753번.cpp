/*
Problem: 1753
Solver: Jinwon
Reference: https://rujang.tistory.com/entry/%EB%B0%B1%EC%A4%80-1753%EB%B2%88-%EC%B5%9C%EB%8B%A8%EA%B2%BD%EB%A1%9C-CC
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//비교연산자
struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

void Dijkstra();

int V, E, K;
vector<pair<int, int>> board[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
int minWeight[20001] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, u, v, w;

	cin >> V >> E >> K;

	for (i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		board[u].push_back({ v,w });
	}

	pq.push({ K,0 });
	Dijkstra();

	minWeight[K] = 0;
	for (i = 1; i <= V; i++)
	{
		if (i == K)
			cout << "0\n";
		else if (minWeight[i] == 0)
			cout << "INF\n";
		else
			cout << minWeight[i] << "\n";
	}

	return 0;
}

void Dijkstra()
{
	int target, weight, node;

	while (!pq.empty())
	{
		//방문할 노드
		node = pq.top().first;

		while (!board[node].empty())
		{
			target = board[node].back().first;
			weight = minWeight[node] + board[node].back().second;

			if (minWeight[target] == 0 || minWeight[target] > weight)
				minWeight[target] = weight;

			pq.push({ target, weight });

			board[node].pop_back();
		}

		pq.pop();
	}
}