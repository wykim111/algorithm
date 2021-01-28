/*
	1부터 1000000  돌면서 L이 포함 되지 않은 숫자를 N개까지 카운트하여
	N개 중 최대 수를 구함

*/

#include<stdio.h>
#include<string.h>

char str[7];

char* toString(int num)
{
	
	int idx = 0;
	memset(str, 0, sizeof(str));

	while (num != 0)
	{
		int remain =  num % 10;

		str[idx++] = remain + '0';

		num = num / 10;
	}

	for (int i = 0; i < idx / 2; i++)
	{
		char temp = str[i];
		str[i] = str[idx - i - 1];
		str[idx - i - 1] = temp;
	}


	return str;
}

int main()
{
	int N, L;
	int cnt = 0;
	int maxRet = 0;
	int num = 1;
	char* p = NULL;

	scanf("%d %d", &N, &L);

	for (int i = 0;i<N;i++)
	{
		p = toString(num++);
		int breakFlag = 0;

		for (int j = 0; j < strlen(p); j++)
		{
			if (p[j] == L + '0')
			{
				breakFlag = 1;
				break;
			}
		}

		if (breakFlag == 1)
		{
			i--;
		}

	}

	printf("%s\n", p);

	return 0;
}
