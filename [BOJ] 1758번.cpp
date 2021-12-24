/*
Problem: 1758
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, temp;
    long long sum = 0;
    vector<int> tip;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> temp;
        tip.push_back(temp);
    }

    sort(tip.begin(), tip.end());

    for (i = 0; i < n; i++)
    {
        if (tip.back() - i < 0)
            break;
        sum += tip.back() - i;
        tip.pop_back();
    }

    cout << sum;

    return 0;
}