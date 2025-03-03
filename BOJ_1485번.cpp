#include <iostream>

using namespace std;
int main()
{
	int n, i;
	cin >> n;

	while (n--)
	{
		int x[4] = { 0 };
		int y[4] = { 0 };
		int l[6], key, check1, check2, t;
		check1 = 0;
		check2 = 0;
		key = 0;
		t = 0;

		for (i = 0; i < 4; i++)
		{
			cin >> x[i] >> y[i];
			if (i > 0)
			{
				l[i - 1] = (x[i - 1] - x[i])*(x[i - 1] - x[i]) + (y[i - 1] - y[i])*(y[i - 1] - y[i]);
				key = key < l[i - 1] ? l[i - 1] : key;
			}
			if (i == 3)
			{
				l[3] = (x[3] - x[1])*(x[3] - x[1]) + (y[3] - y[1])*(y[3] - y[1]);
				key = key < l[3] ? l[3] : key;
				l[4] = (x[3] - x[0])*(x[3] - x[0]) + (y[3] - y[0])*(y[3] - y[0]);
				key = key < l[4] ? l[4] : key;
				l[5] = (x[2] - x[0])*(x[2] - x[0]) + (y[2] - y[0])*(y[2] - y[0]);
				key = key < l[5] ? l[5] : key;
			}
		}

		for (i = 0; i < 6; i++)
		{
			if (key == l[i])
				check1++;
			else if (key / 2 == l[i])
				check2++;
		}
		if (check1 == 2 && check2 == 4)
			t = 1;

		cout << t << endl;
	}

	return 0;
}