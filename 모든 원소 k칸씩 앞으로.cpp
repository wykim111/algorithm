/*
	1. ù����  ���Ҹ� �����ϴ� ������ ����
	2. arr[i] = arr[i+1] �� ���� ���Ҹ� ������ 1ĭ�� �̵�
	3. ù��° ���Ҹ� ������ ������ arr[N-1]�� ����
	4. ���� ������ K����ŭ �ݺ�

*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int* arr;
	int N,K;

	scanf("%d %d", &N, &K);

	arr = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < K; i++)
	{
		int temp = arr[0];

		for (int j = 0; j < N - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		arr[N - 1] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}