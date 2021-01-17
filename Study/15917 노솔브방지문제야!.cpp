/*
	2의 거듭제곱을 나타내는 방법
	1. 비트플래그 체크
	2. (x & -x) == x  -> x는 이진수이며 -x는 2의 보수로 비트연산을 하면 자기 자신이 남으므로

*/
#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);
	
	while (N--)
	{
		int num;

		scanf("%d", &num);

		if ((num & -num) == num)
			printf("1\n");
		else
			printf("0\n");

	}
	return 0;
}
