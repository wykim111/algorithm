/*
    < DP >
    
    1. 재귀로 접근 하는 경우(SK = false, CY = true)
        go(int dep, int remain_cnt, bool turn)
        {
            if(remain_cnt == 0)
            {
                if(turn) // 
                    return ans = "SK"
                    
                return  ans = "CY";

                
            }

            str ans1, ans2, ans3;

            if(1개를 가져가는 경우)
            {
                go(dep+1, remain_cnt-1, !turn);
            }

            if(3개를 가져가는 경우)
            {
                go(dep+1, remain_cnt-3, !turn);
            }

            if(4개를 가져가는 경우)
            {
                go(dep+1, remain_cnt-4, !turn);
            }

        }

    2. DP로 접근하는 경우
        dp[i] = i개의 돌이 남았을 때, 선공이 이길 수 있는지 여부
        
        dp[1] = true;
        dp[2] = false;
        dp[3] = true;
        dp[4] = true;

        for(i = 5 ~ N)
        {
            if(dp[i-1] == false || dp[i-3] == false || dp[i-4] == false)
            {
                dp[i] = true;
            }
            else
            {
                dp[i] = false;
            }
        }


*/

#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool dp[1001];

void input()
{
    cin >> N;
}

void solution()
{
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    dp[4] = true;

    for(int i = 5; i <= N; i++)
    {
        if(!dp[i-1] || !dp[i-3] || !dp[i-4])
        {
            dp[i] = true;
        }
        else
        {
            dp[i] = false;
        }
    }

    if(dp[N])
    {
        cout << "SK\n";
    }
    else
    {
        cout << "CY\n";
    }
}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solution();

    return 0;
}