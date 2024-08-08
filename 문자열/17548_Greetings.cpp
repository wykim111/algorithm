#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

void input()
{
    cin >> str;
}

void solution()
{
    int e_start = -1;
    int e_cnt = 0;
    string ans = "";

    // 'e' 시작점 찾기
    for(int i=0;i<str.size();i++)
    {
        if(str[i] == 'e')
        {
            e_start = i;
            break;
        }
    }

    // 'e'의 갯수 카운트
    for(int i=0;i<str.size()-1;i++)
    {
        if(str[i] == 'e')
        {
            ++e_cnt;
        }
    }

    ans += 'h';

    for(int i = 0; i < (2 * e_cnt); i++)
    {
        ans += 'e';
    }
    ans += 'y';

    cout << ans << '\n';

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
