/*
    < 백트래킹 - 순열 >

    1. 참가자 N명을 순열 탐색.
        go(int dep)
        {
            if(dep == N)
            {
                //순열 완성
                // 0 부터 (N/2)-1까지의 참가자들의 점수 계산
                //(N/2) 부터 N-1까지의 참가자를 점수 계산

                //두 점수의 차이 계산
                //최소 값 갱신.


                return;
            }
            
            for(i=0 ~ N-1)
            {
                if(i를 이미 배정한 경우)
                {
                    continue;
                }

                //i 배정 체크
                // vector에 i 저장
                
                go(dep + 1);

                //i 배정 체크 해제

                // vector에서 i 제거
            }
        }

*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>

using namespace std;

int T;
vector<int> skill_vt;
vector<int> perm_vt;

int N;
int A_team_score = 0;
int B_team_score = 0;
int min_score_diff = INT_MAX;
bool visit[10];

void init()
{
    skill_vt.clear();
    perm_vt.clear();
    fill(visit, visit + 8, false);
}

void input()
{
    cin >> N;
    skill_vt.resize(N);

    for(int i = 0; i < N; i++)
    {
        cin >> skill_vt[i];
    }
    
    min_score_diff = INT_MAX;
}

void go(int dep)
{
    if(dep == N)
    {
        A_team_score = 0;
        B_team_score = 0;

        for(int i = 0; i < N/2; i++)
        {
            A_team_score += skill_vt[perm_vt[i]];
        }

        for(int i = N/2; i < N; i++)
        {
            B_team_score += skill_vt[perm_vt[i]];
        }

        min_score_diff = min(min_score_diff, abs(A_team_score - B_team_score));

        return;
    }

    for(int i = 0; i < N; i++)
    {
        if(visit[i] == true)
        {
            continue;
        }

        perm_vt.push_back(i);
        visit[i] = true;

        go(dep + 1);

        visit[i] = false;
        perm_vt.pop_back();
    }
}


void solution(int t)
{
    go(0);

    cout << "Case #"<<t<<": " << min_score_diff << "\n";

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        init();
        input();
        solution(t);
    }
}