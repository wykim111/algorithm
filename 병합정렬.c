#include<stdio.h>
#include<stdlib.h>

void MergeSort(int arr[], int s, int m, int e)
{
	int fIdx = s;
	int rIdx = m + 1;
	int* sortArr;
	int idx = s;
	sortArr = (int*)malloc(sizeof(int)*(e + 1));

	while (fIdx <= m && rIdx <= e)
	{
		if (arr[fIdx] <= arr[rIdx])
		{
			sortArr[idx++] = arr[fIdx++];
		}
		else
		{
			sortArr[idx++] = arr[rIdx++];
		}
	}

	if (fIdx > m)
	{
		for (int i = rIdx; i <= e; i++)
		{
			sortArr[idx] = arr[i];
			idx++;
		}
	}
	else
	{
		for (int i = fIdx; i <= m; i++)
		{
			sortArr[idx] = arr[i];
			idx++;
		}
	}
	//ÀúÀå
	for (int i = s; i <= e; i++)
	{
		arr[i] = sortArr[i];
	}
	free(sortArr);
}


void partition(int* a, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;

		partition(a, start, mid);
		partition(a, mid + 1, end);
		MergeSort(a, start, mid, end);
	}
}

int main()
{
	int* arr;
	int N;

	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	partition(arr, 0, N-1);

	for (int i = 0; i < N; i++)
	{
		printf("%d", arr[i]);
	}
}
