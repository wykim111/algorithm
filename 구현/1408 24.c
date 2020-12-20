/*
	1시간 = 3600 s
	1분 = 60s
	1초 = 1s
	tc input)
	23:59
	00:00
	이 경우 carry(올림수)에 대한 처리 필요.
	23:59보다 00:00은 숫자상 작으므로  음수가 나오면,
	시간은 +24, 분 + 60, 초+60으로 초 부터 연산
	
	초가 음수이면
	초를 연산하면서 분을 -1 감소시키고,
	
	분이 음수이면
	분을 연산하면서 시간을 -1 감소
*/

#include<stdio.h>

char curTime[10];
char missionTime[10];

long long convSecond(char* time)
{
	long long sumSecond = 0;
	int h = 0, m = 0, s = 0;

	//시간 환산
	for (int i = 0; i < 2; i++)
	{
		h = (h * 10) + (time[i] - '0');
	}
	//분 환산
	for (int i = 3; i < 5; i++)
	{
		m = (m * 10) + (time[i] - '0');
	}

	//초 환산
	for (int i = 6; i < 8; i++)
	{
		s = (s * 10) + (time[i] - '0');
	}


	sumSecond = (h * 3600) + (m * 60) + s;

	return sumSecond;
}
int main()
{
	long long second1 = 0, second2 = 0, remainTime = 0;
	int h, m, s;
	scanf("%s", curTime);
	scanf("%s", missionTime);

	second1 = convSecond(curTime);
	second2 = convSecond(missionTime);

	remainTime = second2 - second1;

	h = remainTime / 3600;
	m = (remainTime % 3600) / 60;
	s = ((remainTime % 3600) % 60);

	if (s < 0)
	{
		s += 60;

		m--;
	}

	if (m < 0)
	{
		m += 60;
		h--;
	}

	if (h < 0)
	{
		h += 24;
	}

	printf("%02d:%02d:%02d\n", h, m, s);

	return 0;
}
