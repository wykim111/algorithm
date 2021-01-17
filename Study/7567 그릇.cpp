#include<stdio.h>
#include<string.h>

char str[51];

int main()
{
	int len;
	int ret = 10;
	int ptr1=0, ptr2=1;

	scanf("%s", str);

	len = strlen(str);

	for (int i = 1; i < len; i++)
	{
	
			//이전 위치에 있는 데이터가 같은 경우
			if (str[i] == str[i - 1])
			{
				ret += 5;
			}
			else
			{
				ret += 10;
			}
		
	}
	printf("%d\n", ret);


	return 0;
}