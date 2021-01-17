#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int R, C;
char map[501][501];
//동서남북
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int wolf_flag = 0;
int check(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		//범위 벗어난 경우
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		if (map[ny][nx] == 'W')
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", &map[i]);

	}
	//늑대 탐색
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')//양 주변에 늑대가 있는지 없는지
			{
				wolf_flag += check(i, j);
			}
		}
	}

	if (wolf_flag == 0)
	{
		//양 주변에는 늑대가 없으며 울타리 설치 가능
		printf("1\n");
		//울타리 설치
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == '.')
				{
					map[i][j] = 'D';
				}
			}
		}
		
	}
	else
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}