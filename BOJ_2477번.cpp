# include<iostream>

int main()
{
	int unit, path[6], length[6], i, empty, f_area, area;
	std::cin >> unit;
	for (i = 0; i < 6; i++)
		std::cin >> path[i] >> length[i];
	
	for (i = 0; i < 6; i++)
	{
		if (path[i] == path[(i + 2) % 6] && path[(i + 1) % 6] == path[(i + 3) % 6])
		{
			empty = length[(i + 1) % 6] * length[(i + 2) % 6];
			f_area = length[(i + 4) % 6] * length[(i + 5) % 6];
			area = f_area - empty;
			break;
		}
	}
	std::cout << area * unit;

}