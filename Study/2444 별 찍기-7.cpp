/*
	상단 삼각형과 하단 역삼각형 나누어 출력
*/
#include<stdio.h>

void top(int n)
{
	for (int i = 0; i < n; i++)
	{
		//빈칸 출력
		for (int j = 0; j < n - i-1; j++)
		{
			printf(" ");
		}
		//별표 출력
		for (int k = 0;k<(2*i)+1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
}

void bottom(int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//빈칸 출력
		for (int j = 0; j<=i; j++)
		{
			printf(" ");
		}
		//별표 출력
		for (int k = 0; k < 2 * (n-i) - 3; k++)
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

	top(N);
	bottom(N);
}