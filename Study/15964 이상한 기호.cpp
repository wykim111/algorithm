#include<stdio.h>

int cal(int A, int B)
{
	return (A + B) * (A - B);
}

int main()
{
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	printf("%d\n",cal(num1, num2));

	return 0;
}