/*
	투 포인터 알고리즘을 이용해 high는 배열의 끝에 가만히 두고 low는 배열의 맨 처음부터 이동하여 high와
	만나면 종료
	1. 배열을 가르키는 포인터를 따로 선언함.
	2. 위의 포인터의 데이터와 low가 가르키는 데이터가 같으면 스킵
	3. 다르면 배열을 가르키는 포인터를 먼저 증가 시킨뒤에 그 위치에 low가 가르키는 데이터를 저장
*/
#include<stdio.h>
#include<stdlib.h>
/*
	버블정렬
*/
void bubblesort(int* arr, int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp;
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int* distinct(int* low,int* high)
{
	if (low == high)
		return high;

	int* res;

	res = low;

	while ((++low) != high)
	{
		//같은 데이터가 있으면 넘어감
		if (*res == *low)
		{
			continue;
		}
		else//같은 데이터가 아니면 res를 증가시켜서 그 공간에 데이터를 저장
		{
			*(++res) = *low;
		}
	}
	return res++;
}

int main()
{
	int arr[10] = { 1,3,1,5,4,7,5,2,9,9 };
	int* end;
	bubblesort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//중복된거 제거 이후의 인덱스에는 정렬된 원본 배열의 데이터가 그대로 있으므로 제거.
	end = distinct(arr+0, arr+10);
	//중복제거 이후의 원본 인덱스 데이터 제거
	//이부분 채워야 함
	//중복제거
	printf("중복제거 이후\n");
	//반환된 주소까지 탐색
	for (int* iter = arr; iter <= end; iter++)
	{
		printf("%d ", *iter);
	}
	return 0;
}
