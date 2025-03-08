/*
Problem: 10809
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int i;
    int alphabet[123];
    
    memset(alphabet, -1, sizeof(alphabet));

    cin>>str;

    for(i=0;i<str.length(); i++)
        if(alphabet[str[i]-97]==-1)
            alphabet[str[i]-97]=i;

    for(i=0;i<26;i++)
        cout<<alphabet[i]<<" ";

    return 0;
}