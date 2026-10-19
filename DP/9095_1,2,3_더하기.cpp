#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#if 0 //재귀 버전
int T;
int N;
int cnt = 0;

void init()
{
    cnt = 0;
}

void input()
{
    cin >> N;

}

void go(int sum)
{
    if(sum > N) return;

    if(sum == N)
    {
        cnt++;
        return;
    }

    for(int i = 1; i <= 3; i++)
    {
        go(sum + i);
    }
}

void solution()
{
    go(0);

    cout << cnt << "\n";
}

#else //DP 버전

int T;
int N;
int dp[12];

void init()
{
    for(int i = 0; i < 12; i++)
    {
        dp[i] = 0;
    }
}

void input()
{
    cin >> N;
}

void solution()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= N; i++)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    cout << dp[N] << "\n";
}


#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        init();
        input();
        solution();
        
    }
  

    return 0;
}
