#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;

bool check_prime[1000001] = { 1,1,0,0, };//�Ҽ��̸� 0 �Ҽ��� �ƴϸ� 1
int idx = 0;
long long int prime[1000001];

void is_prime()
{
	for (int i = 2; i <= 1000000; i++)//�Ҽ��� ��츦 �����ϴ� �迭�� Ž���ϱ� ���� sqrt(1000000)�� �� ��
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