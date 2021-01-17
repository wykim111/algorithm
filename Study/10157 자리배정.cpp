#include<stdio.h>

int map[1002][1002];
int C, R;
int K;
int retY, retX;

int search()
{
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			if (map[i][j] == K)
			{
				retY = j;
				retX = i;

				return 1;
			}
		}

	}

	return 0;
}

int main()
{
	int sw = 1;
	int num = 1;
	int x = 0, y = 1;

	scanf("%d %d", &C, &R);
	scanf("%d", &K);

	if (C * R < K)
	{
		printf("0\n");
		return 0;
	}

	/*
		2�� ����Ŭ �� ������ ��� ���� �ϳ��� ����
	*/
	int tempR = R, tempC = C;

	while (num <= C * R)
	{
		//���� ������ ����
		for (int j = 1; j <= tempR; j++)
		{
			x += sw;
			map[y][x] = num++;

		}
		tempR--;// �� ����
		tempC--;// �� ����
		//x--; //�� �ݺ������� 1���� �Ǿ��� ������
		//�࿡ ������ ����
		for (int k = 1; k <= tempC; k++)
		{
			y += sw;
			map[y][x] = num++;

		}

		sw *= -1; //������ ���� ��ȯ

	}
	/*
	for (int i = 1; i <= C; i++)
	{
		for (int j = 1; j <= R; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	*/
	if (search() == 1)
	{
		printf("%d %d\n", retX, retY);
	}
	else
	{
		printf("0\n");
	}

	return 0;
}