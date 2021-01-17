/*
	1.배열 오름차순 정리
	2. 순열 진행

*/

#include<stdio.h>
#include<stdlib.h>
int ret[9];
int visit[9];
int arr[9];
int N, M;

int cmp(const void* p1, const void* p2)
{
	int  n1 = *(int*)p1;
	int n2 = *(int*)p2;

	return n1 > n2;
}

void go(int idx)
{
	if (idx == M)
	{
		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 1)
			continue;
		visit[i] = 1;
		ret[idx] = arr[i];
		go(idx + 1);
		visit[i] = 0;
	}
	return;
}
int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, N, sizeof(int), cmp);
	/*	정렬 확인
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}
	*/
	go(0);

	return 0;
}