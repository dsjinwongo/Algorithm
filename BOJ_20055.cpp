/*
Problem: [BOJ]20055
Solver: Jinwon
Reference: X
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define FULL 1
#define EMPTY 0

void move_robot(int up_index);
void push_robot(int index);
void pop_robot(int index);

vector<int> Durability, Robot;
int  N, K, K_num;

int main()
{
	int cycle, i, temp, up_index, down_index;

	cin >> N >> K;

	Robot.assign(2 * N, 0);
	Durability.assign(2 * N, 0);
	for (i = 0; i < 2 * N; i++)
		cin >> Durability[i];

	K_num = 0;
	cycle = 0;
	up_index = 0;
	while (K_num < K)
	{
		up_index = up_index > 0 ? --up_index : 2 * N - 1;
		down_index = (up_index + N - 1) % (2 * N);
		
		pop_robot(down_index);
		move_robot(up_index);
		push_robot(up_index);
		pop_robot(down_index);
		cycle++;
	}

	cout << cycle;
}

void move_robot(int up_index)
{
	int i, index, next_index;
	for (i = up_index + N - 1; i >= up_index; i--)
	{
		index= i % (2 * N);
		next_index = (i + 1) % (2 * N);
		if (Robot[index] == FULL)
		{
			if (Robot[next_index] == EMPTY && Durability[next_index] > 0)
			{
				Robot[index] = EMPTY;
				Durability[next_index]--;
				Robot[next_index] = FULL;

				if (Durability[next_index] == 0)
					K_num++;
			}
		}
	}
}

void push_robot(int index)
{
	if (Robot[index] == EMPTY && Durability[index] > 0)
	{
		Durability[index]--;
		Robot[index] = FULL;

		if (Durability[index] == 0)
			K_num++;
	}
}

void pop_robot(int index)
{
	if (Robot[index] == FULL)
		Robot[index] = EMPTY;
}