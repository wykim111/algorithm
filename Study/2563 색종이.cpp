/*
	2���� �迭 ����
	x�� y�� ��ǥ�� 1�� ����ŷ
	1�� ����ŷ �� �� ī��Ʈ
*/
#include<stdio.h>

int map[101][101];

void markingArea(int sX, int sY)
{
	for (int i = sY; i < sY + 10; i++)
	{
		for (int j = sX; j < sX + 10; j++)
		{
			if (map[i][j] == 1)
				continue;
			map[i][j] = 1;
		}

	}
}

int calArea()
{
	int sum = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 1)
			{
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int x, y;

		scanf("%d %d", &x, &y);

		markingArea(x,y);
	}

	printf("%d\n", calArea());

	return 0;
}