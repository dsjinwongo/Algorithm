/*
Problem: 15686
Solver: Jinwon
Reference: https://jaimemin.tistory.com/1059
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int distance(pair<int, int> start);
int backtrack(int start, int closeCnt);

int board[51][51] = { 0 };
int N, M, neneCount, _min = 260000;
vector<pair<int, int>> house, chickenHouse;
bool isclosed[51][51] = { false };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;

	cin >> N >> M;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({ i,j });
			else if (board[i][j] == 2)
				chickenHouse.push_back({i, j});
		}
	}

	//점포 개수
	neneCount = chickenHouse.size();

	cout << backtrack(0, 0);

	return 0;
}

int backtrack(int start, int closeCnt)
{
	int i, temp = 0;
	if (closeCnt == neneCount - M)
	{
		board;
		//치킨거리 탐색
		for (i = 0; i < house.size(); i++)
			temp += distance(house[i]);
		return temp;
	}
	else
	{
		for (i = start; i < neneCount; i++)
		{
			isclosed[chickenHouse[i].first][chickenHouse[i].second] = true;
			_min = min(backtrack(i + 1, closeCnt + 1), _min);
			isclosed[chickenHouse[i].first][chickenHouse[i].second] = false;
		}
		return _min;
	}
}

int distance(pair<int, int> house)
{
	int i, dis = 101;
	for (i = 0; i < neneCount; i++)
		if (!isclosed[chickenHouse[i].first][chickenHouse[i].second])
			dis = min(abs(chickenHouse[i].first - house.first) + abs(chickenHouse[i].second - house.second), dis);
	
	return dis;
}