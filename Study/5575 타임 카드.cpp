/*
타임카드에서 사용하는 시간단위는 24 시간제를 사용한다.
모든 직원은 23시 이전에 퇴근
직원의 퇴근 시간은 항상 출근 시간보다 늦다.
*/
#include<stdio.h>

int main()
{
	int sh, sm, ss, eh, em, es;

	for (int i = 0; i < 3; i++)
	{
		int ret1, ret2,ret3;
		int retH, retM, retS;

		scanf("%d %d %d %d %d %d", &sh, &sm, &ss, &eh, &em, &es);

		ret1 = (sh * 3600) + (sm * 60) + ss;
		ret2 = (eh * 3600) + (em * 60) + es;

		ret3 = ret2 - ret1;
		
		//시간 : ret3 / 3600 
		//분 : (ret3 % 3600) / 60
		//초 : (ret3 % 3600) % 60

		printf("%d %d %d\n", ret3 / 3600, (ret3 % 3600) / 60, (ret3 % 3600) % 60);

	
	}
	return 0;
}