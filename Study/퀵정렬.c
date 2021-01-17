#include<stdio.h>
#include<stdlib.h>

int N;
int cnt = 0;

void swap(int* a, int idx1, int idx2)
{
	int temp;

	temp = a[idx1];
	a[idx1] = a[idx2];
	a[idx2] = temp;
}

int quicksort(int* a, int left, int right)
{
	int temp;
	int pivot = a[left];
	int lo = left+1;
	int hi = right;

	printf("\n[ %d단계]: pivot=%d]\n", ++cnt, pivot);

	while (lo <= hi)
	{
		while (a[lo] <= pivot && (lo <= right))
			lo++;
		while (a[hi] >= pivot && (hi >= (left+1)))
			hi--;

		if (lo <= hi)
		{
			swap(a, lo, hi);
		}
		

	}//while

	//L==R인 경우
	swap(a, left, hi);

	for (int t = 0; t <= right; t++)
	{
		printf("%d ", a[t]);
	}
	printf("\n");

	return hi;
}

void partition(int* a,int left,int right)
{
	if (left <= right)
	{
		int pivot;
		pivot = quicksort(a, left, right);
		partition(a, left, pivot - 1);//pivot 기준 왼쪽 영역
		partition(a, pivot + 1, right);//pivot 기준 오른쪽 영역
	}
}

int main()
{
	int* arr;

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	partition(arr, 0, N - 1);

	printf("\n출력결과 조회\n");

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}
