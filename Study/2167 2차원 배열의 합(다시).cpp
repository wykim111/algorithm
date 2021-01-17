/*
	0���Ͱ� �ƴ� 1���� �����ϱ� ������ �и� 1�� ����
	arr[i][j] = arr[i * (N+1) ][j%(M)]
*/

#include<stdio.h>

int N, M;
int map[301][301];
int K;
int startY, startX, endX, endY;
int convertArray[301 * 301];
int idx = 0;

void update()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			convertArray[idx++] = map[i][j];
		}
	}
}

int cal(int sY, int sX, int eY, int eX)
{
	int start = sY*(N+1) + sX;
	int end = eY*(N+1) + eX ;
	int sum = 0;

	for (int i = start; i <= end; i++)
	{
		sum += convertArray[i];
	}

	return sum;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	
	update();

	scanf("%d", &K);
	
	//����� ��ǥ �Է�
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &startY, &startX, &endY, &endX);
		printf("%d\n",cal(startY-1, startX-1, endY-1, endX-1));
	}

	return 0;
}