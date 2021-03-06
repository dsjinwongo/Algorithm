/*
Problem: [BOJ]1149번
Solver: 이진원
Reference: https://sihyungyou.github.io/baekjoon-1149/
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define R 0
#define G 1
#define B 2

int N, min_cost;
vector<vector<int>> cost, dp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i;

	cin >> N;
	dp.assign(N, vector<int>(3));
	cost.assign(N, vector<int>(3));

	for (i = 0; i < N; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (i = 0; i < 3; i++)
		dp[0][i] = cost[0][i];

	for (i = 1; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
	}

	min_cost = min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));

	cout << min_cost;
}