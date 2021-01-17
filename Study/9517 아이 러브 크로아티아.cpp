/*
한 사람은 게임이 시작한지 3분 30초가 지나면 터지는 폭탄을 들고 있다. 폭탄을 들고있는 사람에게 질문을 하면서 게임은 시작된다. 어떤 문제의 정답을 맞추지 못한 경우나, 문제를 스킵한 경우에는 그 즉시 다음 문제를 받게 된다. 
문제의 정답을 맞춘 경우에는 폭탄을 바로 왼쪽에 있는 플레이어에게 넘겨주고, 넘겨받은 플레이어에게 다음 질문이 나가게 된다.
*/

#include<stdio.h>

//3분 30초
#define TIME_OVER 210

int K, N;

typedef struct _Person
{
	int time;
	char answer;

}Person;

Person P[9];

int main()
{
	int curTime = 0;
	int personNum = 0;
	int idx = 1;

	scanf("%d", &K);
	scanf("%d", &N);

	personNum = K;

	while (N--)
	{
		

		scanf("%d %c", &P[idx].time, &P[idx].answer);
		

		while (getchar() != '\n');
	
		curTime += P[idx].time;

		if (curTime >= TIME_OVER)
		{
			printf("%d\n", personNum);
			break;
		}


		if (P[idx].answer == 'T')
		{
			personNum++;
		}
		else if (P[idx].answer == 'F')
		{

		}
		else if (P[idx].answer == 'P')
		{

		}
		//마지막 8번째 참가자가 마치면 그 다음은 다시 1번째 참가자로 넘어가야 함
		if (personNum % 9 == 0)
		{
			personNum = 1;

		}
		idx++;
	}

	

	return 0;
}
