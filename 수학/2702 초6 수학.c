#include<stdio.h>

int T;

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return GCD(b, a%b);
}

int LCM(int gcmData, int a, int b)
{
	return gcmData * (a/gcmData) * (b/gcmData);
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		int num1, num2;
		int gcdData,lcmData;

		scanf("%d %d", &num1, &num2);

		gcdData = GCD(num1, num2);
		lcmData = LCM(gcdData, num1, num2);
		printf("%d %d\n",lcmData,gcdData);
		
	}

	return 0;
}
