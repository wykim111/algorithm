/*
	대회에서 상금을 받으면 전체 금액의 22%를 제세공과금으로 국가에 납부하고, 나머지 금액을 수령하게 된다. 하지만, 상금의 80%를 필요 경비로 인정하게 되면, 
	나머지 20% 중 22%만을 제세공과금으로 납부해도 된다.

*/

#include<stdio.h>

int main()
{
	int N;
	/*
	전체 상금의 22%를 제세공과금으로 납부하는 경우(ret1)
	상금의 80%를 필요 경비로 인정받고, 
	나머지 금액 중 22%만을 제세공과금으로 납부하는 경우(ret2)
	*/
	int ret1 = 0,ret2 = 0;
	
	scanf("%d", &N);

	ret1 = N - ((N * 22) / 100);
	ret2 = N - ((((N * 20) / 100) * 22) / 100);

	printf("%d %d\n", ret1, ret2);

	return 0;
}
