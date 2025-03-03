/*
Problem: 14502
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int BFS(queue<pair<int, int>> virus);

int N, M, safeSpace, findMin = 64;
int board[8][8] = { 0 };
int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k;
	queue<pair<int, int>> virus;

	cin >> N >> M;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
				virus.push({ i,j });
			else if (board[i][j] == 0)
				safeSpace++;
		}
	}

	// 생성될 벽의 개수
	safeSpace -= 3;

	for (i = 0; i < N * M - 2; i++)
	{
		if (board[i / M][i % M] == 0)
		{
			board[i / M][i % M] = 1;
			for (j = i + 1; j < N * M - 1; j++)
			{
				if (board[j / M][j % M] == 0)
				{
					board[j / M][j % M] = 1;
					for (k = j + 1; k < N * M; k++)
					{
						if (board[k / M][k % M] == 0)
						{
							board[k / M][k % M] = 1;
							findMin = BFS(virus) < findMin ? BFS(virus) : findMin;
							board[k / M][k % M] = 0;
						}
					}
					board[j / M][j % M] = 0;
				}
			}
			board[i / M][i % M] = 0;
		}
	}

	cout << safeSpace - findMin;

	return 0;
}

int BFS(queue<pair<int, int>> virus)
{
	int i, indexX, indexY, cnt = 0;
	bool visited[8][8] = { false };

	while (!virus.empty())
	{
		for (i = 0; i < 4; i++)
		{
			indexX = virus.front().first + x[i];
			indexY = virus.front().second + y[i];
			if (indexX > -1 && indexX<N && indexY>-1 && indexY < M)
			{
				if (!visited[indexX][indexY] && board[indexX][indexY] == 0)
				{
					virus.push({ indexX, indexY });
					visited[indexX][indexY] = true;
					cnt++;
				}
			}
		}
		virus.pop();
	}

	return cnt;
}