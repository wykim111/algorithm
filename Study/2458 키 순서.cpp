/*
	�÷��̵� �ͼ� �˰���
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

#define INF 987654321

using namespace std;

int N,M;
int map[501][501];
int connected[501];
int ret = 0;

void init()
{
	for (int i = 1; i <=N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			map[i][j] = INF;
		}
	}
}
void Floyed()
{
	//���İ��� �߰� ����
	for (int k = 1; k <= N; k++)
	{
		//i �������
		for (int i = 1; i <= N; i++)
		{
			//j ��������
			for (int j = 1; j <= N; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

int main()
{
	int stu1, stu2;

	scanf("%d %d", &N, &M);

	init();

	for (int i = 0; i < M; i++)
	{

		scanf("%d %d", &stu1, &stu2);

		map[stu1][stu2] = 1;
	}

	Floyed();

	//��� üũ
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] != INF)
			{
				connected[i]++;
				connected[j]++;

				if (connected[i] == N-1)
					ret++;
				if (connected[j] == N-1)
					ret++;
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}