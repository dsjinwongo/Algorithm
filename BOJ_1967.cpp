/*
* Problem: 1967
* Solver: Jinwon
* Reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int index);

int N, findMax = 0;
vector<pair<int, int>> board[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, parent, child, weight;
	
	cin >> N;
	
	for (i = 0; i < N - 1; i++)
	{
		cin >> parent >> child >> weight;
		board[parent].push_back({ child,weight });
	}

	DFS(1);

	cout << findMax;


	return 0;
}

int DFS(int index)
{
	vector<int> tree;
	int i, maxTree = 0, firstTree = 0, secondTree = 0;

	//no word of binary tree
	for (i = 0; i < board[index].size(); i++)
	{
		tree.push_back(DFS(board[index][i].first) + board[index][i].second);
		maxTree = max(maxTree, tree[i]);
		
		//top two spanning tree
		secondTree = max(secondTree, tree[i]);
		if (secondTree > firstTree)
			swap(firstTree, secondTree);
	}

	findMax = max(findMax, firstTree + secondTree);

	return maxTree;
}