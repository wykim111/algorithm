#include<stdio.h>
#include<math.h>

int prime[1000000] = {1,1,0,};
int retPrime[500001] = { 0, };

void setPrime()
{
	for (int i = 2; i <= sqrt(1000000); i++)
	{
		for (int j = 2; i*j <= 1000000; j++)
		{
			if (prime[i*j] == 1)
			{
				continue;
			}

			prime[i*j] = 1;
		}
	}
}


void copyPrime()
{
	int idx = 0;

	for (int i = 0; i <= 1000000; i++)
	{
		//소수가 아니면 스킵
		if (prime[i] == 1)
			continue;

		retPrime[idx] = i;
		idx++;
	}

}

int main()
{
	int K;

	scanf("%d", &K);

	setPrime();
	copyPrime();

	printf("%d\n", retPrime[K - 1]);

	return 0;

}