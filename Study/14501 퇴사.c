#include<stdio.h>

int N;
int P[16],T[16];
int ret = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}

int go(int today , int sum)
{

	//baseCase1
	if (today > N)
	{
		return 0;
	}
	//baseCase2
	if (today == N)
	{
		return ret = max(sum, ret);
	}
	
	
	//현재 상담을 선택하지 않는 경우,현재  상담을 선택하는 경우
	go(today + 1, sum);

	//if (today + T[today] <= N)
	//{
	go(today + T[today], sum+P[today]);
	//}
	return ret;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);

	}
	ret = go(0,0);

	printf("%d\n",ret);

	return 0;
}
