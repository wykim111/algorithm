/*
	최대 중복되지 않게 등장하는지 카운트
	- 입력한 단어의 첫글자가 같은 경우 나머지 글자까지 탐색
	- 다르면 다음 인덱스 진행
	- 같으면 나머지 글자까지 같은지 확인 후 카운트, 인덱스를 그 다음으로
	  인덱스로 이동시킨다.

*/
#include<stdio.h>
#include<string.h>

char str[2502];
char findStr[52];

int matchString(char* str,char* find)
{
	if (*str == '\0')
	{
		return 0;
	}

	int len = strlen(find);
	//앞글자가 같은 경우 나머지 글자 비교
	if (*str == *find)
	{
		//printf("str = %c find = %c\n",*str,*find);
		for (int i = 1; i < len; i++)
		{
			if (*(str+i) != *(find+i))
			{
				return 0;
			}
		}
	}
	else
	{
		return 0;
	}
	return 1;//else로 예외처리 안 하니까 if (*str == *find) 만족 못해도 true
}

int main()
{
	int len1 = 0, len2 = 0;
	char* pStr = NULL;
	int cnt = 0;

	fgets(str, sizeof(str), stdin);
	fgets(findStr, sizeof(findStr), stdin);

	len1 = strlen(str);
	str[len1 - 1] = '\0';
	len1 = strlen(str);

	len2 = strlen(findStr);
	findStr[len2 - 1] = '\0';
	len2 = strlen(findStr);
	
	pStr = str;

	for (int i = 0; i < len1; i++)
	{

			if (matchString(pStr+i,findStr))
			{
				cnt++;
			//	printf("i = %d\n", i);
				//찾은 문자열의 길이만큼 이동
				i = i + (len2 - 1);//반복문에 증가되므로
			}
			else
			{
				continue;
			}
		
	}

	printf("%d\n",cnt);

	return 0;
}
