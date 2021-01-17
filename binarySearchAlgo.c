#include<stdio.h>

int binarySearch(int * arr, int key,int left,int right)
{
//	printf("right = %d\n", right);

	while (left <= right)
	{
		int mid = (left + right) >> 1;

		if (arr[mid] == key)
			return mid;
	
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	return -1;
}
int main()
{
	int arr[5] = { 3,7,8,11,50 };
	int size = sizeof(arr) / sizeof(arr[0])-1;
	int flag = 0;
	int key;

	scanf("%d", &key);
	flag = binarySearch(arr, key, 0, size);
	if (flag != -1)
		printf("key = %d find %d\n",key, flag+1);
	else
		printf("fail(%d) key ",flag);

	return 0;
}