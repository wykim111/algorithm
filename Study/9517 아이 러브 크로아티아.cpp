/*
�� ����� ������ �������� 3�� 30�ʰ� ������ ������ ��ź�� ��� �ִ�. ��ź�� ����ִ� ������� ������ �ϸ鼭 ������ ���۵ȴ�. � ������ ������ ������ ���� ��쳪, ������ ��ŵ�� ��쿡�� �� ��� ���� ������ �ް� �ȴ�. 
������ ������ ���� ��쿡�� ��ź�� �ٷ� ���ʿ� �ִ� �÷��̾�� �Ѱ��ְ�, �Ѱܹ��� �÷��̾�� ���� ������ ������ �ȴ�.
*/

#include<stdio.h>

//3�� 30��
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
		//������ 8��° �����ڰ� ��ġ�� �� ������ �ٽ� 1��° �����ڷ� �Ѿ�� ��
		if (personNum % 9 == 0)
		{
			personNum = 1;

		}
		idx++;
	}

	

	return 0;
}
