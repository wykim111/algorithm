/*
������ �� L���̴�. ������ �� B������, ����� �� A�������� Ǯ��� �Ѵ�. ����̴� �Ϸ翡 ��� �ִ� C������, ������ �ִ� D������ Ǯ �� �ִ�.

����̰� �ܿ� ���е��� ������ ���� �ʰ� �� �� �ִ� �ִ� ���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

   ���� �� Ǫ�� �� = A / C, �������� �ִ� ��� + 1
   ���� �� Ǫ�� �� = B /D , �������� �ִ� ��� + 1

   ���� ���� �� �� Ǫ�� ���� �� ��츦 ����

   �� �� �ִ� �� = L - (���� ������ �� Ǫ�� ���� �� ��츦 ����)

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