/*
018과 관련 있는 수 중에서 2, 0, 1, 8을 모두 포함하는 수들은 2018과 밀접한 수이다. 
2018과 밀접한 수 중에서 2, 0, 1, 8의 개수가 모두 똑같은 수들은 2018과 묶여있는 수이다. 
2018과 관련 있는 수가 아닌 양의 정수는 2018과 관련 없는 수이다.

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
		if (digit[i] != 0) // 2018 이외의 숫자가 있는 경우
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
			//2,0,1,8이 모두 같은 갯수(모두 > 0)
			if ((digit[0] == digit[1]) && (digit[1] == digit[2]) && (digit[2] == digit[8]))
			{
				ret = 8;

			}
		}
	}

	printf("%d\n", ret);

	return 0;
}