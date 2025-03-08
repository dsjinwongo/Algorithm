/*
Problem: 25314
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

    int byte;

    for(cin>>byte; byte>0; byte-=4)
        cout<<"long ";
    
    cout<<"int";

    return 0;
}