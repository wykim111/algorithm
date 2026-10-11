/*
    < DP >

    1. dp 상태 정의 : dp[dep][sequence] = dep번째 계단을 sequence번째 연속으로 밟았을 때의 최대 점수
    2. 메모이제이션
        go(dep, sequence)
        {
            if(dep >= N) return 0;
            if(dp[dep][sequence] != -1) return dp[dep][sequence];

            if(sequence < 2)
            {
                dp[dep][sequence] = max(dp[dep][sequence], go(dep + 1, sequence + 1) + stairs_vt[dep]);
            }
            dp[dep][sequence] = max(dp[dep][sequence], go(dep + 2, 1) + stairs_vt[dep]);
            return dp[dep][sequence];
        }

*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
using namespace std;

int N;
vector<int> stairs_vt;
int ans = INT_MIN;

#if 0 //재귀 버전
void input()
{
    cin >> N;
    
    stairs_vt.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> stairs_vt[i];
    }
}

void go(int dep, int sum, int sequence)
{
    if(dep >= N) return;

    if(dep == (N-1))
    {
        ans = max(ans, sum + stairs_vt[dep]);
        return;
    }
    
    if(sequence < 2)
    {
        go(dep + 1, sum + stairs_vt[dep], sequence + 1);
    }

    go(dep + 2, sum + stairs_vt[dep], 1);
    


}

void solution()
{
    go(0, 0, 1);
    go(1, 0, 1);

    cout << ans << '\n';
}
#else //dp 버전

int dp[301][3]; //dp[dep][sequence] = dep번째 계단을 sequence번째 연속으로 밟았을 때의 최대 점수

void input()
{
    cin >> N;
    stairs_vt.resize(N);

    for (int i = 0; i < N; i++)
    {
        cin >> stairs_vt[i];
    }
}

void solution()
{
    dp[0][1] = stairs_vt[0];
    dp[0][2] = 0;

    if(N > 1)
    {
        dp[1][1] = stairs_vt[1];
        dp[1][2] = stairs_vt[0] + stairs_vt[1];
    }

    for(int i = 2; i < N; i++)
    {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stairs_vt[i];
        dp[i][2] = dp[i-1][1] + stairs_vt[i];
    }

    cout << max(dp[N-1][1], dp[N-1][2]) << '\n';

}


#endif


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();


    return 0;
}