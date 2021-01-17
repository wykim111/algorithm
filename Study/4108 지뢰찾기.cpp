/*
	.���� �����¿� �밢�� 1ĭ�� Ž��
	.���� *�� ������ .���� ī��Ʈ�Ͽ� ������ �����ϰ� *�� �״�� �д�.
*/
#include<stdio.h>
#include<string.h>

int tc;
int R, C;
char map[101][101];

//�������� �»� ���� ���� ���
int dy[] = { 0,0,1,-1,-1,1,1,-1 };
int dx[] = { 1,-1,0,0,-1,-1,1,1 };

int mine(int y, int x)
{
	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= R || nextX < 0 || nextX >= C)
			continue;
		if (map[nextY][nextX] == '*')
		{
			cnt++;
		}
	}
	return cnt;
}
void Print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	
}
int main()
{

	while (1)
	{
		scanf("%d %d", &R, &C);

		if (R == 0 && C == 0)
			break;
		memset(map, 0, sizeof(map));
		
		for (int i = 0; i < R; i++)
		{
			scanf("%s", map[i]);

			while (getchar() != '\n');
		}


		// . ã��
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == '.')
				{
					map[i][j] = mine(i, j)+'0';
				}
			}
		}

		//���
		Print();

	}
	return 0;
}