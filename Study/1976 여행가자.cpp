#include<stdio.h>

int N, M;
int map[201][201];
int course[1001]; // M�� ���డ�� ������ ����
int visit[201];

void dfs(int curV)
{
	visit[curV] = 1;

	for (int i = 1; i <= N; i++)
	{
		//�����ų� �̹� �湮�� ���
		if (map[curV][i] == 0 || visit[i] == 1)
			continue;
	//	visit[i] = 1;
		dfs(i);
	}


}
int main()
{
	int flag = 0;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &course[i]);
	}

	dfs(course[0]);
	for (int i = 0; i < M && !flag; i++)
	{
		if (!visit[course[i]]) 
			flag = 1;
	}
	if (flag == 0)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}