/*
	���д� Ʈ���߿� �����˰����� �̿�
	�����˰���: �ּ� ������ ���� �ִ� ���鸸 ã�Ƽ� ����(���ͽ�Ʈ��� �Ϻ� ����)
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>

#define INF 123456789
using namespace std;

vector < pair<int, int>> graph[10001];//ù��°�� ���, �ι�°�� ���

int V, E;
int dist[10001];
int visit[10001];
int ret = 0;//�ּ� ����ġ ����

void prim(int start)
{
	//��庰 ���� �湮�迭 �ʱ�ȭ
	for (int i = 0; i <= V; i++)
	{
		visit[i] = 0;
		dist[i] = INF;
	}
	dist[1] = 0;

	//�ּҺ���� ��� ã��
	for (int i = 1; i <= V; i++)
	{
		int min_dist = INF;
		int now = 0;
		
		for (int j = 1; j <= V; j++)
		{
			//�湮 �� �����鼭 �ּҳ�带 ���� ��� ����
			if (!visit[j] && min_dist > dist[j])
			{
				now = j;
				min_dist = dist[j];
			}
		}
	
		visit[now] = 1;
		ret += min_dist;//�ּ� ����� ��� ����


		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i].first; //���� ���� ����� ����
			int update_cost = graph[now][i].second;//����� ����� ���

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