#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//상단
	for (int i = 1; i <= N; i++)
	{
		//좌측 별
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}

		//중앙 여백
		for (int k = 1; k <= 2 * (N - i); k++)
		{
			printf(" ");
		}
		//우측 별
		for (int ii = 1; ii <= i; ii++)
		{
			printf("*");
		}
		printf("\n");

	}
	//하단
	for (int i = 1; i < N; i++)
	{
		//좌측 별
		for (int j = 1; j <= N-i; j++)
		{
			printf("*");
		}

		//중앙 여백
		for (int k = 1; k <= 2 * i; k++)
		{
			printf(" ");
		}
		//우측 별
		for (int ii = 1; ii <= N - i; ii++)
		{
			printf("*");
		}
		printf("\n");

	}
	return 0;
}