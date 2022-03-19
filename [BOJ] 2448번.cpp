/*
* Problem: 2448
* Solver: Jinwon
* Reference: https://ssu-gongdoli.tistory.com/79
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void divideConquer(int N, int x, int y);

char board[7000][7000];
//char string last one is end of line
char star[3][7] = {
	"  *   ",
	" * *  ",
	"***** "
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j;

	cin >> N;

	divideConquer(N, 0, 0);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N * 2; j++)
			if (board[i][j] == '*')
				cout << "*";
			else
				cout << " ";

		cout << "\n";
	}

	return 0;
}

void divideConquer(int N, int x, int y)
{
	int i, j;

	if (N == 3)
	{
		for (i = 0; i < 3; i++)
			for (j = 0; j < 6; j++)
				board[x + i][y + j] = star[i][j];
	}
	else
	{
		divideConquer(N / 2, x, y + N / 2);
		divideConquer(N / 2, x + N / 2, y);
		divideConquer(N / 2, x + N / 2, y + N);
	}
}