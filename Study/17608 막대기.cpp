#include<stdio.h>

int N;
int bar[100000];

int main()
{
	int cnt = 0;
	int std = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &bar[i]);
	}

	for (int i = N-1; i >= 0; i--)
	{
		//���� ���̴� ����⺸�� �ڿ� �ְ� ���̰� ���� ���� ���̰� �ǹǷ� ���� ���� ������Ʈ
		if (std < bar[i])
		{
			std = bar[i];
			cnt++;
		
		}
	}

	printf("%d\n", cnt);

	return 0;
}