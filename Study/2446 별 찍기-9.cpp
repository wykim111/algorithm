#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//상단
	for (int h = N; h > 0; h--)
	{
		//공백
		for (int i = h; i < N; i++)
		{
			printf(" ");
		}
		//별
		for (int j = 1; j <= (2 * h) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//하단
	for (int h = 1; h < N; h++)
	{
		//공백
		for (int i = 1; i < N-h; i++)
		{
			printf(" ");
		}
		//별
		for (int j=1;j <= 2*h+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}

}