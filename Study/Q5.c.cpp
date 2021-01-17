/*
	이진탐색은 같은 숫자가 있을 떄 최초의  숫자가 있는 인덱스가 아닌 중간에 있는 인덱스를 반환하는데
	이 프로그램은 최초의 인덱스를 반환하도록 한다.
*/
#include<stdio.h>
#include<stdlib.h>

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;//오름차순
}

int bin_search2(const int a[], int n, int key)
{
	int start = 0;
	int end = n - 1;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (a[mid] == key)
		{
			while ((mid > start) && (a[mid-1] == key))
			{
				mid--;
			}
			return mid;
		}
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
	int arr[11];
	int ret;

	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &arr[i]);
	}

	qsort(arr, 11, sizeof(int), cmp);

	for (int i = 0; i < 11; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	ret = bin_search2(arr, 11, 8);

	if (ret == -1)
	{
		printf("키가 없습니다\n");
		return 0;
	}

	printf("해당 데이터는 최초 인덱스 %d에 있습니다\n", ret);

	return 0;
}