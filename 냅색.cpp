#include<stdio.h>

int N, K;
int w[100];//����
int v[100];//��ġ

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	else
		return n2;
}
int knapsack(int idx, int weight)
{
	//���԰� K���� ū ���
	if (weight > K)
	{
		return (-1) * v[idx - 1];
	}
	//idx�� N�� �Ǵ� ���(Ž���� ������ ���)
	if (idx == N)
		return 0;
	
	//�ش� ������ �� ������ ���� ������ ���
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