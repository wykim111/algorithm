/*
018�� ���� �ִ� �� �߿��� 2, 0, 1, 8�� ��� �����ϴ� ������ 2018�� ������ ���̴�. 
2018�� ������ �� �߿��� 2, 0, 1, 8�� ������ ��� �Ȱ��� ������ 2018�� �����ִ� ���̴�. 
2018�� ���� �ִ� ���� �ƴ� ���� ������ 2018�� ���� ���� ���̴�.

*/

#include<stdio.h>
#include<string.h>

char str[11];
int digit[10];

int main()
{
	int len = 0;
	int ret = -1;

	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		digit[str[i] - '0']++;
	}

	for (int i = 0; i < 10; i++)
	{
		if (i == 0 || i == 1 || i == 2 || i == 8)
			continue;
		if (digit[i] != 0) // 2018 �̿��� ���ڰ� �ִ� ���
		{
			ret = 0;
			break;
		}
	}
	if (ret != 0)
	{
		ret = 1;
		if (digit[0] > 0 && digit[1] > 0 && digit[2] > 0 && digit[8] > 0)
		{
			ret = 2;
			//2,0,1,8�� ��� ���� ����(��� > 0)
			if ((digit[0] == digit[1]) && (digit[1] == digit[2]) && (digit[2] == digit[8]))
			{
				ret = 8;

			}
		}
	}

	printf("%d\n", ret);

	return 0;
}