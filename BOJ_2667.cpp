/*
Problem: 2667
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void DFS(int x, int y);

vector<string> board;
int N, _count;
int visited[26][26] = { 0 };
int indexX[4] = { 1,-1,0,0 };
int indexY[4] = { 0,0,1,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	string temp;
	vector<int> num;

	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> temp;
		board.push_back(temp);
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (board[i][j] == '1' && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				_count = 0;
				DFS(i, j);
				num.push_back(_count);
			}
		}
	}

	if(num.empty())
		num.push_back(_count);
	else
		sort(num.begin(), num.end());

	cout << num.size() << "\n";
	for (i = 0; i < num.size(); i++)
		cout << num[i] << "\n";

	return 0;
}

void DFS(int x, int y)
{
	int i, a, b;
	_count++;

	for (i = 0; i < 4; i++)
	{
		a = x + indexX[i];
		b = y + indexY[i];
		if (a > -1 && a<N && b>-1 && b < N)
		{
			if (board[a][b] == '1' && visited[a][b] == 0)
			{
				visited[a][b] = 1;
				DFS(a, b);
			}
		}
	}
}