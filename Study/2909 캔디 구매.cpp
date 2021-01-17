/*
	K는 0의 갯수이므로 str의 길이str[len -1 -i]가 5미만이면 0이고 5이상이면 해당숫자를 +1로 올린다.
	9에서 올린 숫자가 10이면 다음 자릿수에 +1 올린다.
*/
#include<stdio.h>
#include<string.h>


long long C, K;

int main()
{
	long long digit = 1;
	long long ret = 0;
	scanf("%lld %lld", &C, &K);

	
	for (int i = 1; i <= K;i++)
	{
		digit *= 10;
	}

	K = digit / 10;
	ret = ((C + (K * 5)) / (K*10)) * (K*10);

	printf("%lld", ret);

}