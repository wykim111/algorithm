/*
    < 구현 >

    1. 1-based array (N <= 4000)
    2. 명령어대로 처리
        1번 명령어 (1 i x)

        i번째 전구의 상태를 x로 변경합니다.

        2번 명령어 (2 l r)

        l번째부터 r번째까지 전구의 상태를 반전합니다. (0이면 1로, 1이면 0으로)

        3번 명령어 (3 l r)

        l번째부터 r번째까지 전구를 모두 끕니다. (모두 0으로 변경)

        4번 명령어 (4 l r)

        l번째부터 r번째까지 전구를 모두 켭니다. (모두 1로 변경)


*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int light_arr[4001];

typedef struct _command
{
    int cmd;
    int first;
    int second;
}command;

vector<command> cmd_vt;

void input()
{
    cin >> N >> M;

    for(int i=1;i <= N;i++)
    {
        cin >> light_arr[i];

    }

    for(int i=0;i<M;i++)
    {
        command stCommand;

        cin >> stCommand.cmd >> stCommand.first >> stCommand.second;

        cmd_vt.push_back(stCommand);
        
    }
}
// i번째 전구의 상태를 x로 변경합니다.
void one_cmd(int idx, int num)
{
    light_arr[idx] = num;
}

//l번째부터 r번째까지 전구의 상태를 반전합니다. (0이면 1로, 1이면 0으로)
void two_cmd(int l, int r)
{
    for(int i= l; i <= r;i++)
    {
        if(light_arr[i] == 1)
        {
            light_arr[i] = 0;
        }
        else
        {
            light_arr[i] = 1;
        }
    }
}

//l번째부터 r번째까지 전구를 모두 끕니다. (모두 0으로 변경)
void three_cmd(int l, int r)
{
    for(int i= l; i <= r;i++)
    {
        light_arr[i] = 0;    
    }
}
// l번째부터 r번째까지 전구를 모두 켭니다. (모두 1로 변경)
void four_cmd(int l, int r)
{
    for(int i= l; i <= r;i++)
    {
        light_arr[i] = 1;    
    }
}


void solution()
{
    for(int i=0;i<cmd_vt.size();i++)
    {
        int cmd = cmd_vt[i].cmd;
        int first = cmd_vt[i].first;
        int second = cmd_vt[i].second;

        if(cmd_vt[i].cmd == 1)
        {
            one_cmd(first, second);
        }
        else if(cmd_vt[i].cmd == 2)
        {
            two_cmd(first,second);
        }
        else if(cmd_vt[i].cmd == 3)
        {
            three_cmd(first, second);
        }
        else
        {
            four_cmd(first, second);
        }
    
    }

    for(int i=1;i<=N;i++)
    {
        cout << light_arr[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    input();
    solution();
    

    return 0;
}
