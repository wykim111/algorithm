#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
int N, M, V;
int map[1001][1001];
bool visit[1001];
queue<int> Q;

void dfs(int cnt,int start)
{
	//³ëµåÅ½»öÀ» ÃÊ°úÇÒ °æ¿ì
	if (cnt == N)
		return;
	visit[start] = true;
	printf("%d ", start);
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i] && map[start][i] == 1)
		{
			dfs(cnt + 1, i);
		}
	}
}
void BFS(int start)
{
	Q.push(start);

	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		printf("%d ", cur);
		visit[cur] = 1;
		for (int i = 1; i <= N; i++)
		{
			if (map[cur][i] == 1 && !visit[i])
			{
				visit[i] = true;
				Q.push(i);
			}
		}

	}
	printf("\n");
}

int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		map[u][v] = 1;
		map[v][u] = 1;
	}
	dfs(0,V);
	printf("\n");
	memset(visit, 0, sizeof(visit));
	BFS(V);

	return 0;
}
