/*
    1. 각 숫자에 해당하는 수열의 갯수를 저장
        1 = 1개
        2 = 2개
        3 = 3개
        .....
        n = n개

    2. 각 숫자를 벡터에 넣어줌.
    3. 벡터의 인덱스를 기준으로 (A) ~ (B) 사이로 뽑음
        3-1) 벡터의 0번째 인덱스에 미리 0을 넣고 시작(인덱스를 1부터 시작하기 위해)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A,B;
vector<int> vt;

void input()
{
    cin >> A >> B;
}

void solution()
{
    int sum = 0;

    vt.push_back(0);
    for(int i=1;i<=45;i++)
    {
        for(int j=0;j<i;j++)
        {
            vt.push_back(i);
        }
    }
#if 0
    cout << vt.size() << '\n';
#endif

    for(int i=A;i<=B;i++)
    {
        sum += vt[i];
    }

    cout << sum << '\n';

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
