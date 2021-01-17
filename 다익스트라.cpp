/*
	�ּҺ�� ���ϱ�
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

	//�� ��庰 �Ÿ� �ʱ�ȭ
	for (int i = 0; i <= n; i++)
	{
		min_dist[i] = INF;
		visit[i] = false;
	}

	//min_dist[start] = 0;
	pq.push(make_pair(0, start));//���� ����� ����� �̸� ������ �Է�
	//�켱���� ť�� �ּڰ��� ���� ��带 �̾Ƴ�
	while (!pq.empty())
	{
		now_cost = pq.top().first;
		now = pq.top().second;
		pq.pop();
		//ť�� �ִ°� �̾Ƴ��� ���� ��带 �� �̾Ƴ��� ������
		//���� ����� ���� ���� ��뺸�� ������ ��ŵ  
		if (min_dist[now] < now_cost || visit[now] == 1)
			continue;
		
		//���� start ���� �켱���� ť�� ���� Ž��
		//ó������ start����� �ѹ��� ���(0)�� ��
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