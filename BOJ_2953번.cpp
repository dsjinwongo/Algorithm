//BobeRani_[BOJ]_2953

#include <iostream>

int main()
{
	int a[5][5];
	int i, j, winner, max;
	max = 0;
	
	for (i = 0; i < 5; i++)
	{
		a[i][4] = 0;
		for (j = 0; j < 4; j++)
		{
			std::cin >> a[i][j];
			a[i][4] += a[i][j];
		}
		if (a[i][4] > max)
		{
			max = a[i][4];
			winner = i + 1;;
		}
	}

	std::cout << winner << " " << a[winner - 1][4];
}