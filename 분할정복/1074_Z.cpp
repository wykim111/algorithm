/*
	- 분할정복
	1. 4등분씩 나눈다.
	2. 최소단위는 2x2로 둔다.
	3. 최소 단위에서 시작pos(y,x)에서 y+2,x+2까지 값을 저장
	4. 2^N승을 가진 행과 열을 2로 나눈 값을 각 시작지점에 분할한다.
		
		go(size/2,y,x)
		go(size/2,y,x+size/2)
		go(size/2,y+size/2,x)
		go(size/2,y+size/2,x+size/2)
		
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int N, r, c;
int num = 0;
//int map[1024][1024];
int ret = 0;

void go(int size,int y,int x)
{
	if (y==r && x == c)
	{
		ret = num;
		return;
	}
	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		go(size / 2, y, x);
		go(size / 2, y, x + size / 2);
		go(size / 2, y + size / 2, x);
		go(size / 2, y + size / 2, x + size / 2);
	}
	else
	{
		num += size * size;
	}
}

int main()
{
	scanf("%d %d %d", &N, &r, &c);

	int size = (int)(pow(2, N));

	go(size, 0, 0);
	/*
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d\n", ret);

	return 0;
}
