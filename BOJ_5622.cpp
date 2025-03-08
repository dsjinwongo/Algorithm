/*
Problem: 5622
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

    string s;
    int time;

    cin >> s;

    time = 0;
    
    for(char c : s)
    {
        if(c<'D')
            time+=3;
        else if(c<'G')
            time+=4;
        else if(c<'J')
            time+=5;
        else if(c<'M')
            time+=6;
        else if(c<'P')
            time+=7;
        else if(c<'T')
            time+=8;
        else if(c<'W')
            time+=9;
        else
            time+=10;
    }

    cout<<time;

    return 0;
}