/*
Problem: 11501
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

    int tc, i;

    cin >> tc;
    while (tc--)
    {
        int n, tmp, max;
        long long profit;
        vector<int> value;

        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> tmp;
            value.push_back(tmp);
        }

        profit = 0;
        max = 0;
        while (!value.empty())
        {
            if (value.back() < max)
                profit += max - value.back();
            else
                max = value.back();

            value.pop_back();
        }

        cout << profit << "\n";
    }
    return 0;
}