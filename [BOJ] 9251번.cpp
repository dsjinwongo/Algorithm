/*
Problem: 9251
Solver: Jinwon
Reference: http://melonicedlatte.com/algorithm/2018/03/15/181550.html
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int board[1000][1000] = { 0 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j;
	string str1, str2;

	cin >> str1 >> str2;

	for (i = 0; i < str1.size(); i++)
	{
		for (j = 0; j < str2.size(); j++)
		{
			if (str1[i] == str2[j])
			{
				if (i == 0 || j == 0)
					board[i][j] = 1;
				else
					board[i][j] = board[i - 1][j - 1] + 1;
				//대각선인 이유는 같은 값이 연이어있을 때 ex) A / AA 실제론 1임ㅇ에도 2가 된다.
			}
			else
			{
				if (i > 0 && j > 0)
					board[i][j] = max(board[i - 1][j], board[i][j - 1]);
				else if (i == 0 && j == 0)
					board[i][j] = 0;
				else if (i == 0)
					board[i][j] = board[i][j - 1];
				else
					board[i][j] = board[i - 1][j];
			}
		}
	}

	cout << board[str1.size() - 1][str2.size() - 1];

	return 0;
}