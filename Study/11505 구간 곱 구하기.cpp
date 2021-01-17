#include<stdio.h>

#define MOD 1000000007


long long segment[1<<21];

long long update(int pos,int val,int node, int left, int right)
{
	//범위를 벗어나는 경우
	if (pos < left || pos > right)
	{
		return segment[node];
	}
	if (left == right)
	{
		return segment[node] = val;
	}

	
	long long mid = (left + right) >> 1;

	return segment[node] = ((update(pos,val, node * 2, left, mid) * update(pos,val, node * 2 + 1, mid + 1, right))%MOD);
}


long long query(int low, int high, int node, int left, int right)
{
	//쿼리하고자 하는 범위를 벗어나는 경우
	if (high<left || low > right)
	{
		return 1;
	}

	if (low <= left && right <= high)
	{
		return segment[node];
	}
	long long mid = (left + right) >> 1;

	return (query(low, high, node * 2, left, mid) * query(low, high, node * 2 + 1, mid + 1, right))%MOD;
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		update(i, num, 1, 0, N - 1);
	}
	for (int i = 0; i < M + K; i++)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
		{
			update(b - 1, c, 1, 0, N - 1);
		}
		else
		{
			printf("%lld\n", query(b - 1, c - 1, 1, 0, N - 1)%MOD);
		}
	}
	return 0;


}