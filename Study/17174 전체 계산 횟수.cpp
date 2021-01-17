/*
	묶음(M)dl 0이 될 때까지 연산

*/
#include<stdio.h>

int N, M;

int main()
{
	int ret = 0;

	scanf("%d %d", &N, &M);

	
	int tempN = N;
	
	while (tempN != 0)
	{
		ret += tempN;
		tempN = tempN / M;

	}
	printf("%d\n", ret);

	return 0;
}