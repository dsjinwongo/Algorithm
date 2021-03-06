/*
Problem: [BOJ]3190번
Solver: 이진원
Reference: X
*/
#include <iostream>
#include <vector>
#include <queue>

#define EMPTY 0
#define APPLE 1
#define SNAKE 2

using namespace std;

void apple();
int promising();
void move_head();

vector<vector<int>> board;
vector<char> time_board;
int N, apple_num, snake_head[2], snake_tail[2], time;
char previous_direction;
queue<int> snake[2];

int main()
{
	int turn_num, i;

	snake[0].push(1);
	snake[1].push(1);
	snake_head[0] = 1;
	snake_head[1] = 1;
	snake_tail[0] = 1;
	snake_tail[1] = 1;
	previous_direction = 'E';
	time = 0;

	cin >> N;
	cin >> apple_num;

	board.assign(N + 1, vector<int>(N + 1, 0));
	for (i = 0; i < apple_num; i++)
	{
		int a, b;
		cin >> a >> b;

		board[a][b] = 1;
	}

	cin >> turn_num;
	time_board.assign(10000, '0');
	for (i = 0; i < turn_num; i++)
	{
		int a;
		char b;
		cin >> a >> b;

		time_board[a] = b;
	}

	while (promising() == 1)
	{
		apple();
		move_head();
		time++;
	}

	cout << time;
}

void apple()
{
	snake[0].push(snake_head[0]);
	snake[1].push(snake_head[1]);

	if (board[snake_head[0]][snake_head[1]] == EMPTY)
	{
		board[snake_tail[0]][snake_tail[1]] = EMPTY;

		snake[0].pop();
		snake[1].pop();

		snake_tail[0] = snake[0].front();
		snake_tail[1] = snake[1].front();
	}

	board[snake_head[0]][snake_head[1]] = 2;
}

int promising()
{
	if (snake_head[0]<1 || snake_head[1]<1 || snake_head[0]>N || snake_head[1]>N || board[snake_head[0]][snake_head[1]] == SNAKE)
		return 0;
	return 1;
}

void move_head()
{
	if (time_board[time] == '0')
	{
		if (previous_direction == 'E')
			snake_head[1]++;
		else if (previous_direction == 'W')
			snake_head[1]--;
		else if (previous_direction == 'N')
			snake_head[0]--;
		else if (previous_direction == 'S')
			snake_head[0]++;
	}
	else if (time_board[time] == 'D')
	{
		if (previous_direction == 'E')
		{
			snake_head[0]++;
			previous_direction = 'S';
		}
		else if (previous_direction == 'W')
		{
			snake_head[0]--;
			previous_direction = 'N';
		}
		else if (previous_direction == 'N')
		{
			snake_head[1]++;
			previous_direction = 'E';
		}
		else if (previous_direction == 'S')
		{
			snake_head[1]--;
			previous_direction = 'W';
		}
	}
	else if (time_board[time] == 'L')
	{
		if (previous_direction == 'E')
		{
			snake_head[0]--;
			previous_direction = 'N';
		}
		else if (previous_direction == 'W')
		{
			snake_head[0]++;
			previous_direction = 'S';
		}
		else if (previous_direction == 'N')
		{
			snake_head[1]--;
			previous_direction = 'W';
		}
		else if (previous_direction == 'S')
		{
			snake_head[1]++;
			previous_direction = 'E';
		}
	}
}