#include<stdio.h>

int arr[100001];
int size = 0;

void heapify(int root)
{
	int minIdx = root;
	int left = root * 2;
	int right = (root * 2) + 1;

	//root보다 작은 자식 노드의 인덱스 탐색
	if (left <= size && arr[minIdx] > arr[left])
	{
		minIdx = left;
	}
	if (right <= size && arr[minIdx] > arr[right])
	{
		minIdx = right;
	}

	//최솟값을 가진 인덱스를 찾은 경우 부모노드로 올림
	if (minIdx != root)
	{
		int temp;
		temp = arr[root];
		arr[root] = arr[minIdx];
		arr[minIdx] = temp;

		heapify(minIdx);
	}
}


void Insert(int num)
{
	int temp = ++size;

	while (temp > 1 && num < arr[temp / 2])
	{
		arr[temp] = arr[temp / 2];
		temp /= 2;
	}

	arr[temp] = num;

}

int extarct()
{
	int delData = arr[1];

	if (size == 0)
	{
		return 0;
	}

	arr[1] = arr[size];
	size--;
	heapify(1);

	return delData;
}



int main()
{
	int N;
	//int array1[1000];
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);

		if (num == 0)
		{
			if (size == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", extarct());
			}
		}
		else
		{
			Insert(num);
		}

	}


	return 0;
}
