#include<stdio.h>
#include<string.h>

char str[101];

int main()
{
	int len = 0;

	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		else
		{

		}
	}
	printf("%s", str);

	return 0;
}