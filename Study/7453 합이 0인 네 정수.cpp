
/*
	1. 4개의 배열을 2개로 나눕니다. {첫 번째 배열, 두 번째 배열}, {세 번째 배열, 네 번째 배열}

2. 첫 번째 배열과 두 번째 배열의 가능한 모든 합은 미리 전처리 할 필요 없고 
   세 번째 배열과 네 번째 배열의 모든 가능한 합만 미리 전처리해두고 오름차순으로 정렬합니다.
*/
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;

int N;
ll arr[4][4001];
vector<ll> vt;
ll ret = 0;

int main()
{
	scanf("%d", &N);

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			scanf("%lld", &arr[i][j]);
		}
	}
	//3번쨰 배열에서 각 원소가 4번쨰 배열 원소마다 연산 진행
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vt.push_back((arr[2][i] + arr[3][j]));
		}
	}

	sort(vt.begin(), vt.end());
	// 해당 데잉터가 존재하는 최초 지점과 마지막 지점 탐색
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ll GroupA = arr[0][i] + arr[1][j];
			ll start = lower_bound(vt.begin(), vt.end(), -GroupA) - vt.begin();
			ll end = upper_bound(vt.begin(), vt.end(), -GroupA) - vt.begin();

			if ((GroupA + vt[start]) == 0)
			{
				ret += (end - start);
			}
		}
	}
	printf("%lld\n", ret);

	return 0;
}