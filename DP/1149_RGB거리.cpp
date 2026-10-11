/*
    < DP >
    1. dp 상태 정의 
    dp[dep][color] = dep번째 집을 color 색으로 칠할 때의 최소 비용
    2. 점화식
        dp[dep][0] = min(dp[dep-1][1], dp[dep-1][2]) + rgb_vt[dep][0]
        dp[dep][1] = min(dp[dep-1][0], dp[dep-1][2]) + rgb_vt[dep][1]
        dp[dep][2] = min(dp[dep-1][0], dp[dep-1][1]) + rgb_vt[dep][2]
    3. 초기
        dp[0][0] = rgb_vt[0][0];
        dp[0][1] = rgb_vt[0][1];
        dp[0][2] = rgb_vt[0][2];
*/

#include <iostream>
#include <vector>
#include <algorithm>

#include <climits>
using namespace std;

//color vt 0 : R, 1 : G, 2 : B
int N;
vector<vector<int>> rgb_vt;
int ans = INT_MAX;

#if 0 //재귀 버전
void input()
{
    cin >> N;
    
    rgb_vt.resize(N, vector<int>(3));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> rgb_vt[i][j];
        }
    }
}

void go(int dep, int sum, int prev_color)
{
    if (dep == N)
    {
        ans = min(ans, sum);
        return;
    }

    //R : 0, G : 1, B : 2
    for (int i = 0; i < 3; i++)
    {
        if (i != prev_color)
        {
            go(dep + 1, sum + rgb_vt[dep][i], i);
        }
    }
}

void solution()
{
    go(0, 0, -1);
    cout << ans << "\n";
}
#else //dp 버전

void input()
{
    cin >> N;
    
    rgb_vt.resize(N, vector<int>(3));
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> rgb_vt[i][j];
        }
    }
}

void solution()
{
    vector<vector<int>> dp(N, vector<int>(3));
    
    dp[0][0] = rgb_vt[0][0];
    dp[0][1] = rgb_vt[0][1];
    dp[0][2] = rgb_vt[0][2];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb_vt[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb_vt[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb_vt[i][2];
    }

    ans = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    cout << ans << "\n";
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