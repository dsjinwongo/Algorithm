/*
Problem: 25304
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

    int i, price, count, num, sum;

    cin>>sum>>num;

    
    for(i=0;i<num;i++)
    {
        cin>>price>>count;
        sum-=price*count;
    }

    cout<<(sum==0 ? "Yes" : "No");

    return 0;
}