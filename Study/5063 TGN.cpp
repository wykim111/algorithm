/* 
r은 광고를 하지 않았을 때 수익, e는 광고를 했을 때의 수익, c는 광고 비용이다. (-106 ≤ r,e ≤ 106, 0 ≤ c ≤ 106)

 1) r > e - c : 광고를 하지 않았을떄 수익이 큰 경우 "do not advertise" 출력
 2) r = e - c : 수익이 차이가 없다면 "does not matter"를 출력
 3) r < e - c " 광고를 해야 하면 "advertise" 출력

*/

#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	while (N--)
	{
		int r, e, c;

		scanf("%d %d %d", &r, &e, &c);

		if (r < e - c)
		{
			printf("advertise\n");

		}
		else if (r > e - c)
		{
			printf("do not advertise\n");
		}
		else
		{
			printf("does not matter\n");
		}
	}

	return 0;
}