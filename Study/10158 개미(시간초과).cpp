/*
	0.��� ���Ϸ� �̵�
	
	1,������ ���� �����ϸ� ���Ϸ� �̵�
	2,���࿡ �̵��� ��� �»����� �̵�
	3.ù �࿡ �̵��� ��� ���Ϸ� �̵�
	4.���� ���� ��� ���Ϸ� �̵�

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