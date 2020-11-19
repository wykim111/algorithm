/*
	1. 비용을 저장하는 배열을 초기화
	2. 다익스트라(시작 : 1~N) -> 도착지점 X번
	3. 다익스트라(시작 : X) -> 도착지점 1~N
	4. 2~3번의 도착지점을 더하여 최댓값 탐색

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<cstring>

#define INF 987654321

using namespace std;

priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, int>> graph[1001];
int N, M,X;
int dist[1001];
//int visit[1001];

void init()
{
	for (int i = 0; i <= 1000; i++)
	{
		dist[i] = INF;
		//visit[i] = 0;
	}
}

void dijkstra(int start)
{
	pq.push(make_pair(0,start));

	while (!pq.empty())
	{
		int curCost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < curCost )
		{
			continue;
		}
		dist[cur] = curCost;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int nextDist = curCost + graph[cur][i].second;

			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}
	}

}


int main()
{
	int sum = 0;
	int maxRet = -1;

	scanf("%d %d %d", &N, &M, &X);

	
	for (int i = 0; i < M; i++)
	{
		int start, end, cost;

		scanf("%d %d %d", &start, &end, &cost);
		graph[start].push_back(make_pair(end, cost));//단방향
		//graph[end].push_back(make_pair(start, cost));
	}
	//다익스트라를 처음에는 목표 지점 X의 최소거리를 구한다.
	//되돌아 올 때의 최소거리는 시작 지점은 X이고 목표지점은 시작지점이다.
	//다익스트라를 2번 호출하여,
	//dist[X] + dist[출발지점]하여 되돌오는 거리까지 구한다.
	for (int i = 1; i <= N; i++)
	{
		sum = 0;

		init();
		dijkstra(i);
		sum += dist[X];

		init();
		dijkstra(X);
		sum += dist[i];

		if (sum > maxRet)
		{
			maxRet = sum;
		}

	}
	printf("%d\n", maxRet);

	return 0;
}
