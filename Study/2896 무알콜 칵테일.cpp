/*
	1. �� ȸ�� ������ �� ���� �� ������ŭ ���ش�.
	2. �� �ֽ��� �ϳ��� 0�� �Ǹ� �����ϰ� �� �ֽ��� �����ִ� �� ���
*/

#include<stdio.h>

int main()
{
	int orange, apple, pineapple;
	int i, j, k;

	scanf("%d %d %d", &orange, &apple, &pineapple);
	scanf("%d %d %d", &i, &j, &k);

	while (orange != 0 && apple != 0 && pineapple != 0)
	{
		orange -= i;
		apple -= j;
		pineapple -= k;

	}

	printf("%d %d %d\n", orange, apple, pineapple);

	
	return 0;
}