/*
Problem: 10813
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, m, n, a, b;
    vector<int> bowl;

    cin>>n>>m;

    for(i=0;i<=n;i++)
        bowl.push_back(i);

    while(m--)
    {
        cin>>a>>b;
        swap(bowl[a],bowl[b]);
    }

    for(i=1;i<=n;i++)
        cout<<bowl[i]<<" ";

    return 0;
}