#include<stdio.h>

int N, K;
int w[100];//무게
int v[100];//가치

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}
int knapsack(int idx, int weight)
{
	//무게가 K보다 큰 경우
	if (weight > K)
	{
		return (-1) * v[idx - 1];
	}
	//idx가 N이 되는 경우(탐색의 범위가 벗어남)
	if (idx == N)
		return 0;
	
	//해당 물건을 안 가지는 경우와 가지는 경우
	return max(knapsack(idx + 1, weight), knapsack(idx + 1, weight + w[idx]) + v[idx]);
}
int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &w[i], &v[i]);
	}

	printf("%d\n",knapsack(0, 0));

	return 0;
}
