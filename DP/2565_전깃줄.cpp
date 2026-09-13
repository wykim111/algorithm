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
