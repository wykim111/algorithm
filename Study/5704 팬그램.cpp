/*
	각 문장의 소문자 알파벳을 a부터z까지 다 쓰여 있으면 1 아니면 0
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
		 //알파벳이 존재하지 않으면 0리턴
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
			끝에 개행이 있으므로 개행을 널로 바꾸고 다시 문자열 길이 갱신
		*/
		str[len - 1] = '\0';
		len = strlen(str);

		
		//프로그램 종료
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