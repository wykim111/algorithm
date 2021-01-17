#include<stdio.h>
#include<string.h>
int main()
{
	int N;
	char str[100];
	char computer[] = "P=NP";
	scanf("%d", &N);

	while (N--)
	{
		memset(str, 0, sizeof(str));

		scanf("%s", str);
		if (!strcmp(str, computer))
		{
			printf("skipped\n");
			continue;
		}
		else
		{
			char* p;
			int num1=0;
			int num2=0;

			p = str;
			//'+' 만나기 전
			for (; *p != '+'; p++)
			{
				num1 = num1 * 10 + ((*p) - '0');
			}
			//p는 현재 '+'를 가르키고 있으므로 넘어간다.
			p++;
			//'+'이후 문자열의 끝을 가르키면 종료
			for (; *p != '\0'; p++)
			{
				num2 = num2 * 10 + ((*p) - '0');
			}

			printf("%d\n", num1 + num2);
		}

	}
	return 0;
}
