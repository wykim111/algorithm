/*
    < 구현 >

    1. 용어 정의
        적정 체중 (x), 실제 체중(y)
    2. 입력
        2-1. "# 0"을 마지막 줄로 하여 시나리오가 종료
        2-2. 모든 시나리오가 끝나면 "0 0"이 입력
    
    3. 판단
        3-1. 2*y > x && y < 2*x : ":-)"을 출력
        3-2. 사망(y <= 0 또는 is_dead) : "RIP"를 출력
        3-3. 이외인 경우 : ":-("을 출력

    4. 질의 
        4-1. 'E'와 숫자를 입력해 펫을 운동시킬 수 있습니다. n 감소
        4-2. 'F'와 숫자를 입력해 펫에게 먹이를 줄 수 있습니다. n 증가
        4-3. 펫이 중간에 죽는다면 이후의 작용은 무시하되 입력(# 0)은 끝까지 소진
*/

#include <iostream>
#include <algorithm>

using namespace std;

int x, y; // 적정 체중, 실제 체중
int tc = 1;
bool is_dead = false;

int get_status(char cmd, int cal_weight)
{
    int total_weight = y;

    if(cmd == 'E')
    {
        total_weight -= cal_weight;
    }
    else if(cmd == 'F')
    {
        total_weight += cal_weight;
    }

    return total_weight;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) // 프로세스 루틴
    {
        cin >> x >> y;

        // 프로세스 루틴 종료
        if((x == 0) && (y == 0))
        {
            break;
        }

        is_dead = false;

        // 특정 시나리오 루틴
        while(true)
        {
            char cmd;
            int n;

            cin >> cmd >> n;

            // 특정 시나리오 종료 (# 0이 들어올 때까지 무조건 루프 유지)
            if((cmd == '#') && (n == 0))
            {
                break;
            }

            // 살아있는 동안에만 체중 반영
            if(!is_dead)
            {
                y = get_status(cmd, n);

                if(y <= 0)
                {
                    is_dead = true;
                }
            }
        }

        // 강아지 기분 판정 및 출력
        if(is_dead)
        {
            cout << tc << " RIP" << '\n';
        }
        else if(2 * y > x && y < 2 * x)
        {
            cout << tc << " :-)" << '\n';
        }
        else
        {
            cout << tc << " :-(" << '\n';
        }
        
        tc++;
    }

    return 0;
}