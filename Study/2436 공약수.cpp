/*
	GCD(a,b) = g
	LCM(a,b) = a/g * b/g * g
*/
#include<stdio.h>

int getGCD(int a, int b)
{
	if (b == 0)
		return a;

	return getGCD(b,a%b);
}
void swap(int* p1, int* p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

 
int main()
{
	int GCD, LCM;
	int G;
	int temp;
	int num1=0, num2=0;

	scanf("%d %d", &GCD, &LCM);

	temp = LCM / GCD;

	//printf("%d\n", G);

	//최대공약수까지 탐색
	for (int i = 1; i*i <= temp; i++)
	{
		if (temp % i == 0)
		{
			//1인 약수밖에 없는 수
			if (getGCD(i,temp/i) == 1)
			{
				num1 = i;
				num2 = temp / i;
			}
		}
	}
	if (num1 > num2)
		swap(&num1, &num2);
	printf("%d %d\n", num1*GCD, num2*GCD);

	return 0;
}
