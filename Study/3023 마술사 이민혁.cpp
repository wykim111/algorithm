/*
���� �� 1/4�� �������Ѵ�. �� ���� ��Ī���� ������ ���� �����, �ٽ� ��Ī���Ѽ� �Ʒ� �κ��� ��� �����.
������ ���� '#'�̾�� �ϴ� ĭ�� '.'�� �ٲٰų� '.'�̾�� �ϴ� ĭ�� '#'�� �ٲٴ� ���̴�.
*/
#include<stdio.h>

int R, C;
char map[51][51];
int A, B; // ������ ��ġ
char retMap[102][102];

void Print()
{
	for (int i = 0; i < 2 * R; i++)
	{
		for (int j = 0; j < 2 * C; j++)
		{
			printf("%c", retMap[i][j]);
		}
		printf("\n");
	}
}
void errorSearch(int y,int x)
{
	if (retMap[y][x] == '.')
	{
		retMap[y][x] = '#';
	}
	else if (retMap[y][x] == '#')
	{
		retMap[y][x] = '.';
	}
}
int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", map[i]);
		while (getchar() != '\n');
	}
	//���� �Է�
	scanf("%d %d", &A, &B);

	//���� ��� ��Ī
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			retMap[i][j] = map[i][j];
		}
	}

	//���� ��� ��Ī
	for (int i = 0; i <R ; i++)
	{
		for (int j = C; j < 2*C; j++)
		{
			retMap[i][j] = map[i][(2 * C) - j - 1];
		}
	}


	//���� �ϴ� ��Ī
	for (int i = R; i < 2*R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			retMap[i][j] = map[(2*R)-1-i][j];
		}
	}
	//���� �ϴ� ��Ī
	for (int i = R; i < 2 * R; i++)
	{
		for (int j = C; j < 2 * C; j++)
		{
			//input���� ���� �ʿ��� �ش� ��ġ�� ���� ������ ���� ������
			//��¿� ���� ������ �о� ���δ�.
			retMap[i][j] = retMap[(2 * R) - 1 - i][j];
		}
	}

	errorSearch(A-1,B-1);
	Print();
	

	return 0;
}