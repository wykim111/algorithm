#include<stdio.h>
#include<memory.h>

#define TRUE 1
#define FALSE 0
#define INF 1000000001

int map[1001][1001] = { 0, };
int visit[1001] = { 0, };
int dist[1001] = { 0, };
int u, v, w;
int N, M;
int ret=0;

//사실 초기화가 제일 중요!! 모두 INF로 만들어 주고
// input을 저장해야 함!
void Init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			map[i][j] = INF;
			if (i == j)
			{
				map[i][j] = 0;
			}
		}
		visit[i] = 0;
		dist[i] = INF;
	}
}

void prim(int s)
{
	int min;

	visit[s] = TRUE;
	dist[s] = 0;
	
	//시작점과 연결된  노드들  거리갱신
	for (int i = 0; i < N; i++)
	{
		dist[i] = map[s][i];
		//printf("%d ", dist[i]);
	}
	
	//연결된 지점중  최소거리 노드 탐색
	for (int i = 0; i < N; i++)
	{
		min = INF;
		//s = 0;
		for (int j = 0; j < N; j++)
		{
			if (visit[j] == FALSE && min > dist[j])
			{
				min = dist[j];
				s = j;
			}

		}//j

		if (min == INF)
			return;

		visit[s] = TRUE;
		printf("tracking:%d\n", s);
		ret += min;
		for (int k = 0; k < N; k++)
		{
			if (visit[k] == FALSE && (dist[k] > map[s][k]))
			{
				dist[k] = map[s][k];
			}
		}//k
	}
}

int main()
{
	int start, end;

	scanf("%d", &N);
	scanf("%d", &M);

	//사실 초기화가 제일 중요 모두 INF로 만들어 주고
	// input을 저장해야 함
	Init();

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		if (map[u][v] > w)
		{
			map[u][v] = w;
		}
		//	map[u][v] = w;
	}

	prim(0);
	/*
	for (int i = 1; i <= N; i++)
	{
	printf("%d ", dist[i]);
	}
	printf("\n");
	*/
	printf("%d\n", ret);
	//printf("dist = %d\n", dist[end]);
	return 0;
}
