/*
	�������� �����ϴ� ������ ������ ����ϵ��� ��

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
	
		printf("arr[%d]�� arr[%d]�� ��ȯ�մϴ�.\n",i,size-i-1);
		
		for (int j = 0; j < size; j++)
		{
			printf("%d ", arr[j]);
		}
		printf("\n");

	}
	printf("���� ������ �����մϴ�.\n");
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