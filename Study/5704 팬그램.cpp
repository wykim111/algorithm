/*
	�� ������ �ҹ��� ���ĺ��� a����z���� �� ���� ������ 1 �ƴϸ� 0
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int alphabet[26];
char str[202];

void init()
{
	memset(str, 0, sizeof(str));
	memset(alphabet, 0, sizeof(alphabet));
}

char isCheck()
{
	for (int i = 0; i < 26; i++)
	{
		//printf("%s %d\n", __func__, alphabet[i]);
		 //���ĺ��� �������� ������ 0����
		if (alphabet[i] == 0)
			return 'N';
	}
	return 'Y';
}

int terminate(int len)
{
	if (len == 1 && str[0] == '*')
		return 1;
	return 0;
}

int main()
{
	while (1)
	{
		int len = 0;

		init();

		fgets(str, sizeof(str), stdin);
		len = strlen(str);

		/*
			���� ������ �����Ƿ� ������ �η� �ٲٰ� �ٽ� ���ڿ� ���� ����
		*/
		str[len - 1] = '\0';
		len = strlen(str);

		
		//���α׷� ����
		if (terminate(len) == 1)
		{
			break;
		}
		
		for (int i = 0; i < len; i++)
		{
			
			alphabet[str[i] - 'a'] = 1;
		}

		printf("%c\n", isCheck());
	}


	return 0;
}