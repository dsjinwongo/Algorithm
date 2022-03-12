/*
Problem: 9465
Solver: Jinwon
Reference: https://m.blog.naver.com/occidere/220786307316
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
* 한칸차이 대각선, 두칸차이 대각선의 값중에서 큰값을 골라서 저장. 세번째 대각선은 한칸대각선과 동일
*/
int board[2][100000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, i, j;

	cin >> T;
	while (T--)
	{
		cin >> N;
		for (i = 0; i < 2; i++)
			for (j = 0; j < N; j++)
				cin >> board[i][j];

		if (N > 1)
		{
			board[0][1] += board[1][0];
			board[1][1] += board[0][0];

			for (i = 2; i < N; i++)
			{
				board[0][i] += max(board[1][i - 1], board[1][i - 2]);
				board[1][i] += max(board[0][i - 1], board[0][i - 2]);
			}
		}

		cout << max(board[0][N - 1], board[1][N - 1]) << "\n";
	}

	return 0;
}