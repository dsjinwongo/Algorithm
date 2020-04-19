# include<iostream>
# include<string>
# include<algorithm>

int main()
{
	int num, i, size;
	std::string n1, n2;
	while (1)
	{
		std::cin >> num;
		if (num == 0)
			return 0;
		else
		{
			n1 = std::to_string(num);
			n2 = n1;
			std::reverse(n2.begin(), n2.end());
			if (n2 == n1)
				std::cout << "yes\n";
			else
				std::cout << "no\n";
		}
	}
}