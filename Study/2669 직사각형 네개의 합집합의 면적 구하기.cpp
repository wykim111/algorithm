/*
	2차원 배열 선언
	직사각형 넓이만큼 x와 y의 좌표를 1로 마스킹
	1로 마스킹 한 곳 카운트
*/
#include<stdio.h>

int map[101][101];

int main()
{
	int maxX=0, maxY=0;
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int x1, y1,x2,y2;
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		//탐색할 범위 측정
		if (x2 > maxX)
		{
			maxX = x2;
		}

		if (y2 > maxY)
		{
			maxY = y2;
		}

		//직사각형 면적 1로 마스킹
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	//printf("maxX = %d maxY= %d\n", maxX, maxY);
	//1로 마스킹 된 면적 카운트
	for (int i = 0; i <= maxY; i++)
	{
		for (int j = 0; j <= maxX; j++)
		{
			if (map[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}