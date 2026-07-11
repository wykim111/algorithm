/*
    < 구현 >
    1. 대문자 알파벳 기준으로 "ILOVEYONSEI"는 총 이동거리의 합이 84이다.
    2. I를 선택하는 경우, 위 알파벳의 첫 문자이므로 84를 출력.
    3. I를 선택하지 않은 경우, 선택한 숫자에서 I까지의 거리를 계산하여, 84를 더한다.

*/

#include <iostream>
#include <algorithm>
#include <string>

#include <cmath>

using namespace std;

char ch;

void input()
{
    cin >> ch;
}

void solution()
{
    int sum = 84;

    if(ch == 'I')
    {
        cout << sum << "\n";
    }
    else
    {
        int dist = abs(ch - 'I');
        cout << sum + dist << "\n";
    }
}

int main()
{
    input();
    solution();

    return 0;
}