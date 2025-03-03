//BobeRani_[BOJ]_10799

#include <iostream>

using namespace std;

int main()
{
	int new_open, open, count;
	char push, previous;

	new_open = 0;
	open = 0;
	count = 0;
	previous = '0';
	
	do
	{
		cin.get(push);
		if (push == '(')
			new_open++;
		else if (push == ')'&&previous == '(')
		{
			new_open--;
			count += new_open * 2;
			count += open;
			open += new_open;
			new_open = 0;
		}
		else if (push == ')')
			if (new_open == 0)
				open--;
			else
				new_open--;
		previous = push;
	}while (push != '\n');

	cout << count;
}