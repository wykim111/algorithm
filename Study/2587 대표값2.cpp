/*
� ������ ���� ��, �� ������ ��ǥ�ϴ� ������ ���� ���ϰ� ���̴� ���� ����̴�. ����� �־��� ��� ���� ���� ���� ������ ���� ���̴�. 
���� ��� 10, 40, 30, 60, 30�� ����� 34�� �ȴ�.

��� �̿��� �� �ٸ� ��ǥ������ �߾Ӱ��̶�� ���� �ִ�. �߾Ӱ��� �־��� ���� ũ�� ������� �þ� ������ �� ���� �߾ӿ� ���� ���̴�. 
���� ��� 10, 40, 30, 60, 30�� ���, ũ�� ������� �þ� ������ 10 30 30 40 60�� �ǰ� ���� �߾Ӱ��� 30 �� �ȴ�.

�ټ� ���� �ڿ����� �־��� �� �̵��� ��հ� �߾Ӱ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

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
	
	//�������� ����
	bubbleSort(arr, 5);

	//�߾Ӱ� ���ϱ�
	midRet = arr[size / 2];

	printf("%d\n", avr);
	printf("%d\n", midRet);

	return 0;
}