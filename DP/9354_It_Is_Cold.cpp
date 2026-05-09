/*
    <dp>

1) 선풍기 개수만큼 선풍기 속도와 방향을 입력받는다. 방향이 A라면 속도를 음수로 저장한다.
2) result를 0으로 초기화하고 최종 선풍기의 속도가 양수라면 값을 업데이트한다. 
3) 뒤에서부터 선풍기를 탐색하며 result에 속도를 더한다. 이때, result 값이 음수가 된다면 0으로 업데트한다. 
4) 최종 result를 출력한다. 
    
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int T;
int N;
vector<ll> fan_vt;
ll result = 0;

void init()
{
    result = 0;
    fan_vt.clear();
}

void input()
{
    cin >> N;

    //N개의 선풍기 속도
    for(int i=0;i < N;i++)
    {
        int fan_data;

        cin >> fan_data;

        fan_vt.push_back(fan_data);
    }

    //N개의 선풍기 방향 (T이면 양수, A이면 음수)
    for(int i=0; i < N;i++)
    {
        string fan_dir_str;

        cin >> fan_dir_str;

        if(fan_dir_str == "A")
        {
            fan_vt[i] *= (-1);
        }
        
    }
    
}

void solution()
{
#if 0
    cout << "입력값 출력 : " << '\n';
    for(int i = 0; i < N; i++)
    {
        cout << fan_vt[i] << ' ';
    }
    cout << '\n';
#endif

    //끝에서부터 탐색 시작.
    // 만약 현재 선풍기에 대해 연산한 값이 음수이면 0으로 초기화.
    for(int end = fan_vt.size()-1; end >= 0; end--)
    {
        ll cur_fan_data = fan_vt[end];

        result += cur_fan_data;

        if(result < 0)
        {
            result = 0;
        }
    }

    cout << result << '\n';

}

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--)
    {
        init();
        input();
        solution();
    }

    return 0;
}