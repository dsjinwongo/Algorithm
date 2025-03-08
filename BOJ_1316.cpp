/*
Problem: 1316
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

    string str;
    int str_num, group_num;

    group_num=0;

    cin>>str_num;
    while(str_num--)
    {
        int index_location[26]={0};
        int isgroup=1;

        cin>>str;
        for(int i=0; i<str.length(); i++)
        {
            if(index_location[str[i]-'a']==0 || index_location[str[i]-'a']==i)
                index_location[str[i]-'a']=i+1;
            else
            {
                isgroup=0;
                break;
            }
        }

        if(isgroup)
            group_num++;

    }

    cout<<group_num;

    return 0;
}