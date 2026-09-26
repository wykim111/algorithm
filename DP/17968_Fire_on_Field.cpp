/*
	< DP >
	사전 조건 : i >= 2, i-2k >= 0, k > 0
	1. 일반항 : A[i] != ((2*A[i-k]) - A[i-2k])
	2. 완전탐색

for (int i = 2; i <= n; i++)
{
	int value = 1; // 1부터 후보 시작

	while (true) // 조건에 맞는 value를 찾을 때까지 무한 반복
	{
		bool isValid = true; //현재 value가 유효한지 체크하는 플래그

		// 조건: i - 2k >= 0  
		for (int k = 1; i - (2 * k) >= 0; k++)
		{
			// 만약 하나라도 등차수열 조건을 위반하는 경우
			if (value == (2 * A[i - k] - A[i - 2 * k]))
			{
				isValid = false; // 이 value는 탈락!
				break; // 더 이상 k를 검사할 필요 없음
			}
		}

		// 모든 k를 다 돌았는데도 isValid가 true인 경우
		if (isValid == true)
		{
			A[i] = value; //A[i]에 저장
			break;
		}

		// 무사 통과에 실패했다면 value를 1 증가시키고 while문 처음부터 다시 검사
		value++;
	}
}
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[1001];

void input()
{
	cin >> N;
}

void solution()
{
	
	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		int value = 1;

		while (true)
		{
			bool is_valid = true;

			// 조건: i - 2k >= 0  
			for (int k = 1; i - (2 * k) >= 0; k++)
			{
				// 만약 하나라도 등차수열 조건을 위반하는 경우
				if (value == ((2 * dp[i - k]) - dp[i - 2 * k]))
				{
					is_valid = false; 
					break; 
				}
			}

			// 모든 k를 다 돌았는데도 isValid가 true인 경우
			if (is_valid == true)
			{
				dp[i] = value; //A[i]에 저장
				break;
			}

			// 무사 통과에 실패했다면 value를 1 증가시키고 while문 처음부터 다시 검사
			value++;
		}
		
	}

	cout << dp[N] << '\n';
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