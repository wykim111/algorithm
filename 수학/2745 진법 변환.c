/*
	36진법 까지 존재
	가장 우측부터 sum = [0...k-1, n^k + n^(k-1) + ... + n^0]

*/
#include<stdio.h>
#include<string.h>
#include<math.h>

char str[101];
int N;

int main()
{
	int strLen = 0;
	int num = 0;

	scanf("%s %d", str, &N);
	getchar();
	
	strLen = strlen(str);

	for (int i = 0; i < strLen; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			num += (str[i] - 'A' + 10)*pow(N, strLen - i - 1);
		}
		else
		{
			num += (str[i] - '0')*pow(N, strLen - i - 1);
		}
	}

	printf("%d\n",num);

	return 0;
}
