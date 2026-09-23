#include <iostream>

using namespace std;

#define MOD 16769023

void solution()
{
    int N;
    cin >> N;

    int power = (N + 1) / 2; 
    long long ans = 1;

    // 모듈러 연산을 적용한 거듭제곱 계산
    for (int i = 0; i < power; i++)
    {
        ans = (ans * 2) % MOD; 
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solution();
    return 0;
}
