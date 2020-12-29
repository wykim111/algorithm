/*
	구조체로 <숫자,숫자 빈도수>로 선언
	1.평균값을 구함
	2. 빈도수를 기준으로 내림차순 정렬

*/
#include<stdio.h>
#include<math.h>

typedef struct _number
{
	int digit;
	int cnt;

}number;

number num[10];
int idx = 0;

void init()
{
	for (int i = 0; i < 10; i++)
	{
		num[i].digit = 0;
		num[i].cnt = 0;
	}


}


void bubbleSort()
{
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < idx - i - 1; j++)
		{
			if (num[j].cnt < num[j + 1].cnt)
			{
				number stTemp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = stTemp;
			}
		}
	}

}


int main()
{
	int input;
	int sum = 0,avr = 0;

	init();

	for (int i = 0; i < 10; i++)
	{
		int flag = 0;

		scanf("%d", &input);
	
		sum += input;

		for (int j = 0; j < idx; j++)
		{
			if (num[j].digit == input)
			{
				flag = 1;
				num[j].cnt++;

				break;
			}

		}//j

		if (flag == 1)
			continue;

		num[idx].digit = input;
		num[idx].cnt++;

		idx++;
	}//i

	bubbleSort();

	//평균
	printf("%d\n", sum / 10);
	//최빈값
	printf("%d\n", num[0].digit);



	return 0;
}
