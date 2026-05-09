/*
    <dp>

    피보나치 수열로 접근

    출력 형식 : Hour X: Y cow(s) affected

*/

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll dp[491] = {0};

void input()
{
    cin >> N;
}

void solution()
{
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < N; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << "Hour " << N << ": " << dp[N-1] << " cow(s) affected\n";

}

int main()
{
    while(true)
    {
        input();

        if(N == -1)
        {
            break;
        }

        solution();
    }
}

