/*
	0번 째 : 4
	1번 쨰 : 9  (3^2)
	2번 쨰 : 25 (5^2)
	3번 째 : 81 (9^2)

	n번항과 n+1항 사이에는 2씩 커지기 때문에
	계차수열 접근
*/
#include<stdio.h>

int main()
{
	int N;
	int K = 2;
	int an = 3;
	scanf("%d", &N);

	for (int i = 1; i < N; i++)
	{
		an += K;
		K *= 2;
	}

	printf("%d\n", an*an);

	return 0;
}
