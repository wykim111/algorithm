#include<stdio.h>

int T;

//버블정렬

void buubbleSort(int* arr, int size)
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

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		int num[10];

		for (int i = 0; i < 10; i++)
		{
			scanf("%d", &num[i]);
		}
		
		buubbleSort(num, sizeof(num) / sizeof(int));

		printf("%d\n", num[7]);
	}
	return 0;
}