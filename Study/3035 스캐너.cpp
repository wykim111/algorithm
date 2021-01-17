/*
	1. R C ZR ZC 입력
	2. 원본 데이터와 복사 데이터를 두고 원본 데이터를 ZR* ZC만큼 출력

	for(int i=0;i<R;i++)
	{
		for(int Row = 0;Row < ZR;Row++,puts(" "))
		{
			for(int j=0;j<C;j++)
			{
				for(int Col = 0;Col <ZC;Col++)
				{
					printf("%c",map[i][j])

				}
			}
	
	}
*/
#include<stdio.h>
#include<string.h>

char map[51][51];
int R, C, ZR, ZC;

int main()
{
	scanf("%d %d %d %d", &R, &C, &ZR, &ZC);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", map[i]);
	}

	for (int i = 0; i < R * ZR; i++,puts(" "))
	{
		for (int j = 0; j < C*ZC; j++)
		{
			printf("%c", map[i / ZR][j / ZC]);
		}
	}
	return 0;
}