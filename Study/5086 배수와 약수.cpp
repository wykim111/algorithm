#include<stdio.h>

int main()
{
	int num1,num2;

	while (scanf("%d %d",&num1,&num2) && (num1 != 0 && num2 != 0))
	{
		if (num2 % num1 == 0)
		{
			printf("factor\n");
		}
		else if (num1 % num2 == 0)
		{
			printf("multiple\n");
		}
		else
		{
			printf("neither\n");
		}
	}

	return 0;
}