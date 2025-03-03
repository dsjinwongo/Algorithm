/*
Problem: BOJ[14889]
Solver: Jinwon
Reference: X
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_balance(int member, vector<int> start_member, vector<int> link_member);

int N;
vector<vector<int>> S;

int main()
{
	int i, j, diff, member;
	vector<int> start_member;
	vector<int> link_member;

	cin >> N;
	S.assign(N, vector<int>(N));

	for (i = 0; i < N; i++)
		for(j=0;j<N;j++)
			cin >> S[i][j];

	member = 0;
	diff = find_balance(member, start_member, link_member);

	cout << diff;

	return 0;
}

int find_balance(int member, vector<int> start_member, vector<int> link_member)
{
	int diff, diff1, diff2;
	diff1 = 100;
	diff2 = 100;
	if (member < N)
	{
		if (start_member.size() < N / 2)
		{
			start_member.push_back(member);
			diff1 = find_balance(member + 1, start_member, link_member);
			if (link_member.size() < N / 2)
				start_member.pop_back();
		}

		if (link_member.size() < N / 2)
		{
			link_member.push_back(member);
			diff2 = find_balance(member + 1, start_member, link_member);
		}

		diff = min(diff1, diff2);
	}
	else
	{
		int start_strength, link_strength, i, j;

		start_strength = 0;
		link_strength = 0;

		for (i = 0; i < N / 2 - 1; i++)
		{
			for (j = i + 1; j < N / 2; j++)
			{
				start_strength += S[start_member[i]][start_member[j]];
				start_strength += S[start_member[j]][start_member[i]];
				
				link_strength += S[link_member[i]][link_member[j]];
				link_strength += S[link_member[j]][link_member[i]];
			}
		}

		diff = start_strength > link_strength ? start_strength - link_strength : link_strength - start_strength;
	}

	return diff;
}