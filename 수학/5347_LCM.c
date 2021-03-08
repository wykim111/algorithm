/*
	1.최대 공약수를 먼저 구함(유클리드 호제법)
	2. 최대공약수로 나눈 몫들을 곱합

	자연수가 백만이므로 int 자료형 쓰면 안됨
	(unsigned long long)
*/

#include<stdio.h>

unsigned long long GCD(int n1,int n2)
{
	if (n2 == 0)
	{
		return n1;
	}

	return GCD(n2, n1%n2);
}



int main()
{
	int N;

	scanf("%d\n", &N);

	while (N--)
	{
		int num1, num2;
		unsigned long long retGCD = 0,retLCM = 0;
		
		scanf("%d %d", &num1, &num2);

		if (num1 == 0 || num2 == 0)
		{
			printf("0\n");

			return 0;
		}


		retGCD = (unsigned long long)GCD(num1, num2);
		
		//(num1 * num2)/최대공약수로 하면 틀림
		// (num1 / 최대공약수) * num2 로 해야 정답!!!
		retLCM = (unsigned long long)(num1/retGCD) *num2;//이 부분이 중요

		printf("%lld\n", retLCM);

	}

	return 0;
}
