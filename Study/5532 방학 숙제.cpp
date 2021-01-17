/*
방학은 총 L일이다. 수학은 총 B페이지, 국어는 총 A페이지를 풀어야 한다. 상근이는 하루에 국어를 최대 C페이지, 수학을 최대 D페이지 풀 수 있다.

상근이가 겨울 방학동안 숙제를 하지 않고 놀 수 있는 최대 날의 수를 구하는 프로그램을 작성하시오.

   국어 다 푸는 날 = A / C, 나머지가 있는 경우 + 1
   수학 다 푸는 날 = B /D , 나머지가 있는 경우 + 1

   국어 수학 중 다 푸는 날이 긴 경우를 택일

   놀 수 있는 날 = L - (국어 수학중 다 푸는 날이 긴 경우를 택일)

*/

#include<stdio.h>

int Max(int n1, int n2)
{
	if (n1 > n2)
	{
		return n1;
	}

	return n2;
}

int main()
{
	int koreanDay = 0, mathDay = 0;
	int L, A, B, C, D;
	int vacation = 0,maxDay = 0;

	scanf("%d", &L);
	scanf("%d", &A);
	scanf("%d", &B);
	scanf("%d", &C);
	scanf("%d", &D);

	koreanDay = A / C;

	if (A%C != 0)
	{
		koreanDay += 1;
	}

	mathDay = B / D;

	if (B%D != 0)
	{
		mathDay += 1;
	}
	maxDay = Max(koreanDay, mathDay);
	vacation = L - maxDay;

	printf("%d\n", vacation);

	return 0;
}