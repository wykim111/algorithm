/*
	숫자를 제외한 알파벳을 저장한다.
*/
#include<stdio.h>
#include<string.h>

char str[102];
char keyword[102];
char sequence[102];

int main()
{
	int len = 0;
	int idx = 0;

	scanf("%s", str);
	while (getchar() != '\n');

	scanf("%s", keyword);
	while (getchar() != '\n');

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			sequence[idx++] = str[i];
		}
	}

	sequence[idx] = '\0';

	if (strstr(sequence, keyword) != NULL)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}

	return 0;
}