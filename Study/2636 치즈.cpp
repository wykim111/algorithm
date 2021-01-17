#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int map[100][100];
int visit[100][100];
int N, M;
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1,0, 0 };

int checkArea()
{
	int cheese = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//치즈가 공기에 안 닿는 경우
			if (map[i][j] == 1)
			{
				cheese++;

			}
			else //원래 치즈가 없었거나 치즈가 공기에 닿아있는 경우
			{
				map[i][j] = 0;
			}
		}
	}
	return cheese;
}
void dfs(int curY, int curX)
{
	visit[curY][curX] = 1;

	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dy[i];
		int nextX = curX + dx[i];

		//범위를 벗어난 경우
		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
		{
			continue;
		}
		//공기에 닿은 치즈
		if (map[nextY][nextX] > 0)
		{
			map[nextY][nextX]++;
		}

		if (map[nextY][nextX] == 0 && visit[nextY][nextX] == 0)
		{
			dfs(nextY, nextX);
		}
	}
}


int main()
{
	int cheese = 0;
	int Time = 0;
	
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}


	while (1)
	{
		if ( checkArea() != 0)
		{
			cheese = checkArea(); // 모두 녹기 1시간 전의 치즈 양
			dfs(0, 0);
			Time++;
			
			memset(visit, 0, sizeof(visit));
			
		}
		else
		{
			break;
		}
	}

	printf("%d\n", Time);
	printf("%d\n", cheese);
	
	return 0;
}