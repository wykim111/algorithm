#include<stdio.h>

int main()
{
	int A, B;// 시 분
	int C;// 분단위 입력
	int retA, retB;

	scanf("%d %d", &A, &B);
	scanf("%d", &C);


	retB = (B + C) % 60;
	retA = (A + ((B + C) / 60)) % 24;

	printf("%d %d\n", retA, retB);

	return 0;
}