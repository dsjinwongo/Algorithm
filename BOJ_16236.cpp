/*
Problem: 16236
Solver: Jinwon
Reference: https://fjvbn2003.tistory.com/686
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int BFS(int startx, int starty);

int board[20][20] = { 0 };
int N, sharkSize, feedCount, survive;
pair<int, int> shark;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, temp;

	cin >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
				shark = { i,j };
		}

	sharkSize = 2;
	survive = 0;
	feedCount = 0;

	board[shark.first][shark.second] = 0;
	temp = BFS(shark.first, shark.second);
	//check call mom?
	while (temp != 401)
	{
		//survive time
		survive += temp;
		//eat num
		feedCount++;

		//shark evolution
		if (feedCount == sharkSize)
		{
			sharkSize++;
			feedCount = 0;
		}

		temp = BFS(shark.first, shark.second);
	}

	cout << survive;

	return 0;
}

int BFS(int startx, int starty)
{
	int y[4] = { 0,-1,0,1 };
	int x[4] = { -1,0,1,0 };
	int i;
	int visited[20][20] = { 0 };
	queue<pair<int, int>> que;
	pair<int, pair<int, int>> min;

	min = { 401, { startx,starty } };
	visited[startx][starty] = 1;
	que.push({ startx, starty });
	while (!que.empty())
	{
		int a = que.front().first;
		int b = que.front().second;
		for (i = 0; i < 4; i++)
		{
			if (a + x[i] > -1 && a + x[i]<N && b + y[i]>-1 && b + y[i] < N)
			{
				if (visited[a + x[i]][b + y[i]] == 0)
				{
					//can move?
					if (board[a + x[i]][b + y[i]] == 0 || board[a + x[i]][b + y[i]] == sharkSize)
					{
						visited[a + x[i]][b + y[i]] = visited[a][b] + 1;
						que.push({ a + x[i],b + y[i] });
					}//find prey
					else if (board[a + x[i]][b + y[i]] < sharkSize)
					{
						visited[a + x[i]][b + y[i]] = visited[a][b] + 1;
						//started 1 so return not plus 1
						if (min.first == visited[a][b])
						{
							if (min.second.first == a + x[i])
							{
								if (min.second.second > b + y[i])
									min = { visited[a][b], { a + x[i],b + y[i] } };
							}
							else if (min.second.first > a + x[i])
								min = { visited[a][b], { a + x[i],b + y[i] } };
						}
						else if(min.first > visited[a][b])
							min = { visited[a][b], { a + x[i],b + y[i] } };
					}
				}
			}
		}
		que.pop();
	}

	//change empty
	board[min.second.first][min.second.second] = 0;
	shark = min.second;

	return min.first;
}