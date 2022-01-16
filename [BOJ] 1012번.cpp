/*
Problem: 1012
Solver: Jinwon
Reference:
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void DFS(vector<int>* board, int a, int b, int M, int N);

int x[4] = { 1,-1,0,0 };
int y[4] = { 0,0,1,-1 };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M, N, K, i, j, a, b, worm;
    vector<int>* board;

    cin >> T;

    while (T--)
    {
        cin >> M >> N >> K;
        worm = 0;

        board = new vector<int>[N];

        for (i = 0; i < N; i++)
            board[i].assign(M, 0);
        
        while (K--)
        {
            cin >> a >> b;
            
            board[b][a] = 1;
        }

        for (b = 0; b < N; b++)
        {
            for (a = 0; a < M; a++)
            {
                if (board[b][a] == 1)
                {
                    worm++;
                    DFS(board, a, b, M, N);
                }
            }
        }

        delete[] board;

        cout << worm <<"\n";
    }

    return 0;
}

void DFS(vector<int>* board, int a, int b, int M, int N)
{
    if (b>-1&&a>-1&&b<N&&a<M)
    {
        if (board[b][a] == 1)
        {
            int i;

            board[b][a] = 2;
            
            for (i = 0; i < 4; i++)
                DFS(board, a + x[i], b + y[i], M, N);
        }
    }
}