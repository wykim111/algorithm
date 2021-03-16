/*
	현재 도시의 기름 값보다 다음 도시의 기름값이 큰 경우
	현재 도시에서 다음 도시 가는 거리만큼 기름을 채우고
	다음 다음 도시와 비교한다

	현재 도시의 기름 값보다 다음 도시의 기름값이 작은 경우
	현재 도시 기름값을 다음 도시 가는 거리만큼만 충전

	마지막 도시는 거리만 계산

*/

#include<stdio.h>

long long value[100001];
int dist[100000];
int N;
long long cost = 0;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d", &dist[i]);
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &value[i]);
	}

	int nextCity = 1;
	int curCity = 0;

	//초기 출발 기름 값 계산
	cost = (long long)value[0] * dist[0];
	while (nextCity < N-1)
	{
		//현재 도시의 기름 값보다 다음 도시의 기름값이 큰 경우
		
		//다음 도시와 그 다음 도시만큼 가는 거리 * 현재 기름 연산
		if (value[curCity] < value[nextCity])
		{
			cost += (long long)value[curCity] * dist[nextCity];
		}
		else // 현재 도시의 기름 값이 다음 도시보다 큰 경우
		{

			cost += (long long)value[nextCity] * dist[nextCity];
			curCity = nextCity;

		}
		nextCity = nextCity + 1;
	}
	printf("%lld\n", cost);

	return 0;
}
