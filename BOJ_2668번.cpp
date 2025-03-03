/*
Problem: 2668
Solver: Jinwon
Reference:
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> set1;
vector<int> set2;
vector<int> erase_index;
vector<int> erase_value;
vector<int> set1_board;
vector<int> set2_board;

void check_set2();
void check_set1();
void erase(vector<int>& set);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i, n, tmp;

    cin >> n;
    set1_board.assign(n + 1, 0);
    set2_board.assign(n + 1, 1);

    //집합2 입력
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        set1.push_back(tmp);
        //집합 내의 값의 개수
        set1_board[tmp]++;
    }

    //집합1 입력하며 1에 없는 값 기록
    for (i = 0; i < n; i++)
    {
        //2에 없을 경우 인덱스 기록
        if (set1_board[i+1] == 0)
            erase_index.push_back(i);
        else
        {
            set2_board[i + 1]++;
            set2.push_back(i + 1);
        }
    }

    check_set1();

    

    cout << set2.size() << "\n";
    for (i = 0; i < set2.size(); i++)
        cout << set2[i] << "\n";

    return 0;
}

void check_set2()
{
    if (!erase_value.empty())
    {
        int i, value;
        vector<int>::iterator iter;
        iter = set2.begin();
        while (!erase_value.empty())
        {
            value = erase_value.back();

            //집합에 존재하는지 확인
            if (set2_board[value] > 0)
            {
                //삭제
                set2_board[value] = 0;
                for (i = 0; i < set2.size(); i++)
                {
                    //인덱스 저장
                    if (set2[i] == value)
                        erase_index.push_back(i);
                }
            }
            erase_value.pop_back();
        }

        erase(set2);

        check_set1();
    }
}

void check_set1()
{
    if (!erase_index.empty())
    {
        int i, index;

        for (i = 0; i < erase_index.size(); i++)
        {
            index = erase_index[i];

            //보드에서 개수 1개 줄임
            set1_board[set1[index]]--;


            //지워질 인덱스에 해당하는 값이 더이상 존재하지 않는 경우
            if (set1_board[set1[index]] == 0)
                erase_value.push_back(set1[index]);
        }

        //삭제
        erase(set1);
        erase_index.clear();

        check_set2();
    }
}

//.erase를 사용하면 set의 인덱스가 실시간으로 변하기 때문에 따로 밖으로 빼놓음
void erase(vector<int>& set)
{
    int i, size;
    vector<int>::iterator iter;
    iter = set.begin();

    //삭제할때마다 인덱스가 주는 것을 고려하기 위해 역순으로 정렬
    sort(erase_index.begin(), erase_index.end(), greater<int>());

    //erase_index의 크기가 변하기 때문에 따로 할당
    size = erase_index.size();
    for (i = 0; i < size; i++)
        set.erase(iter + erase_index[i]);
}