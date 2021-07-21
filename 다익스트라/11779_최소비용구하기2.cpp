/*
	dijkstra 알고리즘O(N^2)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

#define INF 987654321

int graph[1001][1001];
int dist[1001];
int visit[1001];

int n, m;
int minRet;
int cityCnt = 0;
int trace[1001];

vector<int>trace_city;


void init()
{
	for (int i = 0; i < 1001; i++)
	{
		visit[i] = 0;
		dist[i] = INF;
		for (int j = 0; j < 1001; j++)
		{
			graph[i][j] = INF;
			if (i == j)
			{
				graph[i][j] = 0;
			}
		}
	}
}

void dijkstra(int start)
{
	//시작지점과 연결된 거리 업데이트
	for (int i = 1; i <= n; i++)
	{
		dist[i] = graph[start][i];
	}

	for (int i = 1; i <= n; i++)
	{
		//현재까지 최소 비용을 갖는 노드 찾기
		minRet = INF;
		for (int j = 1; j <= n; j++)
		{
			//방문하지 않은 노드들 중 최소 노드 찾기
			if (visit[j] == 0 && minRet > dist[j])
			{
				minRet = dist[j];
				start = j;
			}
		}

		visit[start] = 1;

		for (int k = 1; k <= n; k++)
		{
			if (visit[k] == 0 && dist[k] > (dist[start] + graph[start][k]))
			{
				dist[k] = (dist[start] + graph[start][k]);
				trace[k] = start;
			}
		}

	}
}

int main()
{
	int start, end;

	init();

	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;

		scanf("%d %d %d", &from, &to, &cost);

		if (graph[from][to] > cost)
		{
			graph[from][to] = cost;
			
		}

		
	}
	scanf("%d %d", &start, &end);

	
	dijkstra(start);

	//출력 : 최소비용, start와 end를 포함한 경로에 포함된 도시의 개수, 최소 비용을 갖는 경로에 방문하는 도시 순
	printf("%d\n", dist[end]);

	//배열의 데이터는 이전에 저장된 노드의 번호(인덱스)가 저장되어있다.
	int trace_idx = end;
	
	while (trace_idx > 0)
	{
		trace_city.push_back(trace_idx);
		trace_idx = trace[trace_idx];
	}
	trace_city.push_back(start);

	printf("%d\n", trace_city.size());

	for (int i = trace_city.size()-1 ; i >= 0; i--)
	{
		printf("%d ", trace_city[i]);
	}
	printf("\n");

	return 0;
}

