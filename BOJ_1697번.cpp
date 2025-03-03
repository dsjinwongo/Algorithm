/*
Problem: 1697
Solver: Jinwon
Reference: https://chanhuiseok.github.io/posts/baek-14/
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

	int N, K, i, count, index;
	queue<pair<int,int>> que;
	bool visited[100001] = { false };

	cin >> N >> K;

	count = -1;
	que.push({ N,0 });
	visited[N] = true;
	while (!visited[K])
	{
		index = que.front().first;
		count = que.front().second;

		if (index > 0 && !visited[index - 1])
		{
			que.push({ index - 1, count + 1 });
			visited[index - 1] = true;
		}
		if (index < K && !visited[index + 1])
		{
			que.push({ index + 1, count + 1 });
			visited[index + 1] = true;
		}
		if (index * 2 < 100001 && !visited[index * 2])
		{
			que.push({ index * 2, count + 1 });
			visited[index * 2] = true;
		}

		que.pop();
	}
	cout << count + 1;

	return 0;
}