/*
Problem: [BOJ]2407번
Solver: 이진원
Reference: https://jaimemin.tistory.com/682
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string combination(int n, int m);
string add(string num1, string num2);

string dp[101][101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;

	cout << combination(n, m);
}

string add(string num1, string num2)
{
	int sum = 0;
	string result;

	while (num1.size() > 0 || num2.size() > 0 || sum)
	{
		if (num1.size() > 0)
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (num2.size() > 0)
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());

	return result;
}

string combination(int n, int m)
{
	if (dp[n][m] != "")
		return dp[n][m];
	if (n == m || m == 0)
		return "1";
	
	dp[n][m] = add(combination(n - 1, m), combination(n - 1, m - 1));
	return dp[n][m];
}