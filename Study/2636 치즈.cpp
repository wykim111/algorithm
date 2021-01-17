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
			//ġ� ���⿡ �� ��� ���
			if (map[i][j] == 1)
			{
				cheese++;

			}
			else //���� ġ� �����ų� ġ� ���⿡ ����ִ� ���
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

		//������ ��� ���
		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
		{
			continue;
		}
		//���⿡ ���� ġ��
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
			cheese = checkArea(); // ��� ��� 1�ð� ���� ġ�� ��
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