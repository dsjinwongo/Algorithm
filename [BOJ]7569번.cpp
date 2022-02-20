/*
Problem: 7569
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int x[6] = { 1,-1,0,0,0,0 };
int y[6] = { 0,0,1,-1,0,0 };
int z[6] = { 0,0,0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<vector<int>>> board;
	vector<vector<vector<int>>> visited;
	vector<vector<vector<int>>> days;

	int M, N, H, i, j, k, t, unriped, max;
	queue<int> quex;
	queue<int> quey;
	queue<int> quez;

	//H, N, M 순서 바꿈
	cin >> H >> N >> M;

	board.assign(M, vector<vector<int>>(N, vector<int>(H, -1)));
	visited.assign(M, vector<vector<int>>(N, vector<int>(H, 0)));
	days.assign(M, vector<vector<int>>(N, vector<int>(H, 0)));

	unriped = 0;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			for (k = 0; k < H; k++)
			{
				cin >> board[i][j][k];
				if (board[i][j][k] == 0)
					unriped++;
				else if (board[i][j][k] == 1)
				{
					quex.push(i);
					quey.push(j);
					quez.push(k);
				}
			}
		}
	}

	max = 0;

	while (!quex.empty())
	{
		if (visited[quex.front()][quey.front()][quez.front()] == 0)
		{
			visited[quex.front()][quey.front()][quez.front()] = 1;
			for (t = 0; t < 6; t++)
			{
				int indexX = quex.front() + x[t];
				int indexY = quey.front() + y[t];
				int indexZ = quez.front() + z[t];
				if (indexX > -1 && indexX < M && indexY>-1 && indexY < N && indexZ>-1 && indexZ < H)
				{
					if (board[indexX][indexY][indexZ] == 0)
					{
						board[indexX][indexY][indexZ] = 1;
						quex.push(indexX);
						quey.push(indexY);
						quez.push(indexZ);
						
						if (days[indexX][indexY][indexZ] != 0)
							days[indexX][indexY][indexZ] = days[quex.front()][quey.front()][quez.front()] + 1 < days[indexX][indexY][indexZ] ? days[quex.front()][quey.front()][quez.front()] + 1 : days[indexX][indexY][indexZ];
						else
							days[indexX][indexY][indexZ] = days[quex.front()][quey.front()][quez.front()] + 1;
						max = days[indexX][indexY][indexZ] > max ? days[indexX][indexY][indexZ] : max;

						unriped--;
						if (unriped == 0)
						{
							cout << max;
							return 0;
						}
					}
				}
			}
		}
		quex.pop();
		quey.pop();
		quez.pop();
	}


	if (unriped == 0)
		cout << 0;
	else
		cout << -1;

	return 0;
}