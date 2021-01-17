#include<stdio.h>
#include<stdlib.h>

int cmp(const void* n1, const void * n2)
{
	int* num1 = n1;
	int* num2 = n2;

	if (*num1 > *num2)
		return 1;
	else if (*num1 < *num2)
		return -1;
	else
		return 0;
}

int bin_search(const int a[],int n,int key)
{
	int start = 0;
	int end = n - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}

	return -1;
}


int main()
{
	int arr[10] = { 0, };
	
	for(int i=0;i<10;i++)
		scanf("%d", &arr[i]);

	qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(int),cmp);

	printf("정렬 이후\n");

	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("7을 인덱스 %d에 찾았습니다\n",bin_search(arr, 10, 7));

	return 0;
}