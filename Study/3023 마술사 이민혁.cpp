/*
왼쪽 위 1/4만 디자인한다. 그 다음 대칭시켜 오른쪽 위를 만들고, 다시 대칭시켜서 아래 부분을 모두 만든다.
에러는 원래 '#'이어야 하는 칸을 '.'로 바꾸거나 '.'이어야 하는 칸을 '#'로 바꾸는 것이다.
*/
#include<stdio.h>

int R, C;
char map[51][51];
int A, B; // 에러의 위치
char retMap[102][102];

void Print()
{
	for (int i = 0; i < 2 * R; i++)
	{
		for (int j = 0; j < 2 * C; j++)
		{
			printf("%c", retMap[i][j]);
		}
		printf("\n");
	}
}
void errorSearch(int y,int x)
{
	if (retMap[y][x] == '.')
	{
		retMap[y][x] = '#';
	}
	else if (retMap[y][x] == '#')
	{
		retMap[y][x] = '.';
	}
}
int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", map[i]);
		while (getchar() != '\n');
	}
	//에러 입력
	scanf("%d %d", &A, &B);

	//좌측 상단 대칭
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			retMap[i][j] = map[i][j];
		}
	}

	//우측 상단 대칭
	for (int i = 0; i <R ; i++)
	{
		for (int j = C; j < 2*C; j++)
		{
			retMap[i][j] = map[i][(2 * C) - j - 1];
		}
	}


	//좌측 하단 대칭
	for (int i = R; i < 2*R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			retMap[i][j] = map[(2*R)-1-i][j];
		}
	}
	//우측 하단 대칭
	for (int i = R; i < 2 * R; i++)
	{
		for (int j = C; j < 2 * C; j++)
		{
			//input으로 사용된 맵에는 해당 위치에 대한 정보가 없기 떄문에
			//출력용 맵의 정보를 읽어 들인다.
			retMap[i][j] = retMap[(2 * R) - 1 - i][j];
		}
	}

	errorSearch(A-1,B-1);
	Print();
	

	return 0;
}