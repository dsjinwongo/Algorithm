/*
Problem: 11047
Solver: Jinwon
Reference:
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

	int N, K, i, temp, count;
	vector<int> A;

	cin >> N >> K;

	for (i = 0; i < N; i++)
	{
		cin >> temp;
		A.push_back(temp);
	}

	count = 0;
	for (i = N - 1; i > -1; i--)
	{
		while (A[i] <= K)
		{
			K -= A[i];
			count++;
		}
	}

	cout << count;
	
	return 0;
}