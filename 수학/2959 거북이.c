/*
	1. 배열 선언 size = 4
	2. 오름차순 정렬
	3. 직접 그려가며 규칙 파악

	앞으로 네 걸음간다.
	오른쪽으로 방향을 바꾼다.
	한 걸음 앞으로 간다.
	오른쪽으로 방향을 바꾼다
	세 걸음 걷는다.
	방향을 다시 90도 회전한다.
	두 걸음 앞으로 걷는다.
	============================
		  ㅡ
		|    | 
		|    |
	  ㅡ| ㅡ |
		|
	==============================
	0번째 원소와 2번쨰 원소를 곱하여 출력
*/

#include<stdio.h>


int arr[4];

void bubbleSort()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4 - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);


	bubbleSort();

	printf("%d\n", arr[0] * arr[2]);

	return 0;
}
