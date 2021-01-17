#include<stdio.h>
#include<stdlib.h>

int arr[100000];
int N;

void MergeSort(int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid+1;
	int* temp = (int*)malloc(sizeof(int)*(right + 1));
	int Merge_Idx = left;

	//전면 인덱스는 mid인덱스 이하, 후면인덱스는 right인덱스 이하로 탐색
	//전면인덱스롸 후면인덱스의 데이터 비교(오름차순기준)

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			temp[Merge_Idx++] = arr[fIdx++];
		else
			temp[Merge_Idx++] = arr[rIdx++];
	}

	//fidx 혹은 ridx에서 아직 정렬할 데이터가 남아있는 경우

	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; i++,Merge_Idx++)
		{
			temp[Merge_Idx] = arr[i];
		}
	}
	else
	{
		for (int i = fIdx; i <= mid; i++, Merge_Idx++)
		{
			temp[Merge_Idx] = arr[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = temp[i];
	}
	free(temp);

}

int Binary_Search(int start, int end,int key)
{

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (key == arr[mid])
			return 1;
		else if (key > arr[mid])
			start = mid + 1;
		else
		{
			end = mid - 1;
		}
	}
	return 0;
}

void partition(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		partition(left, mid);
		partition(mid + 1, right);
		MergeSort(left, mid, right);
	}
}

int main()
{
	int cnt;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	partition(0, N - 1);
	/*
		정렬 잘 되었는지 체크
	
	printf("병합정렬 진행\n");
	
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	*/
	scanf("%d", &cnt);
	
	for (int i = 0; i < cnt; i++)
	{
		int key;
		scanf("%d", &key);
		printf("%d\n", Binary_Search(0, N - 1, key));
	}


	return 0;
}