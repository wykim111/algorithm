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
			num[i*j] = 1;//소수가 아님
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

	//투포인터 알고리즘 활용
	//합계가 크면 left에 있는 데이터를 빼고 1칸 이동
	//합계가 작으면 right로 1칸 이동하며 더함
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