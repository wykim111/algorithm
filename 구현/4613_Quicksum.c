#include <stdio.h>
#include <string.h>

char str[257];



int main()
{
	while (1)
	{
		int len = 0;

		memset(str, 0, sizeof(str));
		fgets(str, sizeof(str), stdin);


		len = strlen(str);
		str[len - 1] = '\0';
		len = strlen(str);

		if (strcmp(str, "#") == 0)
		{
			break;
		}

		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			if (str[i] == ' ')
			{
				continue;
			}
			sum += ((str[i] - 'A') + 1) * (i + 1);
		}

		printf("%d\n", sum);

	}

	return 0;
}
