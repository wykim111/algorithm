#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//���
	for (int i = 1; i <= N; i++)
	{
		//���� ��
		for (int j = 1; j <= i; j++)
		{
			printf("*");
		}

		//�߾� ����
		for (int k = 1; k <= 2 * (N - i); k++)
		{
			printf(" ");
		}
		//���� ��
		for (int ii = 1; ii <= i; ii++)
		{
			printf("*");
		}
		printf("\n");

	}
	//�ϴ�
	for (int i = 1; i < N; i++)
	{
		//���� ��
		for (int j = 1; j <= N-i; j++)
		{
			printf("*");
		}

		//�߾� ����
		for (int k = 1; k <= 2 * i; k++)
		{
			printf(" ");
		}
		//���� ��
		for (int ii = 1; ii <= N - i; ii++)
		{
			printf("*");
		}
		printf("\n");

	}
	return 0;
}