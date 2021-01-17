/*
	0.평소 우하로 이동
	
	1,마지막 열에 도착하면 좌하로 이동
	2,끝행에 이동한 경우 좌상으로 이동
	3.첫 행에 이동한 경우 좌하로 이동
	4.시작 열인 경우 우하로 이동

*/

#include<stdio.h>

int main()
{
	int w, h;
	int x, y;
	int t;

	int dx = 1, dy = 1;
	int tCnt = 0;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &t);


	while (t--)
	{
		if (x == 0 || x == w)
		{
			dx *= -1;
		}

		if (y == 0 || y == h)
		{
			dy *= -1;
		}
		x += dx;
		y += dy;
	}
	printf("%d %d", x, y);

	return 0;
}