#include<stdio.h>
#include<math.h>

int N;

int num[4000001] = { 0, };
int prime[4000001];
int primeIdx = 0;

void primeInit()
{
	for (int i = 2; i < sqrt(N); i++)
	{
		for (int j = 2; i*j <= N; j++)
		{
			if (num[i*j] == 1)
				continue;
			num[i*j] = 1;//�Ҽ��� �ƴ�
		}
	}

	for (int i = 2; i <=N; i++)
	{
		if (num[i] == 1)
			continue;
		
		prime[primeIdx] = i;
	//	printf("%d\n", prime[primeIdx]);
		primeIdx++;
	}
}

int main()
{
	int ret = 0;
	int sum = 0;
	int left = 0, right = 0;
	scanf("%d", &N);

	primeInit();
	//printf("primeIdx = %d\n", primeIdx);
/*
	for (int i = 0; i < primeIdx; i++)
	{
		printf("%d\n", prime[i]);
	}
*/

	//�������� �˰��� Ȱ��
	//�հ谡 ũ�� left�� �ִ� �����͸� ���� 1ĭ �̵�
	//�հ谡 ������ right�� 1ĭ �̵��ϸ� ����
	while (1)
	{
		if (sum >= N)
		{
			sum -= prime[left];
			left++;
		}
		else if (right == primeIdx)
		{
			break;
		}
		else
		{
			sum += prime[right];
			right++;
		}

		if (sum == N)
		{
			ret++;
		}

	}
	printf("%d\n", ret);

	return 0;
}