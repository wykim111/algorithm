#include<stdio.h>
#include<stdlib.h>

void mergeSort(int* arr, int s, int m, int e)
{
	int fIdx = s;
	int rIdx = m + 1;
	int Idx = s;
	int* tempArr;

	tempArr = (int*)malloc(sizeof(int)*(e+1));


	//fIdx�� rIdx �� �� �ϳ� ����Ű�� �迭�� ���� �Ϸ�� ��� ��������
	while (fIdx <= m && rIdx <= e)
	{
		if (arr[fIdx] < arr[rIdx])
		{
			tempArr[Idx] = arr[fIdx++];
		}
		else
			tempArr[Idx] = arr[rIdx++];

		Idx++;
	}

	//���� �ϳ��� ������ �Ϸ�� ���
	if (fIdx <= m)
	{
		while(fIdx<=m)
			tempArr[Idx++] = arr[fIdx++];
	}
	else
	{

		while (rIdx <= e)
			tempArr[Idx++] = arr[rIdx++];
	}
	
	for (int i = s; i <= e; i++)
	{
		arr[i] = tempArr[i];
	}

	free(tempArr);
}

void Partition(int* arr, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

		Partition(arr, start, mid);
		Partition(arr, mid + 1, end);
		mergeSort(arr, start, mid, end);
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

	Partition(arr, 0, N - 1);

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);
	printf("\n");
	return 0;
}