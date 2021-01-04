/*
Problem: [BOJ]14888번
Solver: 이진원
Reference: X
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define PLUS 0
#define	MINUS 1
#define MUL 2
#define DIV 3

int N, sum_max, sum_min;
vector<int> _operand, expression;

void recurrence(int index, vector<int> _operator);

int main()
{
	vector<int> _operator(4);
	int i, temp;

	cin >> N;
	expression.assign(N - 1, 4);
	for (i = 0; i < N; i++)
	{
		cin >> temp;
		_operand.push_back(temp);
	}

	for (i = 0; i < 4; i++)
	{
		cin >> temp;
		_operator[i] = temp;
	}

	sum_max = -1000000000;
	sum_min = 1000000000;
	recurrence(0, _operator);

	cout << sum_max << "\n" << sum_min;
}

void recurrence(int index, vector<int> _operator)
{
	if (index < N - 1)
	{
		if (_operator[PLUS] > 0)
		{
			expression[index] = PLUS;
			_operator[PLUS]--;
			recurrence(index + 1, _operator);
			_operator[PLUS]++;
		}
		if (_operator[MINUS] > 0)
		{
			expression[index] = MINUS;
			_operator[MINUS]--;
			recurrence(index + 1, _operator);
			_operator[MINUS]++;
		}
		if (_operator[MUL] > 0)
		{
			expression[index] = MUL;
			_operator[MUL]--;
			recurrence(index + 1, _operator);
			_operator[MUL]++;
		}
		if (_operator[DIV] > 0)
		{
			expression[index] = DIV;
			_operator[DIV]--;
			recurrence(index + 1, _operator);
			_operator[DIV]++;
		}
	}
	else
	{
		int i, temp;
		temp = _operand[0];
		for (i = 0; i < N - 1; i++)
		{
			if (expression[i] == PLUS)
				temp += _operand[i + 1];
			else if (expression[i] == MINUS)
				temp -= _operand[i + 1];
			else if (expression[i] == MUL)
				temp *= _operand[i + 1];
			else
			{
				if (temp < 0)
				{
					temp = -temp;
					temp /= _operand[i + 1];
					temp = -temp;
				}
				else
					temp /= _operand[i + 1];
			}
		}
		sum_min = min(sum_min, temp);
		sum_max = max(sum_max, temp);
	}
}