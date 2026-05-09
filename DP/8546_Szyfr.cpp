/*
    <DP>

    1. n부터 m까지 피보나치 수열읠 값 구한다.
    2. 각 자리의 수를 10으로 나누어 나머지를 구함(입력한 수의 가장 마지막 자리 값)
    3. n부터 m까지 2번으로 구한 나머지를 모두 이어 붙인다.

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

ll dp[100000001] = {0};
int n, m;

string ans_str = "";

void input()
{
    cin >> n >> m;
}

void solution()
{
    dp[1] = 1;
    dp[2] = 1;

    for(int i = 3; i <= m; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]);

    }

    for(int start = n; start <= m; start++)
    {
        ans_str += to_string(dp[start] % 10);
    }

    cout << ans_str << "\n";
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
