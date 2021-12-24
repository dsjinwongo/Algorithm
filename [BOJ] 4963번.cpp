/*
Problem: [BOJ]4963
Solver: Jinwon
Reference:
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(int a, int b);

vector<vector<int>> visited;
vector<vector<int>> board;
int w,h;
int x[8]={1, -1, 0, 0, 1, -1, 1, -1};
int y[8]={0, 0, 1, -1, -1, 1, 1, -1};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, j, count=0;

    cin>>w>>h;

    while(w!=0&&h!=0)
    {
        visited.assign(h,vector<int>(w,0));
        board.assign(h,vector<int>(w,0));
        
        for(i=0; i<h; i++)
            for(j=0;j<w;j++)
                cin>>board[i][j];

        for(i=0; i<h; i++)
        {
            for(j=0;j<w;j++)
            {
                if(board[i][j]==1&&visited[i][j]==0)
                {
                    count++;
                    dfs(i, j);
                }
            }
        }

        cout<<count<<"\n";

        count=0;
        cin>>w>>h;
    }
}

void dfs(int a, int b)
{
    if(a>-1&&a<h&&b>-1&&b<w)
    {
        if(board[a][b]==1&&visited[a][b]==0)
        {
            visited[a][b]=1;
            for(int i=0; i<8; i++)
                dfs(a+x[i], b+y[i]);
        }
    }
}