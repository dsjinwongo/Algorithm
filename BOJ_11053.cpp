/*
Problem: 11053
Solver: Jinwon
Reference: https://wootool.tistory.com/96
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

	int N, i, j, _max;
	int arr[1001] = { 0 };
	int cnt[1001] = { 0 };

	cin >> N;
	
	for (i = 0; i < N; i++)
		cin >> arr[i];

	cnt[0] = 1;
	for (i = 1; i < N; i++)
	{
		_max = 0;
		for (j = 0; j < i; j++)
			if (arr[i] > arr[j])
				_max = max(_max, cnt[j]);
		cnt[i] = _max + 1;
	}

	for (i = 0; i < N; i++)
		_max = max(_max, cnt[i]);

	cout << _max;

	return 0;
}