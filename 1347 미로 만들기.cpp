/*
	1.�̷� ���� ��ĭ�� ������ �ٶ󺻴� �Ͽ����Ƿ� 50*2�� �迭�� ������ ����
	2. startY,startX, endY,endX�� ������ ���ѵ� ���
	3. �¿�� ȸ���� �� �� ���ư����� ����

*/
#include<stdio.h>
#include<string.h>

//�����ϵ�
int dy[] = { 1,0,-1,0 };
int dx[] = { 0,-1,0,1 };
char str[50];
int map[101][101];
int dir = 0; //dy,dx�� 0�̶�� �ǹ�(������ �ٶ󺸰� ����)
int main()
{
	int len;
	int N;
	int curX = 50, curY = 50;
	int startY = curY, startX = curX, endY = curY, endX = curX;

	scanf("%d", &N);
	scanf("%s", str);

	map[curY][curX] = 1;
	
	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'F')
		{
			//�������� �̵�
			curY += dy[dir];
			curX += dx[dir];

			map[curY][curX] = 1;
			//���� ����
			if (curY > endY)
				endY = curY;
			if (curY < startY)
				startY = curY;
			if (curX > endX)
				endX = curX;
			if (curX < startX)
				startX = curX;
		}
		else if (str[i] == 'L')
		{
			//�������� ȸ��
			dir = (dir+3) % 4;

		}
		else if (str[i] == 'R')
		{
			//�������� ȸ��
			dir = (dir + 1) % 4;
		}
	}

	for (int i = startY; i <= endY; i++)
	{
		for (int j = startX; j <= endX; j++)
		{
			if (map[i][j] == 1)
			{
				printf(".");
			}
			else
			{
				printf("#");
			}
		}
		printf("\n");
	}

	return 0;
}