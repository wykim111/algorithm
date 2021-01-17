#include<stdio.h>
#include<math.h>

int N, M;
int map[1001][1001];
int x[1001], y[1001];
int idx = 0;

int main()
{
	int ret = 0;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (map[i][j] == 1)
			{
				x[idx] = i;
				y[idx] = j;
				idx++;
			}
		}
	}
	
	ret = abs(x[0] - x[1]) + abs(y[0] - y[1]);

	printf("%d\n", ret);

	return 0;
}