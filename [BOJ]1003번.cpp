/*
Problem: [BOJ]1003번
Solver: 이진원
Reference: https://sihyungyou.github.io/baekjoon-1003/
(규칙성을 찾으면 zero, one 따로 찾지 않아도 된다)
참고는 했으나 다르게 품
*/
#include <iostream>
#include <vector>

using namespace std;

int zero_fibofibonacci(int n);
int one_fibofibonacci(int n);

vector<int> zero(40), one(40);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T, i;

	cin >> T;

	zero[0] = 1;
	one[1] = 1;
	for (i = 0; i < T; i++)
	{
		cin >> N;

		one[N] = one_fibofibonacci(N);
		zero[N] = zero_fibofibonacci(N);
		
		cout << zero[N] << " " << one[N] << "\n";
	}

	return 0;
}


int zero_fibofibonacci(int n)
{
	if (n > 1)
	{
		if (zero[n] == 0)
			zero[n] = zero_fibofibonacci(n - 1) + zero_fibofibonacci(n - 2);

		return zero[n];
	}

	if(n==1)
		return 0;
	return 1;
}



int one_fibofibonacci(int n)
{
	if (n > 1)
	{
		if (one[n] == 0)
			one[n] = one_fibofibonacci(n - 1) + one_fibofibonacci(n - 2);
		
		return one[n];
	}

	if (n == 1)
		return 1;
	return 0;
}