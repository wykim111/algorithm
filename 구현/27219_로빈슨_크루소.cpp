/*
    < 구현 >

    1. 5로 나눈 몫은 'V' 출력.
    2. 5로 나눈 나머지의 갯수만큼 'I'를 출력.

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;

void input()
{
    cin >> N;
}

void solution()
{
    int v_cnt = N / 5;
    int i_cnt = N % 5;

    // 'V' 출력.
    for(int i=0; i < v_cnt; i++)
    {
        cout << "V";
    }

    // 'I' 출력.
    for(int i=0; i < i_cnt; i++)
    {
        cout << "I";
    }

    cout << '\n';

}

int main()
{
    input();
    solution();

    return 0;
}