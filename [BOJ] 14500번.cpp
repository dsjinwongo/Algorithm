/*
Problem: 14500
Solver: Jinwon
Reference: https://jaimemin.tistory.com/623
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int miro(int x, int y, int sum, int count);
int excep(int x, int y);

int N, M;
//vector로 하면 복사하는 시간 때문에 시간초과가 뜸
int board[500][500] = { 0 };
bool visited[500][500] = { true };

int indexX[4] = { 1,-1,0,0 };
int indexY[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int i, j, sum, count, _max;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> board[i][j];

	_max = 0;
	sum = 0;
	count = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			visited[i][j] = true;
			_max = max(miro(i, j, sum, count + 1), _max);
			visited[i][j] = false;

			_max = max(excep(i, j), _max);
		}
	}

	cout << _max;

	return 0;
}

int miro(int x, int y, int sum, int count)
{
	sum += board[x][y];

	if (count == 4)
		return sum;

	int i, _max;
	_max = 0;
	for (i = 0; i < 4; i++)
	{
		if (x + indexX[i] > -1 && x + indexX[i]< N && y + indexY[i]>-1 && y + indexY[i] < M)
		{
			if (!visited[x + indexX[i]][y + indexY[i]])
			{
				visited[x + indexX[i]][y + indexY[i]] = true;
				_max = max(miro(x + indexX[i], y + indexY[i], sum, count + 1), _max);
				visited[x + indexX[i]][y + indexY[i]] = false;
			}
		}
	}

	return _max;
}

int excep(int x, int y)
{
	int i, _min, sum, count;

	_min = 1000;
	count = 0;
	sum = board[x][y];
	for (i = 0; i < 4; i++)
	{
		if (x + indexX[i] > -1 && x + indexX[i]< N && y + indexY[i]>-1 && y + indexY[i] < M)
		{
			count++;
			sum += board[x + indexX[i]][y + indexY[i]];
			_min = min(board[x + indexX[i]][y + indexY[i]], _min);
		}
	}

	if (count == 4)
		sum -= _min;

	return sum;
}