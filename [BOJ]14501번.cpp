/*
Problem: BOJ[14501]
Solver: Jinwon
Reference: X
*/
#include <iostream>

using namespace std;

typedef struct counsel {
	int time;
	int pay;
}counsel;

int find_max(int date, int current_pay, counsel* plan);
int N, max_pay = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, date, current_pay;
	counsel* plan;

	cin >> N;
	plan = new counsel[N + 1];

	for (i = 1; i <= N; i++)
		cin >> plan[i].time >> plan[i].pay;

	date = 1;
	current_pay = 0;

	max_pay = find_max(date, current_pay, plan);

	cout << max_pay;

	delete[] plan;

	return 0;
}

int find_max(int date, int current_pay, counsel* plan)
{
	if (date <= N)
	{
		if (date + plan[date].time <= N + 1)
			max_pay = find_max(date + plan[date].time, current_pay + plan[date].pay, plan);

		if (date + 1 < N + 1)
			max_pay = find_max(date + 1, current_pay, plan);
	}

	return max_pay > current_pay ? max_pay : current_pay;
}