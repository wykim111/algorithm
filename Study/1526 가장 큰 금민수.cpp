/*
	숫자를 10으로 나누어 각 자리수의 숫자가 4혹은7인지 판별한 뒤 맞으면 기존의max와 비교하여 max에 저장
*/
#include<stdio.h>

int num;


int isFourSeven(int n)
{
	int temp = n;
	int remain;
	int flag = 0;

	while (temp != 0)
	{
		remain = temp % 10;
		
		if (remain == 4)
		{
			flag = 1;
		}
		else if (remain == 7)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
		}

		if (flag == 0)
		{
			return 0;
		}

		temp = temp / 10;
	}
//	printf("%d\n", n);
	return 1;
}

int main()
{
	int maxRet = 0;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		if (isFourSeven(i) == 1)
		{
			if (i > maxRet)
			{
				maxRet = i;
			}
		}
	}

	printf("%d\n", maxRet);

	return 0;
}