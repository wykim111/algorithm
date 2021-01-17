/*
	key를 입력하여 배열을 탐색하여 만족하는 인덱스를 저장
*/
#include<stdio.h>
#include<stdlib.h>

int search_idx(int* arr, int n,int key, int idx[])
{
	int size = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
		{
			idx[size++] = i;
		}
	}
	
	if (size == 0)
		return -1;

	printf("\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", idx[i]);
	}
	printf("\n");


	return size;
}
int main()
{
	int* arr;
	int n;
	int key;
	int* ret;
	int num;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int)*n);
	ret = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("key 입력:");
	scanf("%d", &key);

	num = search_idx(arr, n, key, ret);
	if (num == -1)
	{
		printf("찾는 key가 없습니다\n");
		
		return 0;
	}
	
	
	printf("반환값 = %d\n", num);
	

	free(arr);
	free(ret);

	return 0;
}