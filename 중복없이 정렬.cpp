/*
	�� ������ �˰����� �̿��� high�� �迭�� ���� ������ �ΰ� low�� �迭�� �� ó������ �̵��Ͽ� high��
	������ ����
	1. �迭�� ����Ű�� �����͸� ���� ������.
	2. ���� �������� �����Ϳ� low�� ����Ű�� �����Ͱ� ������ ��ŵ
	3. �ٸ��� �迭�� ����Ű�� �����͸� ���� ���� ��Ų�ڿ� �� ��ġ�� low�� ����Ű�� �����͸� ����
*/
#include<stdio.h>
#include<stdlib.h>
/*
	��������
*/
void bubblesort(int* arr, int size)
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

int* distinct(int* low,int* high)
{
	if (low == high)
		return high;

	int* res;

	res = low;

	while ((++low) != high)
	{
		//���� �����Ͱ� ������ �Ѿ
		if (*res == *low)
		{
			continue;
		}
		else//���� �����Ͱ� �ƴϸ� res�� �������Ѽ� �� ������ �����͸� ����
		{
			*(++res) = *low;
		}
	}
	return res++;
}

int main()
{
	int arr[10] = { 1,3,1,5,4,7,5,2,9,9 };
	int* end;
	bubblesort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//�ߺ��Ȱ� ���� ������ �ε������� ���ĵ� ���� �迭�� �����Ͱ� �״�� �����Ƿ� ����.
	end = distinct(arr+0, arr+10);
	//�ߺ����� ������ ���� �ε��� ������ ����
	//�̺κ� ä���� ��
	//�ߺ�����
	printf("�ߺ����� ����\n");
	//��ȯ�� �ּұ��� Ž��
	for (int* iter = arr; iter <= end; iter++)
	{
		printf("%d ", *iter);
	}
	return 0;
}