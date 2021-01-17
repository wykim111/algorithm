#include<stdio.h>


char str[50][5][7];
int N;
int min = 1e9;
int main()
{
	int cnt = 0;
	int retOne, retTwo;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%s", str[i][j]);

			while (getchar() != '\n');
		}
	}


	//그림 비교
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			cnt = 0;
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 7; x++)
				{
					if (str[i][y][x] != str[j][y][x])
					{
						cnt++;
					}
				}//x
			}//y

			if (min > cnt)
			{
				min = cnt;
				retOne = i;
				retTwo = j;
			}

		}
	}
	printf("%d %d\n", retOne+1, retTwo+1);

	return 0;

}