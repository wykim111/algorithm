/*
	각 10자리 정수이므로 int형은 안됨
	문자열이나 long형으로 접근
*/
#include<stdio.h>

int main()
{
	long long int N, M;

	scanf("%d %d", &N, &M);

	if (N == M)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}