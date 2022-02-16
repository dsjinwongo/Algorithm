/*
Problem: 2178
Solver: Jinwon
Reference: https://cocoon1787.tistory.com/115
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i = 0;
	int N = 0;
	int M = 0;
	vector<string> board;
	vector<vector<int>> visited;
	vector<vector<int>> _count;
	queue<pair<int, int>> que;
	string temp;

	int indexX[4] = { 1,-1,0,0 };
	int indexY[4] = { 0,0,1,-1 };

	cin >> N >> M;

	visited.assign(N, vector<int>(M, 0));
	_count.assign(N, vector<int>(M, 0));

	for (i = 0; i < N; i++)
	{
		cin >> temp;
		board.push_back(temp);
	}

	que.push(make_pair(0, 0));
	visited[que.front().second][que.front().first] = 1;
	_count[0][0] = 1;
	while (!que.empty())
	{
		for (i = 0; i < 4; i++)
		{
			int tempx = que.front().first + indexX[i];
			int tempy = que.front().second + indexY[i];
			if (tempx > -1 && tempx < M && tempy > -1 && tempy < N)
			{
				if (board[tempy][tempx] == '1' && visited[tempy][tempx] == 0)
				{
					_count[tempy][tempx] = _count[que.front().second][que.front().first] + 1;
					que.push(make_pair(tempx, tempy));
					visited[tempy][tempx] = 1;
				}
			}
		}

		que.pop();
	}

	cout << _count[N - 1][M - 1];

	return 0;
}