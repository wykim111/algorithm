/*
	�� 10�ڸ� �����̹Ƿ� int���� �ȵ�
	���ڿ��̳� long������ ����
*/
#include<stdio.h>

int main()
{
	long long int N, M;

	scanf("%d %d", &N, &M);

	if (N == M)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}