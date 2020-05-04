#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<long long, int> &a, const pair<long long, int> &b)
{
	if (a.second == b.second)
		return (a.first < b.first);
	return (a.second > b.second);
}

int main()
{
	map<long long, int> card;
	vector<pair<long long, int>> p;
	map<long long, int>::iterator iter_m;
	vector<pair<long long, int>>::iterator iter_v;

	int N;
	long long card_num, most;
	cin >> N;

	while (N--)
	{
		cin >> card_num;

		if (card.find(card_num) == card.end())
			card.insert(pair<long long, int>(card_num, 0));
		else
			card[card_num]++;
	}

	for (iter_m = card.begin(); iter_m != card.end(); iter_m++)
		p.push_back(pair<long long, int>(iter_m->first, iter_m->second));

	sort(p.begin(), p.end(), compare);

	iter_v = p.begin();
	cout << iter_v->first;

	return 0;
}