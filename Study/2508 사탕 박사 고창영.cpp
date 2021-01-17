/*
		1. ĵ�� Ÿ�� ����
		2. �� ĵ�� �ִ��� ������ ���� ��ǥ����  1���� ĵƼ�� ��� ������ġ���� y�����κ��� +3, 
		   2��° ĵ��� x�����κ��� +3���� ���� ĵ�� �����ϴ��� Ž��

*/
#include<stdio.h>
#include<string.h>


//���� Ÿ��
char candy1[3] = { '>','o','<' };
char candy2[3] = { 'v','o','^' };

int t;
int r, c;
char map[401][401];

int checkType1(int y, int x)
{
	int idx = 0;

	for (int nextX = x ; nextX < x + 3; nextX++)
	{
		if (nextX >= c || map[y][nextX] != candy1[idx])
		{
			return 0;
		}
		idx++;
	}
	return 1;
}

int checkType2(int y, int x)
{
	int idx = 0;

	for (int nextY = y; nextY < y + 3; nextY++)
	{
		
		if (nextY >= r || map[nextY][x] != candy2[idx])
		{
			return 0;
		}
		idx++;
	}
	return 1;
}


int main()
{
	scanf("%d", &t);

	while (t--)
	{
		int ret = 0;

		scanf("%d %d", &r, &c);
		while (getchar() != '\n');

		memset(map, 0, sizeof(map));

		for (int i = 0; i < r; i++)
		{
			scanf("%s", map[i]);
		}

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (checkType1(i, j) == 1)
				{
					ret++;
				}
				if (checkType2(i, j) == 1)
				{
					ret++;
				}
			}
		}

		printf("%d\n", ret);

	}
	return 0;
}