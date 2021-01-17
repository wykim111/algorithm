#include<stdio.h>

int cal(int k)
{

	int remain = k;
	int cnt = 0;
	

	if (remain % 5 == 0)
	{
		return remain / 5;
	}
	while (remain > 0)
	{
		remain = remain - 3;
		cnt++;

		if (remain % 5 == 0)
		{
			cnt += remain / 5;
			return cnt;
		}
	}
	
	
	return -1;
}


int main()
{
	int N;

	scanf("%d", &N);

	while (N--)
	{
		int K;

		scanf("%d", &K);

		printf("%d\n",cal(K));
	}
	return 0;
}