#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char str[1002];
char convRule[27];

int main()
{
	int T;

	scanf("%d", &T);
	getchar();

	while (T--)
	{
		int strLen = 0;

		memset(str, 0, sizeof(str));
		memset(convRule, 0, sizeof(convRule));

		fgets(str, sizeof(str), stdin);
		strLen = strlen(str);
		str[strLen - 1] = '\0';
		strLen = strlen(str);

		scanf("%s", convRule);
		getchar();
		for (int i = 0; i < strLen; i++)
		{
			if (str[i] == ' ')
			{
				printf(" ");
				continue;
			}
			printf("%c", convRule[str[i]-'A']);
		}
		printf("\n");

	}


}
