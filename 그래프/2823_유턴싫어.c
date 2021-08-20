/*
	1. 각 칸에 빌딩이 있다면 'X'로 표시하고, 길이라면 '.'으로 표시
	2. 근처 네 방향(위,아래,오른쪽,왼쪽)의 길로 이동
	3. 이 마을에 막다른 길이 없다면, 상근이는 임의의 한 길에서 시작해서, 갈 수 있는 어떤 방향으로 움직이더라도, 유턴을 하지 않고 그 위치로 돌아올 수 있어야 한다.
	4. 유턴은 방금 이동한 방향의 반대 방향으로 이동하는 것을 말한다.
	- 
*/

#include<stdio.h>

int R, C;
char map[11][11];
int visit[11][11];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int is_blcoking(int y,int x)
{
	int block = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		//맵의 범위를 벗어난 경우
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
		{
			block++;
		}
		//빌딩이 있는 경우
		if (map[ny][nx] == 'X')
		{
			block++;
		}
	}

	if (block > 2)
	{
		return 1;
	}

	return 0;
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", map[i]);
	}


	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == '.')
			{
				if (is_blcoking(i,j) == 1)
				{
					printf("1\n");

					return 0;
				}
			}
		}
	}
	printf("0\n");

	return 0;
}
