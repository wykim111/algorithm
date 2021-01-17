#include<stdio.h>

int main()
{
	int num1,num2;
	char op1;
	int sum = 0 ;

	scanf("%d", &num1);
	sum = num1;
	while (1)
	{
		scanf(" %c", &op1);
		
		if (op1 == '=')
			break;

		scanf("%d", &num2);
		if (op1 == '+')
		{
			sum +=  num2;
		} 
		else if (op1 == '-')
		{
			sum -=  num2;
		}
		else if (op1 == '*')
		{
			sum *= num2;
		}
		else if (op1 == '/')
		{
			sum /= num2;
		}
	}
	printf("%d\n", sum);

	return 0;
}