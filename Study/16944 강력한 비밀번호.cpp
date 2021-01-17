/*
비밀번호는 알파벳 소문자, 대문자, 숫자, 특수문자로만 이루어져 있다.
비밀번호는 6글자 이상이어야 한다.
숫자는 하나 이상 포함되어야 한다.
알파벳 소문자는 하나 이상 포함되어야 한다.
알파벳 대문자는 하나 이상 포함되어야 한다.
특수 문자는 하나 이상 포함되어야 한다. 사용할 수 있는 특수 문자는 !@#$%^&*()-+이다.

1. 숫자, 소문자, 대문자,특수문자 카운트 플래그
2. 특수문자는 배열로 지정
3. 해당 카운트 플래그 변수가 0인 경우 비밀번호에 안 쓰인 경우므로 카운트
*/

#include<stdio.h>
#include<string.h>

int N;
int upperFlag = 0, lowerFlag = 0, digitFlag = 0, specialFlag = 0;
char str[101] = { 0, };
char special[12] = { '!','@','#','$','%','^','&','*','(',')','-','+' };

int password[4] = { 0, };

int main()
{
	int len = 0;
	int ret = 0;


	scanf("%d", &N);
	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		//숫자인지 검사
		if (str[i] >= '0' && str[i] <= '9')
		{
			digitFlag=0;
			password[digitFlag]++;
		}//알파벳 대소문자 검사
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			lowerFlag = 1;
			password[lowerFlag]++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			upperFlag=2;
			password[upperFlag]++;
		}
		else
		{//특수문자
			for (int j = 0; j < sizeof(special) / sizeof(char); j++)
			{
				if (special[j] == str[i])
				{
					specialFlag = 3;
					password[specialFlag]++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
	//	printf("password[%d] = %d\n", i, password[i]);
		if (password[i] == 0)
		{
			ret++;
		}
	}
	//길이가 6이상이고 부족한 문자를 채워야 하는 경우
	if (len + ret >= 6)
	{
		printf("%d\n", ret);
	}
	else
	{
		printf("%d\n", 6-len);
	}
	
	return 0;
}