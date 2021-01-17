#include<stdio.h>
#include<stdlib.h>

int N,M;

typedef struct _data
{
	int num;
	int key;//M개의 순서 보장
	int flag;//M개중에 N개와 일치하는게 있는지 없는지 체크
}Data;

int cmp1(const void* p1, const void* p2)
{
	Data* D1 = (Data*)p1;
	Data* D2 = (Data*)p2;
	
	//오름차순
	return (D1->num - D2->num);
}
int cmp2(const void* p1, const void* p2)
{
	Data* D1 = (Data*)p1;
	Data* D2 = (Data*)p2;

	//오름차순
	return (D1->key - D2->key);
}
void BinarySearch(Data* arr, int num)
{
	int left = 0;
	int right = M - 1;

	while (left<=right)
	{
		int mid = (left + right) / 2;
		
		if (arr[mid].num == num)
		{
			arr[mid].flag = 1;//M개의 배열에 있는지 체크
			return;
		}
		else if (arr[mid].num < num)
		{
			left = mid + 1;
		}
		else// arr[mid] > num
		{
			right = mid - 1;
		}
	}
	return;
}

int main()
{
	int* arr1;
	Data* arr2;

	scanf("%d", &N);

	arr1 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr1[i]);
	}
	scanf("%d", &M);

	arr2 = (Data*)malloc(sizeof(Data)*M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr2[i].num);
		arr2[i].key = i + 1;
		arr2[i].flag = 0;
	}

	qsort(arr2, M, sizeof(Data), cmp1);
	/*
	for (int i = 0; i < M; i++)
	{
		printf("num= %d, key = %d \n", arr2[i].num,arr2[i].key);
	}
	*/
	for (int i = 0; i < N; i++)
	{
		 BinarySearch(arr2, arr1[i]);
		/*
		if (ret == 0)
			printf("%d no match\n",arr1[i]);
		else
			printf("%d match\n",arr1[i]);
		*/
	}
	qsort(arr2, M, sizeof(Data), cmp2);

	//Print
	for (int i = 0; i < M; i++)
	{
		printf("%d ", arr2[i].flag);
		//printf("key = %d flag = %d data = %d\n", arr2[i].key, arr2[i].flag, arr2[i].num);
	}
	printf("\n");

	return 0;
}