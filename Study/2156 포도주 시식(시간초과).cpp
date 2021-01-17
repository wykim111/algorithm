#include<stdio.h>

int grape[10000];
int N;
int ret = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

/*
	해당 포도주를 마시는 경우/ 안 마시는 경우로 나누며
	연속 3잔을 마실 수 없게 cont로 카운트한다.
*/
void go(int dep, int sum, int cont)
{
	if (dep == N )
	{
		ret = max(ret, sum);
		return;
	}
	//안 마시는 경우
	go(dep + 1, sum, 0);

	//연속 3잔이 아닌 이상 마시는 경우
	if (cont < 2)
	{
		go(dep + 1, sum+ grape[dep], cont+1);
	}
	return;
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &grape[i]);
	}

	go(0,0,0);
	printf("%d\n", ret);

}