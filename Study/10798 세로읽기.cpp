#include<stdio.h>
#include<string.h>

char str[5][17];

int main()
{
	int maxLen = 0;
	int len = 0;

	for (int i = 0; i < 5; i++)
	{
		scanf("%s", str[i]);

		while (getchar() != '\n');

		len = strlen(str[i]);

		if (maxLen < len)
			maxLen = len;
	}
	/*
	for (int i = 0; i < 5; i++)
	{
		printf("%s", str[i]);
	}
	printf("\n");
	*/

	for (int i = 0; i < maxLen; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (str[j][i] == '\0')
				continue;
			printf("%c", str[j][i]);
		}
	}
	printf("\n");

	return 0;
}