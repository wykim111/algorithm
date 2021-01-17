/*
	1. 매 회씩 진행할 때 마다 각 비율만큼 뺴준다.
	2. 각 주스중 하나라도 0이 되면 종료하고 각 주스들 남아있는 양 출력
*/

#include<stdio.h>

int main()
{
	int orange, apple, pineapple;
	int i, j, k;

	scanf("%d %d %d", &orange, &apple, &pineapple);
	scanf("%d %d %d", &i, &j, &k);

	while (orange != 0 && apple != 0 && pineapple != 0)
	{
		orange -= i;
		apple -= j;
		pineapple -= k;

	}

	printf("%d %d %d\n", orange, apple, pineapple);

	
	return 0;
}