/*
	key�� �Է��Ͽ� �迭�� Ž���Ͽ� �����ϴ� �ε����� ����
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
	printf("key �Է�:");
	scanf("%d", &key);

	num = search_idx(arr, n, key, ret);
	if (num == -1)
	{
		printf("ã�� key�� �����ϴ�\n");
		
		return 0;
	}
	
	
	printf("��ȯ�� = %d\n", num);
	

	free(arr);
	free(ret);

	return 0;
}