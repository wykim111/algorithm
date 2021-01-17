/*
	합이 M을 넘지 않는 카드
*/
#include<stdio.h>

int N, M;
int card[101];
int ret = 1e9;

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;
	return n1;
}

void go(int idx, int curIdx, int sum)
{
	//3장 선택
	if (idx == 3)
	{
		//M 이하인 수 찾기
		if (sum <= M)
		{
	//		printf("sum = %d\n", sum);
			ret = min(ret, M - sum);
		}
		return;
	}
	//범위 초과시
	if (curIdx >= N)
		return;

	//해당 카드를 선택하는 경우,해당카드를 선택 안 하는 경우
	go(idx + 1, curIdx + 1, sum + card[curIdx]);
	go(idx, curIdx + 1, sum);

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &card[i]);

	go(0, 0, 0);

	printf("%d\n", M-ret);

	return 0;
}