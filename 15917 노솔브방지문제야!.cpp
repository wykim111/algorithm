/*
	2�� �ŵ������� ��Ÿ���� ���
	1. ��Ʈ�÷��� üũ
	2. (x & -x) == x  -> x�� �������̸� -x�� 2�� ������ ��Ʈ������ �ϸ� �ڱ� �ڽ��� �����Ƿ�

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
