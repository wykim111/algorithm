/*
void go(int night, int remain_cnt) 
{
    // 1. 매 순간 정답(최대 밤의 수) 업데이트
    ans = max(ans, night);

    // 2. 종료 조건: 마피아 사망 or 마피아 승리(혼자 남음)
    if (!alive[mafia_id] || remain_cnt == 1) return;

    if (remain_cnt % 2 == 0)  // 밤 (짝수)
    {
        for (int i = 0; i < N; i++) 
        {
            if (i == mafia_id || !alive[i]) continue;

            // i번 시민 처단
            alive[i] = false;
            for (int j = 0; j < N; j++) 
            {
                if (alive[j]) guilt_point[j] += R[i][j]; // R[i][j]를 사용!
            }

            go(night + 1, remain_cnt - 1);

            // 유죄 지수 및 생존 여부 원상복구
            for (int j = 0; j < N; j++) 
            {
                if (alive[j]) guilt_point[j] -= R[i][j];
            }
         
            alive[i] = true;
        }
    } 
    else 
    { // 낮 (홀수)
        int target = get_max_idx();
        
        if (target == mafia_id) return; // 마피아 처형 시 종료

        // target 처단 (낮에는 점수 변동 없음)
        alive[target] = false;
        go(night, remain_cnt - 1);
        
        // 복구
        alive[target] = true;
    }
}

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> guilt_point_vt;
int R[16][16];
bool alive[16];
int mafia_id;
int ans = 0;

void input()
{
    cin >> N;

    guilt_point_vt.resize(N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> guilt_point_vt[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> R[i][j];
        }
    }
    cin >> mafia_id;
}

int get_max_idx()
{
    int max_idx = -1;
    int max_value = -1;

    for (int i = 0; i < N; i++)
    {
        if (!alive[i]) continue;

        if (guilt_point_vt[i] > max_value)
        {
            max_value = guilt_point_vt[i];
            max_idx = i;
        }
    }

    return max_idx;
}


void go(int night, int remain_cnt)
{
    ans = max(ans, night);

    //base case : 시민 혹은 마피아가 혼자 남은 경우
    if (remain_cnt == 1) return;


    if(remain_cnt % 2 == 0) // 밤
    {
        for (int i = 0; i < N; i++)
        {
            if (i == mafia_id || !alive[i]) continue;

            alive[i] = false;
            
            // i번 시민 처단
            for (int j = 0; j < N; j++)
            {
                if(i == j) continue;

                if (alive[j])
                {
                    guilt_point_vt[j] += R[i][j];
                } 
            }

            go(night + 1, remain_cnt - 1);

            for (int j = 0; j < N; j++)
            {
                if(i == j) continue;

                if (alive[j]) 
                {
                    guilt_point_vt[j] -= R[i][j];
                }
            }
            alive[i] = true;
        }
    }
    else // 낮
    {
#if 1
        int target = get_max_idx();
#else
        int target = max_element(guilt_point_vt.begin(), guilt_point_vt.end()) - guilt_point_vt.begin();
#endif
        if (target == mafia_id) return;

        alive[target] = false;
        go(night, remain_cnt - 1);
        alive[target] = true;
    }

}

void solution()
{
    for(int i = 0; i < N; i++)
    {
        alive[i] = true;
    }

    go(0, N);

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