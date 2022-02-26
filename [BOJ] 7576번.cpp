/*
Problem: 7576
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int M, N, unripe;
int board[1000][1000] = { 0 };
int visited[1000][1000] = { 0 };
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };
queue<pair<int, int>> que;

void BFS();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, _max, indexX, indexY;

	cin >> M >> N;

	unripe = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 0)
				unripe++;
			else if (board[i][j] == 1)
			{
				que.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}

	_max = 0;
	while (!que.empty())
	{
		for (i = 0; i < 4; i++)
		{
			indexX = que.front().first + x[i];
			indexY = que.front().second + y[i];

			if (indexX > -1 && indexX < N && indexY>-1 && indexY < M)
			{
				if (visited[indexX][indexY] == 0 && board[indexX][indexY] == 0)
				{
					unripe--;
					board[indexX][indexY] = 1;
					que.push({ indexX, indexY });

					visited[indexX][indexY] = visited[que.front().first][que.front().second] + 1;
					//started 1 not 0
					_max = visited[indexX][indexY] - 1 > _max ? visited[indexX][indexY] - 1 : _max;

					if (unripe == 0)
					{
						cout << _max;
						return 0;
					}
				}
			}
		}
		que.pop();
	}

	if (unripe == 0)
		cout << 0;
	else
		cout << -1;

	return 0;
}