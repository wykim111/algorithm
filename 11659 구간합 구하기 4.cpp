/*
	세그먼트 트리 응용

*/
#include<stdio.h>

int N,M;
int arr[100001];
int seg[100001 * 4];
int cnt = 0;

//각 구간의 노드들 초기화
int init(int node,int left,int right)
{
	cnt++;
	//자기 자신의 노드를 찾는 경우
	if (left == right)
	{
		//printf("left =%d, %d\n", left, arr[left]);
		return seg[node] = arr[left];
	}
	int mid = (left + right) >> 1;

	return seg[node] = init(node * 2, left, mid) + init(node * 2 + 1, mid + 1, right);

}

int query(int node, int left, int right, int low, int high)
{
	//지정된 범위를 벗어난 경우
	if (left > high || right < low)
		return 0;
	//지정된 범위 내에 속하는 경우
	if (low <= left && right <= high)
	{
		return seg[node];
	}

	int mid = (left + right) >> 1;

	return query(node * 2, left, mid,low,high) + query(node * 2 + 1, mid + 1, right,low,high);
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	init(1, 1, N);
	/*
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d\n", seg[i]);
	}
	*/
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n",query(1, 1, N, a, b));

	}

	return 0;
}