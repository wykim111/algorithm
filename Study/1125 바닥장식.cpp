#include<stdio.h>
#include<string.h>

int N, M;
char map[100][100];
int visit[100][100];

int dfsRow(int cury, int curx)
{
	visit[cury][curx] = 1;
	//������ Ž���� ��ǥ�� ������ ����ų� '|' ����� ���
	
	if (map[cury][curx+1] == '|' || curx + 1 >= M)
		return 1;

	if (map[cury][curx + 1] == '-' && visit[cury][curx+1] == 0)
		return dfsRow(cury, curx + 1);

	return 0;
}


int dfsCol(int cury, int curx)
{
	visit[cury][curx] = 1;
	//������ Ž���� ��ǥ�� ������ ����ų� '|' ����� ���

	if (map[cury+1][curx] == '-' || cury + 1 >= N)
		return 1;

	if (map[cury+1][curx] == '|' && visit[cury+1][curx] == 0)
		return dfsCol(cury+1, curx);

	return 0;
}

int main()
{
	int ret = 0;

	scanf("%d %d", &N, &M);

	for(int i=0;i<N;i++)
		scanf("%s", map[i]);

	/*
	for (int i = 0; i < N; i++)
		printf("%s\n", map[i]);
	*/
	// �� ���ַ� �ٴ� ���� ī��Ʈ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '-' && visit[i][j] == 0)
			{
				ret += dfsRow(i, j);
			}
		}
	}

	// �� ���ַ� �ٴ� ���� ī��Ʈ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == '|' && visit[i][j] == 0)
			{
				ret += dfsCol(i, j);
			}
		}
	}

	printf("%d\n", ret);

	return 0;
}