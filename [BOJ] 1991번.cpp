/*
* Problem: 1991
* Solver: Jinwon
* Reference: 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void preorder(char temp);
void inorder(char temp);
void postorder(char temp);

map<char, pair<char, char>> node;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i;
	char parent, leftChild, rightChild;

	cin >> N;

	for (i = 0; i < N; i++)
	{
		cin >> parent >> leftChild >> rightChild;
		node[parent] = { leftChild, rightChild };
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');

	return 0;
}

void preorder(char temp)
{
	if (temp != '.')
	{
		cout << temp;
		preorder(node[temp].first);
		preorder(node[temp].second);
	}
}

void inorder(char temp)
{
	if (temp != '.')
	{
		inorder(node[temp].first);
		cout << temp;
		inorder(node[temp].second);
	}
}

void postorder(char temp)
{
	if (temp != '.')
	{
		postorder(node[temp].first);
		postorder(node[temp].second);
		cout << temp;
	}
}