/*
같은 눈이 3개가 나오면 10,000원+(같은 눈)*1,000원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다.
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.
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
		//같은 눈이 몇개 나오는지 카운트
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

	//같은 눈 카운트
	sameFlag = sameNum(dice, 3,&maxNum);

	switch (sameFlag)
	{
	case 1:
		ret = dice[2] * 100; //오름차순 정렬로 끝값이 가장 큼
		break;
	case 2:
		ret = 1000 + (maxNum) * 100;
		break;
	case 3:
		ret = 10000 + (dice[2]) * 1000; //모두 같은 값이므로 아무거나 택1
		break;
	default:
		break;
	}

	printf("%d\n", ret);

	return 0;
}