/*
어떤 수들이 있을 때, 그 수들을 대표하는 값으로 가장 흔하게 쓰이는 것은 평균이다. 평균은 주어진 모든 수의 합을 수의 개수로 나눈 것이다. 
예를 들어 10, 40, 30, 60, 30의 평균은 34가 된다.

평균 이외의 또 다른 대표값으로 중앙값이라는 것이 있다. 중앙값은 주어진 수를 크기 순서대로 늘어 놓았을 때 가장 중앙에 놓인 값이다. 
예를 들어 10, 40, 30, 60, 30의 경우, 크기 순서대로 늘어 놓으면 10 30 30 40 60이 되고 따라서 중앙값은 30 이 된다.

다섯 개의 자연수가 주어질 때 이들의 평균과 중앙값을 구하는 프로그램을 작성하시오.

*/

#include<stdio.h>

int average(int sum,int size)
{
	return sum / size;
}

void bubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int arr[5],size = 5;
	int sum = 0,avr = 0;
	int midRet = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	
		sum += arr[i];
	}
	avr = average(sum, 5);
	
	//오름차순 정렬
	bubbleSort(arr, 5);

	//중앙값 구하기
	midRet = arr[size / 2];

	printf("%d\n", avr);
	printf("%d\n", midRet);

	return 0;
}