/*
Problem: 15663
Solver: Jinwon
Reference: https://m.blog.naver.com/js568/221857286945
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void backtrack(int index);

bool visited[8] = { false };
int num[8] = { 0 };
int board[8] = { 0 };
int N, M;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	cin >> N >> M;

	for (i = 0; i < N; i++)
		cin >> num[i];

	sort(num, num + N);

	backtrack(0);

	return 0;
}

void backtrack(int index)
{
	int i, duplicate = 0;;

	if (index == M)
	{
		

		for (i = 0; i < M; i++)
			cout << board[i] << " ";
		cout << "\n";
	}
	else
	{
		for (i = 0; i < N; i++)
		{
			//같은 값을 두번 반복하지 않기 위함
			if (!visited[i] && duplicate != num[i])
			{
				visited[i] = true;

				//이전에 입력되었던 값에 영향을 받지않기 위해 새로운 변수 생성
				duplicate = num[i];
				board[index] = num[i];
				backtrack(index + 1);

				visited[i] = false;
			}
		}
	}
}