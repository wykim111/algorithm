/*
���� ��, �ڽ��� ���ϴ� �ܹ��ſ� ���Ḧ �ϳ��� ���, ��Ʈ�� �����ϸ�, ������ �հ迡�� 50���� �� ������ ��Ʈ �޴��� ������ �ȴ�.
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