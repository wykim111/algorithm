#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> map[51];

int N, M;//노드 간선의 수
//int map[51][51];
int visit[51];
int ret = 1e9;
int minRet = 1e9;

void dfs(int start, int dest, int level)
{
	if (start == dest)
	{
		ret = min(ret, level);
		//printf("start = %d dest = %d level = %d\n",start,dest, level);
		return;
	}
	for (int i = 0; i < map[start].size(); i++)
	{
		//이미 방문하거나 간선이 연결 안 된 경우
		if (visit[map[start][i]] == 1)
			continue;
		//printf("start = %d i = %d\n", start, i);
		visit[map[start][i]] = 1;
		dfs(map[start][i], dest, level + 1);
		visit[map[start][i]] = 0;
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int A, B;

		scanf("%d %d", &A, &B);

		map[A].push_back(B);
		map[B].push_back(A);
	}
	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		minRet = 0;
		visit[i] = 1;

		for (int j = 1; j <= N; j++)
		{
			ret = 1e9;

			if (visit[j] == 1)
				continue;

			dfs(i, j, 0);
			minRet += ret;
			if (i == 2)
				printf("ret = %d\n", ret);
		}

		visit[i] = 0;
		//printf("minRet = %d\n", minRet);

	}

	//printf("%d\n", minRet);

	return 0;
}