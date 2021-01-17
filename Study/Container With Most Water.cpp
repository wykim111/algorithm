#include<stdio.h>


/*
	��� Ǯ�...
	1. left �����ʹ� 0�� ����Ų��.
	2. right �����ʹ� ������ �ε����� ����Ų��.
	3. left�� right�� ���� ���� �����͸� ���ϰ� left�� right ���ݸ�ŭ ���Ѵ�.
	4. 3���� ���� ���� ������ �ִ񰪰� ���Ѵ�.
	5. left����Ű�� �����Ͱ� right�� ����Ű�� �����ͺ��� ���� ��� left�� 1�� ����
	6. �ݴ��� ���
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