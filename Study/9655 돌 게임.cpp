/*
	������ Ȧ���̸� ����̰� �̱�� ¦���̸� �����̰� �̱��.

*/
#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//¦��
	if (N % 2 == 0)
	{
		printf("CY\n");
	}
	else //Ȧ��
	{
		printf("SK\n");
	}

	return 0;
}