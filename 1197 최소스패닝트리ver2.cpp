#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>

#define INF 1234567
using namespace std;
vector<pair<int, int>> graph[10001];//첫번째는 연결된 노드, 두번째는 연결된 노드의 비용
int visit[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E;
int ret = 0;

void prim(int start)
{
	visit[start] = 1;
	//시작지점과 연결된 노드들을 pq에 push
	for (int i = 0; i < graph[start].size(); i++)
	{
		int next = graph[start][i].first;
		int next_dist = graph[start][i].second;

		pq.push(make_pair(next_dist, next));
	}
	while (!pq.empty())
	{
		int now = pq.top().second;
		int now_dist = pq.top().first;

		pq.pop();
		if (visit[now] == 1)	//2->3, 1->3과 같이 우선순위큐에 의해 먼저 방문한 경우 스킵
			continue;
		visit[now] = 1;
		ret += now_dist;

		//현재 노드와 연결된 노드들 pq에 push
		for (int i = 0; i < graph[now].size(); i++)
		{
			int after = graph[now][i].first;
			int after_dist = graph[now][i].second;

			pq.push(make_pair(after_dist,after));
		}

	}
}

int main()
{
	scanf("%d %d", &V, &E);

	for (int i = 0; i < E; i++)
	{
		int u, v;
		int cost;

		scanf("%d %d %d", &u, &v, &cost);

		graph[u].push_back(make_pair(v, cost));
		graph[v].push_back(make_pair(u, cost));

	//	pq.push(make_pair(cost, v));
	}
	prim(1);

	printf("%d\n", ret);
	return 0;
}