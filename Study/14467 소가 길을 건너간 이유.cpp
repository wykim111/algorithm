/*
	현재 상태에서 다른 상태로 변하면 소가 길을 건너갔으므로 카운트(0 -> 1, 1 - > 0)
	각 소의 id, 현재 상태 ,이동횟수를 저장하는 구조체 선언
	입력받은 상태와 현재 상태가 상이하면 업데이트 같으면 스킵

	소가 최초 입력 받은 경우 이동횟수는 0이며 상태 천이가 일어나면 카운트하여 그 수가 0보다 크면 카운트한다.
*/

#include<stdio.h>

#define LEFT 0
#define RIGHT 1

int N;


typedef struct _Cow
{
	int cowName; //소 이름
	int state; //소 현재 상태
	int cnt; // 소 이동 횟수
}Cow;

Cow localCow[101];

void init()
{
	for (int i = 0; i < 101; i++)
	{
		localCow[i].cowName = i;
		localCow[i].state = -1;
		localCow[i].cnt = -1;
	}
}
int main()
{
	int curState,cowName;
	int sum = 0;
	
	
	init();
	
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &cowName, &curState);

		
		//현재 소 길 건너 상태와 입력 받은 상태가 다르면 갱신
		// 같으면 스킵
		if (localCow[cowName].state != curState)
		{
			localCow[cowName].state = curState;
			localCow[cowName].cnt++;
		}
		else
		{
			continue;
		}
	}
	//건너간 횟수 총 카운트
	for (int i = 1; i <= N; i++)
	{
		//printf("%d %d %d\n", localCow[i].cowName, localCow[i].state, localCow[i].cnt);

		if (localCow[i].cnt > 0)
		{
			sum += localCow[i].cnt;
		}
	}
	printf("%d\n", sum);

	return 0;
}