/*
Problem: 2480
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

    int a, b, c;

    cin>>a>>b>>c;

    if(a==b && b==c)
        cout<<10000+a*1000;
    else if(a!=b && b!=c && a!=c)
        cout<<max(max(a,b),c)*100;
    else
        cout << ((a==b) ? 1000+a*100 : 1000+c*100);

    return 0;
}