#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

bool check_prime[1000001] = { 1,1,0,0, };//소수이면 0 소수가 아니면 1
int idx = 0;
long long int prime[1000001];

void is_prime()
{
	for (int i = 2; i <= 1000000; i++)//소수인 경우를 저장하는 배열을 탐색하기 위해 sqrt(1000000)을 안 씀
	{
		if (check_prime[i] == 0)
		{
			prime[idx++] = i;
		}
		for (int j = 2; i*j <= 1000000; j++)
		{
			check_prime[i*j] = 1;
		}
	}
}

int main()
{
	int N;

	scanf("%d", &N);

	while (N--)
	{
		is_prime();
		long long int num;
		int i;
		scanf("%lld", &num);
	
		for (i = 0; i < idx; i++)
		{
			if ((num % prime[i]) == 0)
			{
				break;
			}
		}
		if (i == idx)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}

	return 0;
}