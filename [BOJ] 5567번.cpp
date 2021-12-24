/*
Problem: 5567
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, n, m, a, b, level1, level2, count = 0;

    cin >> n >> m;

    vector<vector<int>> list;
    vector<int> answer;

    list.assign(n + 1, vector<int>());
    answer.assign(n + 1, 0);

    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    while (!list[1].empty())
    {
        level1 = list[1].back();
        answer[level1] = 1;
        while (!list[level1].empty())
        {
            level2 = list[level1].back();
            answer[level2] = 1;
            list[level1].pop_back();
        }
        list[1].pop_back();
    }

    for (i = 2; i < n + 1; i++)
        if (answer[i] == 1)
            count++;

    cout << count;

    return 0;
}