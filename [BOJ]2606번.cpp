/*
Problem: 2606
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<int>* computer, int index);

int _count = 0;
vector<int> visited;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, edge, i, node1, node2, index;
	vector<int>* computer;

	cin >> num >> edge;

	computer = new vector<int>[num + 1];
	visited.assign(num + 1, 0);

	for (i = 0; i < edge; i++)
	{
		cin >> node1 >> node2;

		computer[node1].push_back(node2);
		computer[node2].push_back(node1);
	}

	visited[1] = 1;
	while (!computer[1].empty())
	{
		if (visited[computer[1].back()] == 0)
			DFS(computer, computer[1].back());
		computer[1].pop_back();
	}
	
	cout << _count;

	return 0;
}

void DFS(vector<int>* computer, int index)
{
	_count++;

	visited[index] = 1;
	while (!computer[index].empty())
	{
		if (visited[computer[index].back()] == 0)
			DFS(computer, computer[index].back());
		computer[index].pop_back();
	}
}