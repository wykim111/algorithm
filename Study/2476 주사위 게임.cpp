#include<stdio.h>
#include<string.h>

int N;
int dice[3];
int sameDice;



int same(int size)
{
	int maxSame = 1;
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		int cnt = 1;

		for ( j = i + 1; j < size; j++)
		{
			if (dice[i] != dice[j])
			{
				break;
			}
			cnt++;
		}
		i = j-1;//j++로 증가하므로, 현재 중복된 수와는 다른 수가 있는 경우 

		if (maxSame < cnt)
		{
			sameDice = dice[i];
			maxSame = cnt;
		}
	}
	return maxSame;
}

void bubbleSort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (dice[j] > dice[j + 1])
			{
				int temp = dice[j];
				dice[j] = dice[j + 1];
				dice[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int ret = 0;
	int maxRet = 0;

	scanf("%d", &N);

	while (N--)
	{
		//Init();
		for (int i = 0; i < 3; i++)
		{
			scanf("%d", &dice[i]);
		}

		bubbleSort(3);

		if (same(3) == 1)
		{
			ret = dice[2] * 100;
		}
		else if (same(3) == 2)
		{
			ret = 1000 + (sameDice * 100);
		}
		else
		{
			ret = 10000 + ((dice[0]) * 1000);
		}
	
		//printf("%d\n", ret);
		if (maxRet < ret)
		{
			maxRet = ret;
		}
	}
	
	printf("%d\n", maxRet);

	return 0;
}