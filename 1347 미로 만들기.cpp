/*
	1.미로 안의 한칸에 남쪽을 바라본다 하였으므로 50*2로 배열의 사이즈 정함
	2. startY,startX, endY,endX로 범위를 정한뒤 출력
	3. 좌우는 회전만 할 뿐 나아가지는 않음

*/
#include<stdio.h>
#include<string.h>

//남서북동
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };
char str[50];
int map[101][101];
int dir = 0; //dy,dx는 0이라는 의미(남쪽을 바라보고 있음)
int main()
{
	int len;
	int N;
	int curX = 50, curY = 50;
	int startY = curY, startX = curX, endY = curY, endX = curX;

	scanf("%d", &N);
	scanf("%s", str);

	map[curY][curX] = 1;
	
	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'F')
		{
			//남쪽으로 이동
			curY += dy[dir];
			curX += dx[dir];

			map[curY][curX] = 1;
			//범위 조정
			if (curY > endY)
				endY = curY;
			if (curY < startY)
				startY = curY;
			if (curX > endX)
				endX = curX;
			if (curX < startX)
				startX = curX;
		}
		else if (str[i] == 'L')
		{
			//동쪽으로 회전
			dir = (dir+3) % 4;

		}
		else if (str[i] == 'R')
		{
			//서쪽으로 회전
			dir = (dir + 1) % 4;
		}
	}

	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (map[i][j] == 1)
			{
				printf(".");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}

	return 0;
}