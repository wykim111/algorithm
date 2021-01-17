#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<queue>

#define INF 1234567
using namespace std;
vector<pair<int, int>> graph[10001];//ù��°�� ����� ���, �ι�°�� ����� ����� ���
int visit[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int V, E;
int ret = 0;

void prim(int start)
{
	visit[start] = 1;
	//���������� ����� ������ pq�� push
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
		if (visit[now] == 1)	//2->3, 1->3�� ���� �켱����ť�� ���� ���� �湮�� ��� ��ŵ
			continue;
		visit[now] = 1;
		ret += now_dist;

		//���� ���� ����� ���� pq�� push
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