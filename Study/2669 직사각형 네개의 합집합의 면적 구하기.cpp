/*
	2���� �迭 ����
	���簢�� ���̸�ŭ x�� y�� ��ǥ�� 1�� ����ŷ
	1�� ����ŷ �� �� ī��Ʈ
*/
#include<stdio.h>

int map[101][101];

int main()
{
	int maxX=0, maxY=0;
	int cnt = 0;

	for (int i = 0; i < 4; i++)
	{
		int x1, y1,x2,y2;
		
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		//Ž���� ���� ����
		if (x2 > maxX)
		{
			maxX = x2;
		}

		if (y2 > maxY)
		{
			maxY = y2;
		}

		//���簢�� ���� 1�� ����ŷ
		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				map[j][k] = 1;
			}
		}
	}
	//printf("maxX = %d maxY= %d\n", maxX, maxY);
	//1�� ����ŷ �� ���� ī��Ʈ
	for (int i = 0; i <= maxY; i++)
	{
		for (int j = 0; j <= maxX; j++)
		{
			if (map[i][j] == 1)
			{
				cnt++;
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}