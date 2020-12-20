/*
	1시간 = 3600 s
	1분 = 60s
	1초 = 1s
*/

#include<stdio.h>

char curTime[10];
char missionTime[10];

long long convSecond(char* time)
{
	long long sumSecond = 0;
	int h=0, m=0, s=0;

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
	long long second1 = 0, second2 = 0,remainTime=0;
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

	printf("%02d:%02d:%02d\n", h,m,s);

	return 0;
}
