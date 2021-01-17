/*
���� ���� 3���� ������ 10,000��+(���� ��)*1,000���� ����� �ް� �ȴ�.
���� ���� 2���� ������ ��쿡�� 1,000��+(���� ��)*100���� ����� �ް� �ȴ�.
��� �ٸ� ���� ������ ��쿡�� (�� �� ���� ū ��)*100���� ����� �ް� �ȴ�.
*/

#include<stdio.h>

void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
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

int sameNum(int* arr,int size,int* pNum)
{
	int maxSameCnt = 0;

	for (int i = 0; i < size - 1; i++)
	{
		int cnt = 1;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] == arr[j])
			{
				cnt++;
			}
		}
		//���� ���� � �������� ī��Ʈ
		if (maxSameCnt < cnt)
		{
			*pNum = arr[i];
			maxSameCnt = cnt;
		}
	}

	return maxSameCnt;
}

int main()
{
	int dice[3];
	int sameFlag = 0;
	int ret = 0;
	int maxNum = 0;

	scanf("%d %d %d", &dice[0], &dice[1], &dice[2]);

	bubbleSort(dice, 3);

	//���� �� ī��Ʈ
	sameFlag = sameNum(dice, 3,&maxNum);

	switch (sameFlag)
	{
	case 1:
		ret = dice[2] * 100; //�������� ���ķ� ������ ���� ŭ
		break;
	case 2:
		ret = 1000 + (maxNum) * 100;
		break;
	case 3:
		ret = 10000 + (dice[2]) * 1000; //��� ���� ���̹Ƿ� �ƹ��ų� ��1
		break;
	default:
		break;
	}

	printf("%d\n", ret);

	return 0;
}