#include<stdio.h>
#include<string.h>

int n;
char str[30];

int main()
{
	scanf("%d", &n);

	//���� ���� ����
	while (getchar() != '\n');

	while (n--)
	{
		int len = 0;
		int g = 0, b = 0;

		memset(str, 0, sizeof(str));
		fgets(str, sizeof(str), stdin);

		len = strlen(str);

		str[len - 1] = '\0';

		len = strlen(str);

		//printf("len=%d\n", len);
		//'g'�� 'b' ī��Ʈ

		for (int i = 0; i < len; i++)
		{
			if (str[i] == 'g' || str[i] =='G')
				g++;
			if (str[i] == 'b' || str[i] == 'B')
				b++;

		}

		//printf("g = %d b= %d\n", g, b);

		if (g > b)
		{
			strcat(str, " is GOOD");
			puts(str);
		}
		else if ( g < b)
		{
			strcat(str, " is A BADDY");
			puts(str);
		}
		else
		{
			strcat(str, " is NEUTRAL");
			puts(str);
		}
	}

	return 0;
}