/*
	< 백트래킹 - 부분집합>

	1. 모든 경우의 부분집합을 탐색
    go(dep, bean_mask)
    {
		// base case :  모든 콩에 대한 선택이 끝남
        if (모든 원소를 다 탐색한 경우)
        {    
            // 1. 농부 검증 (이 조합을 공짜로 줄 수 있는 농부가 있는지 확인)
            bool is_possible = false;

            for (모든 농부 i에 대해)
            {
                // 핵심 조건: 농부의 작물이 내 목표(bean_mask)의 부분집합인가?
                if ((bean_mask & farmer_mask[i]) == farmer_mask[i])
                {
                    is_possible = true;
                    break; // 안전한 농부가 한 명이라도 있으면 공짜 해결 (비용 0)
                }
            }
            // 2. 경우 계산 (비용 갱신)
            // 도와줄 농부가 한 명도 없는 경우 (최악의 시나리오 -> 전부 사야 함)
            if (is_possible == false)
            {
                int total_value = 0;

                // 현재 마스크에 포함된 콩들의 가치를 모두 더함
                for (콩 j = 0 부터 B-1 까지)
                {
                    if (bean_mask & (1 << j))
                    {
                        total_value += V[j];
                    }
                }

                // 최댓값(우리가 준비해야 할 예산) 업데이트
                max_ans = max(max_ans, total_value);
            }

            return;
        }
        // 현재 dep원소를 포함하는 경우
        go(dep + 1, bean_mask | (1 << dep));

        // 현재 dep원소를 포함하지 않는 경우
        go(dep + 1, bean_mask);
    }

2. 경우 계산 요약
    2-1. 농부 검증: 농부가 가진 콩이 내가 원하는 콩(bean_mask)의 부분집합인지 확인.
         - 참이면: 그 농부는 나에게 필요한 콩만 주므로 안전함 -> 비용 0원.
    2-2. 비용 계산: 안전한 농부가 단 한 명도 없을 때.
         - bean_mask에 포함된 모든 콩의 가격을 더해서 max_ans(최대 비용) 갱신.


*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
#include <cstdlib>

#define DEBUG 0

using namespace std;

int B;
vector<int> V_vt; //빈 타입별로 가치를 저장하는 벡터 필요하다.
int T; //농부의 수
vector<int> farmer_vt[100];
unsigned int farmer_bean_mask[100];

int max_ans = 0;

void input()
{
	cin >> B;

	for (int i = 0; i < B; i++)
	{
		int bean;

		cin >> bean;

		V_vt.push_back(bean);
	}

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M;

		cin >> M;

		for (int j = 0; j < M; j++)
		{
			int bean_type;

			cin >> bean_type;

			farmer_vt[i].push_back(bean_type);
			farmer_bean_mask[i] |= (1 << (bean_type - 1)); // bean_type은 1-based이므로 0-based로 변환
		}
	}


}

void go(int dep, unsigned int current_bean_mask)
{
	if (dep == B)
	{
#if DEBUG //debug
		// current_bean_mask 확인
		for (int i = 0; i < T; i++)
		{
			for (int j = 0; j < farmer_vt[i].size(); j++)
			{
				if (current_bean_mask & (1 << (farmer_vt[i][j] - 1))) // bean_type은 1-based이므로 0-based로 변환
				{
					// 농부 i가 가져온 콩 확인
					cout << "농부 " << i << "가 가져온 콩: " << farmer_vt[i][j] << endl;
				}
			}

		}
#endif

		bool is_possible = false;

		for (int i = 0; i < T; i++)
		{
			if ((current_bean_mask & (farmer_bean_mask[i])) == farmer_bean_mask[i])
			{
				is_possible = true;

				break;
			}
		}



		if (is_possible == false)
		{
			//cout << "is_possible == false인 경우 발생" << "\n";

			int total_value = 0;

			for (int i = 0; i < B; i++)
			{
				// 현재 부분집합에 포함된 콩들의 가치 합산
				if (current_bean_mask & (1 << i))
				{
					total_value += V_vt[i];
				}
			}

			max_ans = max(max_ans, total_value);
		}


		return;
	}

	// 현재 dep번쨰 콩을 포함하는 경우
	go(dep + 1, current_bean_mask | (1 << dep));

	// 현재 dep번쨰 콩을 포함하지 않은 경우
	go(dep + 1, current_bean_mask);

}


void solution()
{

	go(0, 0x00);

	cout << max_ans << "\n";
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
