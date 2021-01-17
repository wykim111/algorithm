#include<stdio.h>
#include<string.h>

int computer;
int link;
int map[101][101];
int visit[101];
int res = 0;

void dfs(int start)
{
	visit[start] = 1;

	for (int i = 1; i <= computer; i++)
	{
		if (map[start][i] == 1 && !visit[i])
		{
			res++;
			dfs(i);
		}
	}
}

int main()
{
	int u, v;

	memset(map, 0, sizeof(map));
	scanf("%d", &computer);
	scanf("%d", &link);

	for (int i = 0; i < link; i++)
	{
		scanf("%d %d", &u, &v);

		map[u][v] = 1;
		map[v][u] = 1;
	}
	dfs(1);
	printf("%d\n", res);

	return 0;
}
