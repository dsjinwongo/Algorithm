/*
Problem: [BOJ]15904
Solver: Jinwon
Reference:
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char c;
    string str="UCPC";

    int check=0;

    while((check<=3)&&((c=getchar())!='\n'))
    {
        if(c==str[check])
            check++;
    }
    

    if(check>3)
        cout<<"I love UCPC";
    else
        cout<<"I hate UCPC";
}