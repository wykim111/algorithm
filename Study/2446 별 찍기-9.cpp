#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	//���
	for (int h = N; h > 0; h--)
	{
		//����
		for (int i = h; i < N; i++)
		{
			printf(" ");
		}
		//��
		for (int j = 1; j <= (2 * h) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}

	//�ϴ�
	for (int h = 1; h < N; h++)
	{
		//����
		for (int i = 1; i < N-h; i++)
		{
			printf(" ");
		}
		//��
		for (int j=1;j <= 2*h+1;j++)
		{
			printf("*");
		}
		printf("\n");
	}

}