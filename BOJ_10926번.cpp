/*
Problem: 1260
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void DFS(set<int>* graph, vector<int> visited, int V);
void BFS(set<int>* graph, vector<int> visited, int V);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    set<int>* graph;
    vector<int> visited;

    int N, M, V, i;

    cin >> N >> M >> V;

    visited.assign(N + 1, 0);
    graph = new set<int>[N + 1];

    for (i = 0; i < M; i++)
    {
        int a, b;

        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    DFS(graph, visited, V);
    cout << "\n";
    BFS(graph, visited, V);

    delete[] graph;

    return 0;
}

void BFS(set<int>* graph, vector<int> visited, int V)
{
    vector<int> answer;
    queue<int> Q;
    set<int>::iterator iter;
    int temp, i;

    Q.push(V);

    while (!Q.empty())
    {
        temp = Q.front();

        visited[temp] = 1;
        answer.push_back(temp);

        for (iter = graph[temp].begin(); iter != graph[temp].end(); iter++)
            Q.push(*iter);

        while (!Q.empty() && visited[Q.front()] == 1)
            Q.pop();
    }

    for (i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}

void DFS(set<int>* graph, vector<int> visited, int V)
{
    vector<int> stack, answer;
    set<int>::reverse_iterator riter;
    int temp, i;

    stack.push_back(V);

    while (!stack.empty())
    {
        temp = stack.back();

        visited[temp] = 1;
        answer.push_back(temp);

        for (riter = graph[temp].rbegin(); riter != graph[temp].rend(); riter++)
            stack.push_back(*riter);

        while (!stack.empty() && visited[stack.back()] == 1)
            stack.pop_back();
    }

    for (i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}