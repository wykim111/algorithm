/*
	abs ���밪�� Ȱ���Ͽ� ���

	-> |N-M|
*/

#include<stdio.h>
#include<math.h>

int main()
{
	long long N, M;
	long long ret = 0;

	scanf("%lld %lld", &N, &M);

	ret = abs(N - M);

	printf("%lld\n", ret);

	return 0;
}