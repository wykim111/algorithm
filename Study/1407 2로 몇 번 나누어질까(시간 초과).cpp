#include<stdio.h>

int num[51];

long long int pow(long long int num, int exp)
{
	if (exp == 0)
		return 1;

	return num*pow(num, exp - 1);
}
int main()
{
	long long int A, B;
	 long long int retA = 0,retB = 0;
	 int flag = 1;
	scanf("%lld %lld", &A, &B);

	num[0] = 1;

	for (int i = 1; i < 50; i++)
		num[i] = num[i - 1] * 2 + (1 << (i - 1));
	
	A--;
	for (int i = 0; i < 50; i++)
	{
		if (A % 2 == 1)
		{
			retA += num[i];
		
		}
	}
	
}
