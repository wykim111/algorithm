/*
	1. ���� 10���� 42�� ���� �������� ���ϰ� �迭�� ����
	2. �������� ����
	3. ������ ��, ���� ���� �ڿ� ������ ��� ��ŵ�ϰ� �ٸ����� ���� ������
	   �ݺ��Ѵ�.
	4. �ٸ� ���� ������ �ٸ� �� ī��Ʈ�� ������Ű�� 3~4 �ݺ��Ѵ�
*/

/*
	�� ���� �̷��� ���� ���� Ǯ�� ���� ���� ������� Ǯ���
	arr[n%42]++�� �ش� �ε����� �����ؼ� ī��Ʈ�� �Ͽ�
	arr[n%42]�� 0�� �ƴ� ��츸 ī��Ʈ�ϸ� ��

*/
#include<stdio.h>

int remainder(int n)
{

	return n % 42;
}
void bubbleSort(int* a,int size)
{
	
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			int temp;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[10];
	int ret[10];
	int idx = 0;
	for (int i = 0; i < 10; i++)
	{
		int num;

		scanf("%d", &num);

		arr[i] = remainder(num);
	}
	/*
	//���
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d]= %d\n", i, arr[i]);
	}
	*/
	bubbleSort(arr,10);
	int ptr1, ptr2;
	//for�� ���ǹ��� ���� ������ ���� �� ���� ���� ���� ���
	//���� �˻� �ʰ��� �Ǿ� �Ѿ
	//�ٸ� ���
	// 
	for (ptr1 = 0; ptr1 < 10; ptr1++)
	{
		int flag = 1; //������ ���� üũ
		for (ptr2 = ptr1 + 1; ptr2 < 10; ptr2++)
		{
			if (arr[ptr1] != arr[ptr2])
			{
				break;
			}
		}
		//inner for������ ���� �ٸ� ���� ����Ű��, out for������ �������� �����Ƿ�
		// 1���� �����ش�.
		ptr1 = ptr2 - 1;
		ret[idx++] = arr[ptr1];
		//������ ���� ����
	
	}
	/* ���� üũ
	for (int i = 0; i <idx; i++)
	{
		printf("arr[%d]= %d\n", i, ret[i]);
	}
	*/
	printf("%d\n", idx);

	return 0;

}