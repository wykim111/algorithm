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

	//���� �ε����� mid�ε��� ����, �ĸ��ε����� right�ε��� ���Ϸ� Ž��
	//�����ε����� �ĸ��ε����� ������ ��(������������)

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			temp[Merge_Idx++] = arr[fIdx++];
		else
			temp[Merge_Idx++] = arr[rIdx++];
	}

	//fidx Ȥ�� ridx���� ���� ������ �����Ͱ� �����ִ� ���

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
		���� �� �Ǿ����� üũ
	
	printf("�������� ����\n");
	
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