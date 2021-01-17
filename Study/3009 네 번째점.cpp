/*
	직사각형좌표 3개애서 평행한 점은 이미 x와 y에 대한 데이터를 짝수개로 갖고 있다.
	홀수개 갖고 있는 점이 나머지 1개에 대한 좌표이다.
*/
#include<stdio.h>

int ypos[1001];
int xpos[1001];

int main()
{
	int retY, retX;

	for (int i = 0; i < 3; i++)
	{
		int y, x;

		scanf("%d %d", &x, &y);
		
		ypos[y]++;
		xpos[x]++;

	}

	for (int yIdx = 1; yIdx <= 1000; yIdx++)
	{
		if (ypos[yIdx] == 1)
		{
			retY = yIdx;
		}
	}
	for (int xIdx = 1; xIdx <= 1000; xIdx++)
	{
		if (xpos[xIdx] == 1)
		{
			retX = xIdx;
		}
	}

	printf("%d %d\n", retX, retY);


	return 0;
}