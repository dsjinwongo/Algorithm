/*
Problem: [BOJ]1918번
Solver: 이진원
Reference: X
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int priority(char _operator);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> _operator;
	string exp, postexp;
	int i;

	cin >> exp;

	for (i = 0; i < exp.size(); i++)
	{
		if ('A' <= exp[i] && exp[i] <= 'Z')
			postexp.push_back(exp[i]);
		else if (exp[i] == ')')
		{
			while (_operator.top() != '(')
			{
				postexp.push_back(_operator.top());
				_operator.pop();
			}
			_operator.pop();
		}
		else if (_operator.empty() || exp[i] == '(')
			_operator.push(exp[i]);
		else if (priority(exp[i]) > priority(_operator.top()))
			_operator.push(exp[i]);
		else
		{
			while (!(_operator.empty()) && priority(exp[i]) <= priority(_operator.top()))
			{
				postexp.push_back(_operator.top());
				_operator.pop();
			}
			_operator.push(exp[i]);
		}
	}
	while (_operator.empty() == false)
	{
		postexp.push_back(_operator.top());
		_operator.pop();
	}

	cout << postexp;
}

int priority(char _operator)
{
	switch (_operator)
	{
	case '(':
		return 0;
	case '-':
	case '+':
		return 1;
	case '/':
	case '*':
		return 2;
	}
}