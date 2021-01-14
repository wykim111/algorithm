/*
	T : testCase
	N : 양의 정수

	N의 제곱의 배수 중 최소 양의 정수

	-> N * N
*/

#include<stdio.h>

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		long long int N,K;

		scanf("%lld", &N);

		K = N * N;
		printf("%lld\n", N*N);
	}

	return 0;
}
