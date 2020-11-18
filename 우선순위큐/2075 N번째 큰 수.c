#include<stdio.h>

int arr[1501];
int size = 0;

void heapfy(int root)
{
	int smallest = root;
	int left = root * 2;
	int right = (root * 2) + 1;

	if (left <= size && arr[smallest] > arr[left])
		smallest = left;

	if (right <= size && arr[smallest] > arr[right])
		smallest = right;


	if (smallest != root)
	{
		int temp = arr[smallest];
		arr[smallest] = arr[root];
		arr[root] = temp;

		heapfy(smallest);

	}

}

void insert(int num)
{
	int tempSize;

	size++;
	tempSize = size;

	arr[size] = num;

	while (tempSize > 1 && num < arr[tempSize / 2])
	{
		arr[tempSize] = arr[tempSize /2];
		tempSize = tempSize / 2;
	}

	arr[tempSize] = num;
}

int deletePop()
{
	int remove = arr[1];

	arr[1] = arr[size];

	size--;

	heapfy(1);

	return remove;
}

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N*N; i++)
	{
		int num;

		scanf("%d", &num);

		insert(num);

		// N번째만 출력하면 되므로 다 inser할 필요없이 
		//정해진 사이즈를 초과하면 가장 작은걸 pop
		if (size > N)
		{
			deletePop();
		}
	}

	//최소힙으로 루트는 가장 작은걸 가르키고 원소는 N개까지 있으므로
	//루트가 N번째 원소이다.
	printf("%d\n", deletePop());

	return 0;
}




