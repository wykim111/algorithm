/*
번호판에 사용할 수 있는 숫자는 0, 1, 2, ..., 8, 9이다.
사용할 수 있는 문자는 a, b, c, d, ..., y, z이다.
차량 번호판의 형식은 최대 4글자이고, c와 d로 이루어진 문자열로 나타낼 수 있다.
c는 문자가 위치하는 자리, d는 숫자가 위치하는 자리이다.
같은 문자 또는 숫자가 연속해서 2번 나타나면 안 된다. 
 ex) dd = 그 다음 자리는 같은 숫자를 사용할 수 없음 경우의 수:10*9
     cc = 26 * 25
*/

#include<stdio.h>
#include<string.h>

char carName[5];

int main()
{
	int len = 0;
	int ret = 0;

	scanf("%s", carName);

	len = strlen(carName);

	for (int i = 0; i < len; i++)
	{
		//첫번째가 숫자인 경우와 문자인 경우
		if (i == 0)
		{
			if (carName[i] == 'c')
			{
				ret = 26;
			}
			if (carName[i] == 'd')
			{
				ret = 10;
			}
		}
		else //0번쨰 자리가 아닌 경우
		{
			//이전 데이터와 같은 경우
			if (carName[i] == carName[i - 1])
			{
				//이전데이터가 문자인 경우
				if (carName[i - 1] == 'c')
				{
					ret *= 25;
				}
				else if (carName[i - 1] == 'd')//이전 데이터가 숫자인 경우
				{
					ret *= 9;
				}
			}
			//이전 데이터와 다른 경우
			else
			{
				//이전데이터가 문자인 경우 현재 데이터는 d
				if (carName[i - 1] == 'c')
				{
					ret *= 10;
				}
				else if (carName[i - 1] == 'd')//이전 데이터가 숫자인 경우 현재 데이터는 c
				{
					ret *= 26;
				}
			}
		}
	}

	printf("%d\n", ret);

	return 0;
}