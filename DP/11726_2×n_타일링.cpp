/*
    < dp >

    1. width가 1인 경우, 2인 경우로 나누어 탐색.
        go(width)
        {
            if(width == N)
            {
        
                return 0;
            }

            
            if((width + 1) <= N)
            {
                dp[width] += go(width + 1) + 1;
            }

            if((width + 2) <= N)
            {
                dp[width] += go(width + 2) + 1;
            }



        }

*/

#include <iostream>
#include <algorithm>

#include <cstring>

#define MOD 10007

using namespace std;

int N;
int dp[1001];

void input()
{
    cin >> N;
}

int go(int width)
{
    // base case
    if(width == N)
    {
        return 1;
    }

    if(dp[width] != 0)
    {
        return dp[width];
    }

    
    if((width + 1) <= N)
    {
        dp[width] += go(width + 1) % MOD;
    }

    if((width + 2) <= N)
    {
        dp[width] += go(width + 2) % MOD;
    }

    return dp[width] % MOD;
}

void solution()
{
    memset(dp, 0x00, sizeof(dp));
    go(0);

    cout << dp[0] << "\n";

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}