/*
		1. 캔디 타입 정의
		2. 각 캔디가 있는지 없는지 현재 좌표에서  1번쨰 캔티의 경우 현재위치에서 y축으로부터 +3, 
		   2번째 캔디는 x축으로부터 +3으로 현재 캔디가 존재하는지 탐색

*/
#include<stdio.h>
#include<string.h>


//사탕 타입
char candy1[3] = { '>','o','<' };
char candy2[3] = { 'v','o','^' };

int t;
int r, c;
char map[401][401];

int checkType1(int y, int x)
{
	int idx = 0;

	for (int nextX = x ; nextX < x + 3; nextX++)
	{
		if (nextX >= c || map[y][nextX] != candy1[idx])
		{
			return 0;
		}
		idx++;
	}
	return 1;
}

int checkType2(int y, int x)
{
	int idx = 0;

	for (int nextY = y; nextY < y + 3; nextY++)
	{
		
		if (nextY >= r || map[nextY][x] != candy2[idx])
		{
			return 0;
		}
		idx++;
	}
	return 1;
}


int main()
{
	scanf("%d", &t);

	while (t--)
	{
		int ret = 0;

		scanf("%d %d", &r, &c);
		while (getchar() != '\n');

		memset(map, 0, sizeof(map));

		for (int i = 0; i < r; i++)
		{
			scanf("%s", map[i]);
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (checkType1(i, j) == 1)
				{
					ret++;
				}
				if (checkType2(i, j) == 1)
				{
					ret++;
				}
			}
		}

		printf("%d\n", ret);

	}
	return 0;
}