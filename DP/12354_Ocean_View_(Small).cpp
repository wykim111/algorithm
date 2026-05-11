/*
	< DP - LIS >

	1. dp 모두 1로 초기화
	2. 증가 수열 로직
		for(i = 1 부터 N까지)
		{
			for( j = 0 ~ i까지)
			{
				if(home[j] < home[i])
				{
					dp[i] = max(dp[j]+1, dp[i]);
				}
			}
			//최대 증가수열 값 설정
		}
	3. (전체 집의 수(N) - 최대 증가수열의 길이) 출력
*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N;
vector<int> home_vt;
int max_len = 0;

void init()
{
	home_vt.clear();
}

void input()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int home;

		cin >> home;

		home_vt.push_back(home);
	}
}

void solution(int tc)
{


	cout << "Case #" << tc << ": " << (N - max_len) << '\n';
}

int main()
{
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		init();
		input();
		solution(i);
	}
}