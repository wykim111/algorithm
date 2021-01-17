#include<stdio.h>

int front = 0;
int rear = 3;
int N;
int arr[10];
int ret = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

int main()
{
	int temp1, temp2, temp3, temp4;
	int i, j, k,f;
	int rIdx;
	int ptr1, ptr2;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (rIdx = N - 3; rIdx > 0; rIdx--)
	{
		temp1 = 1;
		for (i = 0; i < rIdx; i++)
		{
			temp2 = 1;
			temp1 *= arr[i];
				for (j = i + 1; j < N - 2; j++)
				{
					temp2 *= arr[j];
					temp3 = 1;
					for (k = j + 1; k < N - 1; k++)
					{
						temp3 *=arr[k];
						temp4 = 1;
						for (f = k + 1; f < N; f++)
						{
							temp4 *= arr[f];
						}
						ret = max(ret, temp1 + temp2 + temp3 + temp4);
					}
				}
		}
	}
	printf("%d\n", ret);
	return 0;
}
