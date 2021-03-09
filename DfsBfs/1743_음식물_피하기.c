/*
	동서남북 탐색
*/

#include<stdio.h>

char map[101][101];
int visit[101][101];
int N, M;//세로 가로
int K;//쓰레기의 수

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int maxCnt = 0;
int cnt = 0;

void init()
{
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			map[i][j] = '.';
		}
	}
}

void dfs(int curY, int curX)
{
	visit[curY][curX] = 1;
	cnt++;

	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dy[i];
		int nextX = curX + dx[i];

		//'.'이거나 맵의 범위를 벗어나는 경우
		if (nextY >= N || nextY < 0 || nextX >= M || nextX < 0 || visit[nextY][nextX] == 1)
		{
			continue;
		}

		if (map[nextY][nextX] == '#')
		{
			dfs(nextY,nextX);
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);

	init();

	for (int i = 0; i < K; i++)
	{
		int y, x;

		scanf("%d %d", &y, &x);
		map[y-1][x-1] = '#';
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '#' && !visit[i][j])
			{
				cnt = 0;
				dfs(i, j);

				if (cnt > maxCnt)
				{
					maxCnt = cnt;
				}
			}
		}
	}

	printf("%d\n", maxCnt);

	return 0;
}
