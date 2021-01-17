/*
문할 때, 자신이 원하는 햄버거와 음료를 하나씩 골라, 세트로 구매하면, 가격의 합계에서 50원을 뺀 가격이 세트 메뉴의 가격이 된다.
*/
#include<stdio.h>

int hamburger[3];
int beverage[2];

int main()
{
	int minRet = (int)1e9;
	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &hamburger[i]);
	}
	
	for (int i = 0; i < 2; i++)
	{
		scanf("%d", &beverage[i]);
	}

	for (int i = 0; i < 3; i++)
	{
		int total = 0;

		for (int j = 0; j < 2; j++)
		{
			total = hamburger[i] + beverage[j] - 50;
			
			if (minRet > total)
			{
				minRet = total;
			}
		}
	}
	printf("%d\n", minRet);
	
	return 0;
}