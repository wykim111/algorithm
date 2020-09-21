#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char str[10];
char revStr[10];

void ReverceStr(int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		revStr[i] = str[length - 1 - i];
	}
	revStr[i] = '\0';
}

int match(int num)
{
	int temp = num,idx=0;
	char matchStr[10];
	int remain = 0;

	for (int i = 0; i < 10; i++)
	{
		matchStr[i] = 0;
	}

	while (temp != 0)
	{
		remain = temp % 10;
		matchStr[idx++] = remain + '0';
		temp = temp / 10;

	}
	matchStr[idx] = '\0';

	for (int i = 0; i < idx/2; i++)
	{
		if (matchStr[i] != matchStr[idx - 1 - i])
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	int N;

	scanf("%d", &N);

	getchar();

	while (N--)
	{
		int len = 0;
		int num1 = 0 , num2 = 0;
		int sum = 0;

		memset(str, 0, sizeof(str));
		memset(revStr, 0, sizeof(revStr));

		scanf("%s", str);
		getchar();
		
		len = strlen(str);

		ReverceStr(len);
		
		num1 = atoi(str);
		num2 = atoi(revStr);

		sum = (num1 + num2);

		//printf("sum = %d\n", sum);
		if (match(sum) == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}

	}
	return 0;
}
