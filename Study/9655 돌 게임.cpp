/*
	갯수가 홀수이면 상근이가 이기고 짝수이면 찬영이가 이긴다.

*/
#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//짝수
	if (N % 2 == 0)
	{
		printf("CY\n");
	}
	else //홀수
	{
		printf("SK\n");
	}

	return 0;
}