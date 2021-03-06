/*
영어 문장속 숨어있는 니모(Nemo)를 찾아보자.니모를 찾는데 있어서 대소문자는 중요하지 않다.

	strstr 구현
*/
#include <stdio.h>
#include <string.h>

char str[82];

void conv()
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
}
/*
	strstr과 같이 구현
*/
int find(const char* src,const char* dest)
{
	int len = strlen(dest);
	int i = 0;

	for (;*src != '\0';src++)
	{
		if (*src == *dest)
		{
			for (i = 1; i < len; i++)
			{
				if (*(src + i) != *(dest + i))
				{
					break;
				}
			}//for i

			//길이가 찾고자 하는 단어랑 같은 경우
			if (i == len)
			{
				return 1;
			}


		}
	}

	return 0;
}

int main()
{
	while (1)
	{
		int len = 0;
		
		memset(str, 0, sizeof(str));
		fgets(str, sizeof(str), stdin);

		

		len = strlen(str);
		str[len - 1] = '\0';
		len = strlen(str);

		if (strcmp(str, "EOI") == 0)
		{
			break;
		}

		conv();

		if (find(str, "nemo") == 1)
		{
			printf("Found\n");
		}
		else
		{
			printf("Missing\n");
		}
		


	}

	return 0;
}
