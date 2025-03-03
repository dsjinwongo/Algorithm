/*
* Problem: 13549
* Solver: Jinwon
* Reference: https://jdselectron.tistory.com/58
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int BFS();

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
int board[100001] = { 0 };
bool visited[100001] = { false };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	pque.push({ 0, N });
	visited[N] = true;

	cout << BFS();

	return 0;
}

int BFS()
{
	int time, index;

	while (!pque.empty())
	{
		time = pque.top().first;
		index = pque.top().second;

		pque.pop();

		if (index == K)
			return time;

		if (index < K)
		{
			if (index * 2 < 100001 && !visited[index * 2])
			{
				pque.push({ time, index * 2 });
				visited[index * 2] = true;
			}

			if (!visited[index + 1])
			{
				pque.push({ time + 1, index + 1 });
				visited[index + 1] = true;
			}
		}

		if (index > 0 && !visited[index - 1])
		{
			pque.push({ time + 1, index - 1 });
			visited[index - 1] = true;
		}
	}
}