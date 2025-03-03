/*
Problem: 2525
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

    int h, m, t;

    cin>>h>>m>>t;

    m+=t%60;
    h+=t/60+m/60;

    cout<<h%24<<" "<<m%60;

    return 0;
}