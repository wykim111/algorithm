/*
	해당좌표를 선택하는 경우/ 선택하지 않은 경우로 나눔
*/
#include<stdio.h.>

int N, M;
int map[4][4];
int visit[4][4];
int result = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

void cal()
{
	//가로
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int tempSum = 0;
		
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1)
			{
				tempSum *= 10;
				tempSum += map[i][j];
			}
			else
			{
				sum += tempSum;
				tempSum = 0;
			}
		}//j
		sum += tempSum;
	}//i
	//세로
	for (int i = 0; i < M; i++)
	{
		int tempSum = 0;

		for (int j = 0; j < N; j++)
		{
			if (visit[j][i] == 0)
			{
				tempSum *= 10;
				tempSum += map[j][i];
			}
			else
			{
				sum += tempSum;
				tempSum = 0;
			}
		}//j
		sum += tempSum;
	}//i
	result = max(result, sum);
}

void dfs(int y, int x)
{
	if (y >= N)
	{
		cal();
		return;
	}


	//한행 선택 완료 시
	if (x >= M)
	{
		dfs(y + 1, 0);
		return;
	}

	visit[y][x] = 1;
	dfs(y, x + 1);// 해당좌표 선택
	visit[y][x] = 0;
	dfs(y, x + 1);//해당 좌표 미선택
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", result);

	return 0;
}