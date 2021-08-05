/*
	플로이드 알고리즘

	1. 거쳐가는 정점을 중심으로 O(N^3)으로 거리를 업데이트

	for(j=0 ~ N)//거쳐가는 정점
	{
		for(i=0 ~N)
		{
			for(k=0 ~ N)
			{
				if( dist[i][k] > dist[i][j] + dist[j][k])
				{
					dist[i][k] > dist[i][j] + dist[j][k]
				}
			}
		}
	}
	2. 양방향 그래프 
	
*/
#include<stdio.h>

#define INF 987654321

int map[101][101];
int dist[101][101];
int n, m;

void init()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= 100; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
				
				continue;
			}

			map[i][j] = INF;
		}
	}
}

void floyd()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;

			//거리 변수 초기화
			if (map[i][j] != INF)
			{
				dist[i][j] = map[i][j];
			}
			else
			{
				dist[i][j] = INF;
			}
			
		}
	}
	for (int j = 1; j <= n; j++) // via : 거쳐가는 정점
	{
		for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				//목적지가 같은 정점을 보는 경우 스킵
				if (i == k)
					continue;
				//거쳐가는 지점이 출발지나 목표지에 같은 경우도 스킵
				if (j == i || j == k)
					continue;

				if (dist[i][k] > (dist[i][j] + dist[j][k]))
				{
					dist[i][k] = (dist[i][j] + dist[j][k]);
				}
			}
		}
	}
}

void Print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] != INF)
			{
				printf("%d ", dist[i][j]);
			}
			else
			{
				printf("0 ");
			}
		}
		printf("\n");
	}
}


int main()
{
	scanf("%d", &n);
	scanf("%d", &m);

	init();

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);

		if (map[from][to] > cost)
		{
			map[from][to] = cost;

			continue;
		}



	}

	floyd();

	Print();

	return 0;
}
