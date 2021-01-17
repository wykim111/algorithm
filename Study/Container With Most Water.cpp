#include<stdio.h>


/*
	어떻게 풀까나...
	1. left 포인터는 0을 가르킨다.
	2. right 포인터는 마지막 인덱스를 가르킨다.
	3. left와 right중 가장 작은 데이터를 구하고 left와 right 간격만큼 곱한다.
	4. 3번에 대한 답을 기존의 최댓값과 비교한다.
	5. left가르키는 데이터가 right가 가르키는 데이터보다 작은 경우 left는 1씩 증가
	6. 반대의 경우
*/
unsigned int max = 0;


int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;

	return n1;
}
int maxArea(int* height, int heightSize) {

	int left = 0;
	int right = heightSize - 1;
	//	int sum = 0;
	//	int maxIdx1;

	while (left < right)
	{
		unsigned int temp = 0;

		temp = (min(height[left], height[right]) * (right - left));

		if (temp > max)
			max = temp;

		if (height[left] <= height[right])
		{
			left += 1;
		}
		else
		{
			right -= 1;
		}
	}

	return max;
}


int main()
{
	int arr[] = { 1,1 };
	int size = sizeof(arr) / sizeof(arr[0]);


	printf("%d\n",maxArea(arr, size));

	return 0;
}