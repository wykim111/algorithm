/*
	���簢����ǥ 3���ּ� ������ ���� �̹� x�� y�� ���� �����͸� ¦������ ���� �ִ�.
	Ȧ���� ���� �ִ� ���� ������ 1���� ���� ��ǥ�̴�.
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