/*
	1. 첫번쨰  원소를 저장하는 변수를 생성
	2. arr[i] = arr[i+1] 로 뒤의 원소를 앞으로 1칸씩 이동
	3. 첫번째 원소를 저장한 변수를 arr[N-1]에 저장
	4. 위의 과정을 K번만큼 반복

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