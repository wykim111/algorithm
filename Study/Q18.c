#include<stdio.h>

void nspira(int n)
{
	for (int i = 1; i <= n; i++)
	{		
		//��ĭ
		for (int j = 1; j < i; j++)
		{
			printf(" ");
		}
		//��ǥ
		for (int k = 1; k <= (n - i) * 2 + 1; k++)
		{
			printf("%d", i);
		}
		printf("\n");
	}
}

int main()
{
	int N;

	scanf("%d", &N);

	nspira(N);

	return 0;
}