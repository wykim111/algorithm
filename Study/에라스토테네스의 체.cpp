/*
	�Ҽ� �迭�� �÷��װ� 1�� ��� �Ҽ��� �ƴϰ� 0�� ��� �Ҽ��̴�
	0�� 1�� �÷��װ� 0������ �Ҽ��� �ƴϴ�
*/

#include<stdio.h>
#include<math.h>

int prime[101] = { 0,0, };
int cnt = 0;

int main()
{
	for (int i = 2; i <= sqrt(100); i++)
	{
		for (int j = 2; i*j <= 100; j++)
		{
			//������ �Ҽ� �ƴ� �÷��� üũ �� ���
			if (prime[i*j] == 1)
			{
				continue;
			}

			//�Ҽ��� �ƴ� ��� 1�� ����
			prime[i*j] = 1;
		}
	}

	for (int i = 2; i <= 100; i++)
	{
		if (prime[i] == 1)//1�� ��� �Ҽ��� �ƴ�
			continue;
		printf("%d ", i);
		cnt++;
	}
	printf("\n");
	printf("ī��Ʈ = %d\n", cnt);

	return 0;
}