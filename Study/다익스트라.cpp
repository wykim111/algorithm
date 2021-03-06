/*
	최소비용 구하기
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#define INF 123456789

using namespace std;
vector<pair<int,int>> graph[1001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[1001];

int main()
{
	int n, m;
	int from, to, cost;
	int start, end;
	int now = 0, min_dist[1001], now_cost = INF;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back(make_pair(to, cost));
	}

	scanf("%d %d", &start, &end);

	//각 노드별 거리 초기화
	for (int i = 0; i <= n; i++)
	{
		min_dist[i] = INF;
		visit[i] = false;
	}

	//min_dist[start] = 0;
	pq.push(make_pair(0, start));//비용과 연결된 노드의 이름 순으로 입력
	//우선순위 큐로 최솟값을 가진 노드를 뽑아냄
	while (!pq.empty())
	{
		now_cost = pq.top().first;
		now = pq.top().second;
		pq.pop();
		//큐에 있는걸 뽑아낼때 같은 노드를 또 뽑아내기 문에
		//이전 비용이 지금 뽑은 비용보다 낮으면 스킵  
		if (min_dist[now] < now_cost || visit[now] == 1)
			continue;
		
		//최초 start 포함 우선순위 큐에 들어가서 탐색
		//처음에는 start노드의 넘버와 비용(0)이 들어감
		visit[now] = true;
		min_dist[now] = now_cost;
		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first;
			int dist = now_cost + graph[now][i].second;

			if (min_dist[next] > dist && (visit[next] == false))
			{
				min_dist[next] = dist;
				pq.push(make_pair(dist,next));
			}
		}
	}
	//for(int i=1;i<=n;i++)
		printf("%d\n", min_dist[end]);

	return 0;
}
