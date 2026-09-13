/*
	< DP >

	[재귀로 접근해보는 경우]
	1.탐색 (A 전봇대에 존재하는 전깃줄의 위치를 유지 혹은 제거)
		go(dep)
		{
			if (dep == N)
			{
				if(교차 되지 않은 경우)
				{
					//전깃줄을 제거한 개수의 최솟값 갱신
				}

				return;
			}

			//전봇대의 dep번째 전깃줄을 제거 하는 경우
			remove_line_subset_vt.push_back(dep);
			go(dep+1);
			remove_line_subset_vt.pop_back();

			//전봇대의 dep번째 전깃줄을 유지 하는 경우
			go(dep+1);
		}
==========================================================================
	[DP로 접근해보는 경우]
	1. DP 배열 정의
		- dp[i] : i번째 전깃줄을 마지막으로 선택(유지)했을 때, 교차하지 않고 남길 수 있는 전깃줄의 최대 개수

	2. 탐색 및 점화식
		- 기본값 설정: dp[i] = 1 (어떤 전깃줄이든 최소한 자기 자신 1개는 유지할 수 있음)
		- i번째 전깃줄 앞의 모든 전깃줄(j = 0 ~ i-1)을 돌아보며 검사:
			if (pole_vt[j].b < pole_vt[i].b) // 과거의 B위치보다 현재 B위치가 크다면 (교차하지 않음)
			{
				dp[i] = max(dp[i], dp[j] + 1);
				// j번째까지 꼬이지 않은 최대 전깃줄 묶음에 나(i)를 이어 붙인 값과 현재 갱신된 값 중 최댓값 선택
			}



*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[501];

typedef struct _pole
{
	int a;
	int b;
}pole;

int N;
vector<pole> pole_vt;


bool cmp(pole line1, pole line2)
{
	
	return line1.a < line2.a;
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		pole temp_pole;

		cin >> temp_pole.a >> temp_pole.b;

		pole_vt.push_back(temp_pole);
	}
}

void solution()
{
	int max_line = 0;

	sort(pole_vt.begin(), pole_vt.end(), cmp);

	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			//교차 하지 않은 조건
			if (pole_vt[j].b < pole_vt[i].b)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		max_line = max(max_line, dp[i]);
	}

	cout << N - max_line << '\n';
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
