#include<stdio.h>
#include<stdlib.h>

int size = 0;

void Heap_Insert(int* a,int num)
{
	int idx;
	++size;
	idx = size;
	a[idx] = num;

	while (idx != 1 && a[idx] < a[idx/2])
	{
		a[idx] = a[idx / 2];
		idx /= 2;
	}
	a[idx] = num;

}
int Delete_Heap(int* a)
{
	int ret = a[1];
	int temp = a[size--];
	int parent, child;

	parent = 1;
	child = 2;

	while (child <= size)
	{
		if (child < size && a[child] > a[child + 1])
		{
			child++;
		}
		if (temp < a[child])
			break;

		a[parent] = a[child];
		parent = child;
		child *= 2;
		
	}
	a[parent] = temp;



	return ret;
}


int main()
{
	int* arr;
	int N;
	int data;
	int delete_data;
	scanf("%d", &N);

	arr = (int*)malloc(sizeof(int)*(N+1));

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &data);
		Heap_Insert(arr,data);
	}
	
	delete_data = Delete_Heap(arr);
	printf("Delete:%d\n", delete_data);
	for (int i = 1; i <= size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return 0;
}
