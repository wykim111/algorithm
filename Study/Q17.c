#include<stdio.h>

void spira(int n)
{
	for (int i = 1; i <= n; i++)
	{
		//��ĭ
		for (int j = i; j <= n; j++)
		{
			printf(" ");
		}
		//��ǥ
		for (int k = 1; k <= (i - 1) * 2 + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

int main()
{
	int N;

	scanf("%d", &N);

	spira(N);

	return 0;
}