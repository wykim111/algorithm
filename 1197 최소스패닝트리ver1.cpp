/*
	스패닝 트리중에 프림알고리즘을 이용
	프림알고리즘: 최소 간선을 갖고 있는 노드들만 찾아서 연결(다익스트라와 일부 유사)
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

#define INF 123456789
using namespace std;

vector < pair<int, int>> graph[10001];//첫번째는 노드, 두번째는 비용

int V, E;
int dist[10001];
int visit[10001];
int ret = 0;//최소 가중치 저장

void prim(int start)
{
	//노드별 비용과 방문배열 초기화
	for (int i = 0; i <= V; i++)
	{
		visit[i] = 0;
		dist[i] = INF;
	}
	dist[1] = 0;

	//최소비용인 노드 찾기
	for (int i = 1; i <= V; i++)
	{
		int min_dist = INF;
		int now = 0;
		
		for (int j = 1; j <= V; j++)
		{
			//방문 안 했으면서 최소노드를 갖는 노드 조건
			if (!visit[j] && min_dist > dist[j])
			{
				now = j;
				min_dist = dist[j];
			}
		}
	
		visit[now] = 1;
		ret += min_dist;//최소 노드의 비용 저장


		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first; //현재 노드와 연결된 노드들
			int update_cost = graph[now][i].second;//연결된 노드의 비용

			if (!visit[next] && (dist[next] > update_cost))
			{
				dist[next] = update_cost;
			}

		}
	}
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++)
	{
		int u, v, cost;
		scanf("%d %d %d", &u, &v,&cost);

		graph[u].push_back(make_pair(v, cost));
		graph[v].push_back(make_pair(u, cost));

	}
	prim(1);
	printf("%d\n", ret);

	return 0;
}