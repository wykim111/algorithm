/*
	역순으로 정렬하는 과정을 일일히 출력하도록 함

*/
#include <stdio.h>
#include<string.h>


void reveseSort(int* arr, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - i-1];
		arr[size - i-1] = temp;
	
		printf("arr[%d]과 arr[%d]를 교환합니다.\n",i,size-i-1);
		
		for (int j = 0; j < size; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");

	}
	printf("역순 정렬을 종료합니다.\n");
}

int main()
{
	int N;
	int arr[1000];

	memset(arr, 0, sizeof(arr));

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	reveseSort(arr, N);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}