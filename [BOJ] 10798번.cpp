#include<iostream>
#include<string>

int main()
{
	std::string str[5], strsum;

	std::cin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4];

	int i, j, length;
	length = 0;
	for (i = 0; i < 5; i++)
		if (length < str[i].length())
			length = str[i].length();

	for (i = 0; i < length; i++)
		for (j = 0; j < 5; j++)
			if (i < str[j].length())
				strsum += str[j].at(i);

	std::cout << strsum;
}