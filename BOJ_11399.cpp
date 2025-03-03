/*
Problem: 11399
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

	int N, temp, i, sum;
	vector<int> p;

	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> temp;
		p.push_back(temp);
	}

	sort(p.begin(), p.end());

	sum = p[0];
	for (i = 1; i < N; i++)
	{
		p[i] += p[i - 1];
		sum += p[i];
	}

	cout << sum;

	return 0;
}