/*
주어진 숫자의 각 자릿수를 더한다.
결과가 한 자릿수가 될 때 까지 규칙1을 반복한다.

*/
#include<stdio.h>

int getDigit(int num)
{
	int digit = 0;

	while (num % 10 != 0)
	{
		digit++;
		num = num / 10;
	}

	return digit;
}
int getSum(int num)
{
	int retSum = 0;
	
	while (num != 0)
	{
		retSum += num % 10;
		num = num / 10;
	}


	return retSum;
}
int main()
{
	int num;
	int  sum = 0;

	while (scanf("%d", &num) && num != 0)
	{
		int temp = num;

		while (1)
		{

			if (getDigit(temp) == 1)
			{
				sum = getSum(temp);
				break;
			}

			temp = getSum(temp);

		}

		printf("%d\n", sum);
	}

	return 0;
}
