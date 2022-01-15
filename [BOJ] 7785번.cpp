#include<iostream>
#include<string>
#include<set>

int main()
{
	std::string inout, name;
	std::set<std::string> str;
	int n, i;
	std::cin >> n;

	for (i = 0; i < n; i++)
	{
		std::cin >> name >> inout;

		if (inout == "leave")
			str.erase(name);
		else
			str.insert(name);
	}
	
	//�ݺ���(C����� ������ ���� ��) ����
	std::set<std::string>::reverse_iterator find;

	for (find = str.rbegin(); find != str.rend(); find++)
		std::cout << *find << "\n";
}