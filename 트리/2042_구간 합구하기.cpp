/*
		세그먼트 트리 알고리즘


		-> 틀린 이유: 자료형 (long long)으로 수정(변수 c)
*/

#include<stdio.h>

int N, M, K;//수의 갯수, 수의 변경이 일어나는 횟수, 구간의 합
long long segment[1 << 21];
long long arr[1000001];

long long init(int node, int s, int e)
{
	if (s == e)
	{
		return segment[node] = arr[s];
	}

	long long mid = (s + e) >> 1;
	
	segment[node] = init(node * 2, s, mid) + init((node * 2)+1, mid + 1, e);

	return segment[node];
}


//pos: 값을 갱신할 위치, val: 변경할 값
void update(int pos, long long int diff, int node, long long start, long long end)
{
	//변경하고자 하는 노드를 포함한 범위의 노드를 전부 업데이트
	if (start <= pos && pos <= end)
	{
		segment[node] += diff;

	}
	else
	{
		return;
	}
	if (start == end)
	{
		return;
	}

	long long mid = (start + end) >> 1;

	update(pos, diff, node * 2, start, mid);
	update(pos, diff, (node * 2)+1, mid+1, end);
}
//start부터 end까지 범위의 합을 lo,hi로 좁혀가면서 연산
long long query(int lo, int hi, int node, long long start,long long end)
{
	//범위를 벗어나는 경우
	if (lo > end || hi < start)
	{
		return 0;
	}

	if (start <= lo && hi <= end)
	{
		return segment[node];
	}

	long long mid = (lo+hi) >> 1;

		
	return query(lo, mid, node * 2, start, end) + query(mid + 1, hi, (node * 2) + 1, start, end);
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);

	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	init(1, 1, N);

	for (int i = 0; i < M + K; i++)
	{
		int a, b;
		long long c;

		scanf("%d %d %lld", &a, &b, &c);


		if (a == 1)
		{
			//b번쨰 수를 c로 바꿈
			long long diff = c - arr[b];

			arr[b] = c;

			update(b, diff,1, 1, N);
		}
		else if (a == 2)
		{
			printf("%lld\n", query(1, N, 1, b, c));
		}
	
	}
	return 0;
}
