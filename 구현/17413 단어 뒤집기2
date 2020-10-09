/*
알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
문자열의 시작과 끝은 공백이 아니다.
'<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.

태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, 
'<'와 '>' 사이에는 알파벳 소문자와 공백만 있다.

-> strtok 함수를 이용하면 < 와 > 사이에 공백 문자들도 분리 되므로 사용 x

*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char str[100002];
char retStr[100002];
char tempStr[100002];
//역순으로 저장
void reverseStr(char* pStr,int len)
{
	for (int i = 0; i < len/2; i++)
	{
		char temp = pStr[i];
		pStr[i] = pStr[len - 1 - i];
		pStr[len - 1 - i] = temp;
	}

}

int main()
{
	int strLen = 0;
	char* token = NULL;
	int start = 0, end = 0;
	int i, j;

	fgets(str, sizeof(str)/sizeof(char), stdin);

	strLen = strlen(str);

	str[strLen - 1] = '\0';
//	printf("strLen = %d\n", strLen);
	//'<'와 '>' 사이에 있는 문자열을 그대로 저장
	for (i = 0; i < strLen - 1; i++)
	{
		//char* tempStr = NULL;
		memset(tempStr, 0, sizeof(tempStr));

		if (str[i] == '<')
		{
			start = i;

			// '>' 만날때까지 이동
			//end는 '>'만나는 위치 저장
			for (j = i; ;j++)
			{
				if (str[j] == '>' || str[j] == 0 )
					break;
			}
			end = j+1;
			//tempStr = (char*)malloc(sizeof(char)*(end - start + 1));
			
			int idx = 0;
			for (int k = start; k < end; k++)
			{
				tempStr[idx++] = str[k];
			}
			tempStr[idx] = '\0';
			strcat(retStr, tempStr);

			//'>'의 위치를 현재 탐색하는 i에 저장
			i = end-1;
			
		}
		else if((str[i] >= 'a' && str[i] <= 'z') || str[i] >= '0' && str[i] <= '9')//'<'와 '>'를 사이에 있는 문자열 제외한 일반 문자열, 공백 분리
		{
			int tempLen = 0;

			start = i;
			//'<' 이거나 공백이거나 문자열 끝부분까지 탐색
			for (j = i; ; j++)
			{
				if (str[j] == '<' || str[j] == ' ' || str[j] == 0)
				{
					break;
				}

			}
			end = j-1;
			//tempStr = (char*)malloc(sizeof(char)*(end - start + 1));
			int idx = 0;
			for (int k = start; k <= end; k++)
			{
				tempStr[idx++] = str[k];
			}
			tempStr[idx] = '\0';//idx는 문자열 길이
		//	printf("tempStr=%s\n", tempStr);
			reverseStr(tempStr, idx);//구분자가 있으면 길이에서 1을 뺸다.

			strcat(retStr, tempStr);

			i = end;
			tempLen = strlen(retStr);
			
			//end 포인터 다음 위치에 구분자가 있는 경우
			if (str[end+1] == ' ')
			{
				retStr[tempLen] = ' ';
			}
			
		}

		
		
	}
	retStr[strLen - 1] = '\0';
	printf("%s\n", retStr);

	return 0;
}
