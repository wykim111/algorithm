/*
    <백트래킹>

    1. 분할에 사용된 어떤 수도 서로 같아서는 안 되며, 차이가 1이 나도 안 됨.

===========================================================================
    1. 탐색  시작
        go(int dep, int last_num, int sum)
        {
            if(sum == N)
            {
                //N으로 만들 수 있는 분할 된 수들을 출력.

                return;
            }

            for(int i=last_num+2; i <= N; i++)
            {
                if(sum + i > N)
                {
                    break;
                }

                num_vt.push_back(i);//현재 수를 벡터에 넣음
                go(dep+1, i, sum + i);
                num_vt.pop_back();//현재 수를 벡터에서 제거
            }
        
        }
    


*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> num_vt;

void input()
{
    cin >> n;
}

void go(int dep, int last_num, int sum)
{
    if(sum == n)
    {
        cout << n << "=";
        for(int i=0; i<num_vt.size()-1; i++)
        {
            cout << num_vt[i] << '+';
        }
        cout << num_vt[num_vt.size()-1] << '\n';

        return;
    }

    for(int i=last_num+2; i <= n; i++)
    {
        if(sum + i > n)
        {
            break;
        }

        num_vt.push_back(i);//현재 수를 벡터에 넣음
        go(dep+1, i, sum + i);
        num_vt.pop_back();//현재 수를 벡터에서 제거
    }
}

void solution()
{
    go(0, -1, 0);
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