/*
두 수 사이에 있는 정수를 모두 출력
1 000 000 000 000 000
*/
#include<stdio.h>
#define ULL unsigned long long

unsigned long long A, B;

void swap(ULL* p1, ULL* p2)
{
	ULL temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main()
{
	scanf("%llu %llu", &A, &B);

	if (A > B)
	{
		swap(&A, &B);
	}
	if (A != B)
	{
		printf("%llu\n", B - A - 1);
		for (ULL num = A + 1; num < B; num++)
		{
			printf("%llu ", num);
		}
		printf("\n");
	}
	else
	{
		printf("0\n");
	}
	return 0;
}