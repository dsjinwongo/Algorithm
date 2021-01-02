/*
Problem: [BOJ]14891번
Solver: 이진원
Reference: X
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gear_standard[5] = { 0 };
vector<string> gear;

#define L -1
#define R 1

void check_direction(int gear_num, int direction);
void rotate(int search_direction, int gear_num, int direction);

int main()
{
	string temp;
	int i, j, temp1, temp2, rotate_num, score = 0;
	vector<int> gear_num;
	vector<int> direction;

	gear.push_back("0");
	for (i = 0; i < 4; i++)
	{
		cin >> temp;
		gear.push_back(temp);
	}
	cin >> rotate_num;

	for (i = 0; i < rotate_num; i++)
	{
		cin >> temp1 >> temp2;
		gear_num.push_back(temp1);
		direction.push_back(temp2);
	}

	for (i = 0; i < rotate_num; i++)
	{
		rotate(R, gear_num[i], direction[i]);
		rotate(L, gear_num[i], direction[i]);
		check_direction(gear_num[i], direction[i]);
	}
	
	if (gear[1][gear_standard[1]] == '1')
		score += 1;
	if (gear[2][gear_standard[2]] == '1')
		score += 2;
	if (gear[3][gear_standard[3]] == '1')
		score += 4;
	if (gear[4][gear_standard[4]] == '1')
		score += 8;

	cout << score;
}

void check_direction(int gear_num, int direction)
{
	if (direction == 1)
		gear_standard[gear_num] = gear_standard[gear_num] - 1 > -1 ? gear_standard[gear_num] - 1 : 7;
	else
		gear_standard[gear_num] = gear_standard[gear_num] + 1 < 8 ? gear_standard[gear_num] + 1 : 0;
}

void rotate(int search_direction, int gear_num, int direction)
{
	if (direction != 0)
	{
		if (search_direction == R)
		{
			if (gear_num != 4)
			{
				if (gear[gear_num][(gear_standard[gear_num] + 2) % 8] != gear[gear_num + 1][(gear_standard[gear_num + 1] + 6) % 8])
				{
					if (direction == 1)
						direction = -1;
					else
						direction = 1;
					rotate(search_direction, gear_num + 1, direction);
					check_direction(gear_num + 1, direction);
				}
				else
				{
					direction = 0;
					rotate(search_direction, gear_num + 1, direction);
				}
			}
		}
		else
		{
			if (gear_num != 1)
			{
				if (gear[gear_num][(gear_standard[gear_num] + 6) % 8] != gear[gear_num - 1][(gear_standard[gear_num - 1] + 2) % 8])
				{
					if (direction == 1)
						direction = -1;
					else
						direction = 1;
					rotate(search_direction, gear_num - 1, direction);
					check_direction(gear_num - 1, direction);
				}
				else
				{
					direction = 0;
					rotate(search_direction, gear_num - 1, direction);
				}
			}
		}
	}
}