#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

int R, C;
char map[501][501];
//��������
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int wolf_flag = 0;
int check(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		//���� ��� ���
		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;

		if (map[ny][nx] == 'W')
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		scanf("%s", &map[i]);

	}
	//���� Ž��
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] == 'S')//�� �ֺ��� ���밡 �ִ��� ������
			{
				wolf_flag += check(i, j);
			}
		}
	}

	if (wolf_flag == 0)
	{
		//�� �ֺ����� ���밡 ������ ��Ÿ�� ��ġ ����
		printf("1\n");
		//��Ÿ�� ��ġ
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (map[i][j] == '.')
				{
					map[i][j] = 'D';
				}
			}
		}
		
	}
	else
	{
		printf("0\n");
		return 0;
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}