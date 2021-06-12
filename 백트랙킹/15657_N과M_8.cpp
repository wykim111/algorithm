/*
	중복조합
*/

#include<stdio.h>

int N, M;
int arr[8];
int perm[8];

void bubbleSort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
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

void go(int dep, int curIdx)
{
	if (dep == M)
	{
		for (int i = 0; i < dep; i++)
		{
			printf("%d ", perm[i]);
		}
		printf("\n");

		return;
	}

	for (int i = curIdx; i < N; i++)
	{
		perm[dep] = arr[i];
		go(dep + 1, i);
		perm[dep] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	bubbleSort(N);
	go(0, 0);

	return 0;
}
