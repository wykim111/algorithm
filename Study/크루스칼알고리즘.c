#include<stdio.h>
#include<stdlib.h>//퀵소트

#define TRUE 1
#define FALSE 0

typedef struct _edge
{
	int u;
	int v;
	int cost;

}Edge;


Edge e[1000];
int ret = 0;
/*
   해당정점의 루트정점을 초기화
*/
void Init_set(int* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = i;
	}
}

/*
   해당정점의 루트노드가 어떤것인지 확인하는 기능
*/
int Find_set(int* p, int u)
{

	if (p[u] == u)
		return u;

	int temp = Find_set(p, p[u]);

	return temp;
}
/*
   u정점과 v정점 각각의 루트 정점을 탐색하고, 병합하는 기능

*/
void Union_set(int* p, int u, int v)
{
	int temp_u = Find_set(p, u);
	int temp_v = Find_set(p, v);


	//u 정점의 루트 정점과 v 정점의 루트정점과 비교하여, 둘중 루트정점이 작은 것이 루트로 진행하여 병합
	if (temp_u < temp_v)
	{
		p[temp_v] = temp_u;//v의 루트정점을 u의 루트정점에 병합
	}
	else//temp_u > temp_v
	{
		p[temp_u] = temp_v;//u의 루트정점을 v의 루트정점에 병합
	}
}
/*
   사이클이 형성됐는지 유무 확인
*/
int Is_Cycle(int* p, int u, int v)
{
	int temp_u = Find_set(p, p[u]);
	int temp_v = Find_set(p, p[v]);

	if (temp_u == temp_v)
		return TRUE;

	return FALSE;
}

/*
   간선의 비용을 기준으로 오름차순 정렬
*/

int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;


	if (e1->cost > e2->cost)
		return 1;
	else if (e1->cost < e2->cost)
		return -1;
	else
		return 0;
}
/*
   해당정점들마다 루트 정점을 체크
*/
void tracking(int* p, int vertax)
{
	printf("각 정점의 루트노드 리스트\n");

	for (int i = 0; i < vertax; i++)
	{
		printf("%d정점의 병합된 정점 %d \n", i, p[i]);
	}
	printf("\n");
}

int main()
{
	int N, M;//정점과 간선의 수
	int parent[1000];


	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &(e[i].u), &(e[i].v), &(e[i].cost));
	}
	//간선의 비용을 기준으로 오름차순 정렬
	qsort(e, M, sizeof(Edge), cmp);

	//오름차순 간선 정렬 확인
	printf("정렬 확인\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].cost);
	}

	//Union_Find 진행
	/*
	   해당 정점(인덱스)의 루트 노드 초기화
	*/
	Init_set(parent, N);

	/*
	   각 정점들간의 루트정점 탐색 및 병합 진행
	*/
	for (int i = 0; i < M; i++)
	{
		if (Is_Cycle(parent, e[i].u, e[i].v) == 1)
			continue;
		else
		{
			ret += e[i].cost;
			Union_set(parent, e[i].u, e[i].v);

		}
	}
	tracking(parent, N);
	printf("%d\n", ret);

	return 0;
}
