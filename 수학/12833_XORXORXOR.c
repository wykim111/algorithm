/*
	1. XOR의 특성상 피연산자를 연산하는 횟수가 짝수인 경우 자기 자신이 나옴.
	2. XOR의 특성상 피연산자를 연산하는 횟수가 홀수인 경우 피연산자를 1회만 XOR 한 값.

*/

#include <stdio.h>

unsigned int A, B, C;

void input()
{
	scanf("%u %u %u", &A, &B, &C);
}

void solution()
{
	if ((C % 2) == 0)
	{
		printf("%u\n", A);
	}
	else
	{
		printf("%u\n", A ^ B);
	}
}

int main()
{
	input();
	solution();

	return 0;
}
