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
	
			//���� ��ġ�� �ִ� �����Ͱ� ���� ���
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