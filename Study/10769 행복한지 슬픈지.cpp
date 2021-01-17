/*
•어떤 이모티콘도 포함되어 있지 않으면, none 을 출력한다.
•행복한 이모티콘과 슬픈 이모티콘의 수가 동일하게 포함되어 있으면, unsure 를 출력한다.
•행복한 이모티콘이 슬픈 이모티콘보다 많이 포함되어 있으면, happy 를 출력한다.
•슬픈 이모티콘이 행복한 이모티콘보다 많이 포함되어 있으면, sad 를 출력한다

행복한 얼굴을 나타내는 :-) 와 슬픈 얼굴을 나타내는 :-( 가 있다.
*/

#include<stdio.h>
#include<string.h>

char happy[4] = { ':','-',')' };
char sad[4] = { ':','-','(' };

char str[257];

int main()
{
	int len = 0;
	int happyCnt = 0, sadCnt = 0;
	int happyRet = 0 , sadRet = 0;
	fgets(str, sizeof(str), stdin);

	len = strlen(str);
	str[len - 1] = '\0';

	len = strlen(str);

	//행복 카운트
	for (int i = 0; i < len; i++)
	{
		//행복한 경우
		if (str[i] == happy[0])
		{
			happyCnt++;
			for (int j = 1; j < 3; j++)
			{
				if (str[i + j] == happy[j])
				{
					happyCnt++;
				}
			}
			//행복한 경우가 모두 일치하는 경우
			if (happyCnt == 3)
			{
				happyRet++;
			}
			//행복한 이모티콘인지 확인하는 변수 초기화
			happyCnt = 0;
		}// happy
		if (str[i] == sad[0]) //sad
		{
			sadCnt++;
			for (int j = 1; j < 3; j++)
			{
				if (str[i + j] == sad[j])
				{
					sadCnt++;
				}
			}
			//행복한 경우가 모두 일치하는 경우
			if (sadCnt == 3)
			{
				sadRet++;
			}
			//행복한 이모티콘인지 확인하는 변수 초기화
			sadCnt = 0;
		}
	}
	//printf("행복 슬픔 체크 =%d %d\n", happyRet,sadRet);

	if ((happyRet == 0) && (sadRet == 0))
	{
		printf("none\n");

		return 0;
	}
	if (happyRet < sadRet)
	{
		printf("sad\n");
	}
	else if (happyRet > sadRet)
	{
		printf("happy\n");
	}
	else
	{
		printf("unsure\n");
	}

	return 0;
}