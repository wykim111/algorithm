/*
	K�� 0�� �����̹Ƿ� str�� ����str[len -1 -i]�� 5�̸��̸� 0�̰� 5�̻��̸� �ش���ڸ� +1�� �ø���.
	9���� �ø� ���ڰ� 10�̸� ���� �ڸ����� +1 �ø���.
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