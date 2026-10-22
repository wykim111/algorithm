/*
    < 구현 >

    1. 각 악보 ID별로 Timeline 색인
    2. Q개의 time에 해당하는 악보 ID 출력.

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
int timeline[10005];
int music[101];
int seconds = 0;

void set_timeline()
{
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < music[i]; j++)
        {
            timeline[seconds] = i;
            ++seconds;
        }
    }
}

void solution(int query)
{
    cout << timeline[query] << '\n';
}


void input()
{
    cin >> N >> Q;

    //악보 정보 입력
    for(int i = 1; i <= N; i++)
    {
        cin >> music[i];
    }

    //timeline 설정
    set_timeline();


    //질문의 갯수
    for(int i = 0; i < Q; i++)
    {
        int query;

        cin >> query;

        solution(query);
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    input();


    return 0;
}