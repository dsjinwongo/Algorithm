/*
Problem: 12865
Solver: Jinwon
Reference: https://gumeum.tistory.com/25
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, i, j, a, b, weight, value;
	vector<pair<int, int>> product;
	int dp[101][1000001] = { 0 };

	cin >> N >> K;

	for (i = 0; i < N; i++)
	{
		cin >> a >> b;
		product.push_back({ a,b });
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= K; j++)
		{
			weight = product[i - 1].first;
			value = product[i - 1].second;
			if (weight <= j)
				dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	

	cout << dp[N][K];

	return 0;
}