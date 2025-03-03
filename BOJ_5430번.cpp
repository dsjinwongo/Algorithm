/*
Problem: 5430
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string result(string func, int num, vector<int> arr);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	string func = "";
	int num = 0;
	string arrStr = "";
	vector<int> arr;
	string temp = "";
	int i = 0;

	cin >> testCase;

	while (testCase--)
	{
		cin >> func >> num >> arrStr;

		for (i = 0; i < arrStr.size(); i++)
		{
			if (arrStr[i] >= '0' && arrStr[i] <= '9')
				temp.push_back(arrStr[i]);
			else if (!temp.empty() && (arrStr[i] == ',' || arrStr[i] == ']'))
			{
				arr.push_back(stoi(temp));
				temp = "";
			}
		}

		cout << result(func, num, arr);

		arr.clear();
	}

	return 0;
}

string result(string func, int num, vector<int> arr)
{
	int i = 0;
	int front = 0;
	int back = arr.size();
	bool isR = false;
	string answer = "";

	for(i=0;i<func.size();i++)
	{
		if (func[i] == 'R')
		{
			if (isR == false)
				isR = true;
			else
				isR = false;
		}
		else if (func[i] == 'D')
		{
			if (back > front)
				if (isR)
					back--;
				else
					front++;
			else
				return "error\n";
		}
	}

	answer += '[';

	if (isR)
	{
		for (i = back - 1; i >= front; i--)
			answer += to_string(arr[i]) + ",";
	}
	else
	{
		for (i = front; i < back; i++)
			answer += to_string(arr[i]) + ",";
	}

	if (answer.back() == ',')
		answer.pop_back();
	answer += "]\n";

	return answer;
}