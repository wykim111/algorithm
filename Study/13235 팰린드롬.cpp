#include<stdio.h>
#include<string.h>

char str[21];

int main()
{
	int len = 0;
	int flag = 1;
	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len/2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
	{
		printf("false\n");
	}
	else
	{
		printf("true\n");
	}

	return 0;
}