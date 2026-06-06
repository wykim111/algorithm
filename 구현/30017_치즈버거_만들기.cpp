/*
    < 구현 >

    1. 패티의 갯수와 치즈의 갯수 입력.
    2. 패티의 갯수를 기준으로 치즈의 갯수와의 차이를 구함.
    3. 차이가 0보다 큰 경우
        - 패티의 갯수가 많다는 의미이므로, 패티의 갯수 = 치즈의 갯수 + 1 설정
    4. 차이가 0보다 작은 경우
        - 치즈의 갯수가 많다는 의미이므로 치즈의 갯수 = 패티의 갯수 - 1 설정
    5. 패티와 치즈의 갯수가 같은 경우
       - 치즈의 갯수를 패티의 갯수 - 1 설정
    6. 패티와 치즈의 갯수 모두 더하여 출력.

*/

#include <iostream>
#include <algorithm>

using namespace std;

int P, C;

void input()
{
    cin >> P >> C;
}

void solution()
{
    int diff = P - C;
    
    if(diff > 0)
    {
        P = C + 1;
    }
    else if(diff < 0)
    {
        C = P - 1;
    }
    else
    {
        C = P - 1;
    }

    cout << P + C << "\n";
}

int main()
{
    input();
    solution();

    return 0;
}