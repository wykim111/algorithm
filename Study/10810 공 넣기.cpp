/*
	1 . 바구니에 입력
	(각 방법은 세 정수 i j k로 이루어져 있으며, i번 바구니부터 j번 바구니까지에 k번 번호가 적혀져 있는 공을 넣는다는 뜻이다. 
	예를 들어, 2 5 6은 2번 바구니부터 5번 바구니까지에 6번 공을 넣는다는 뜻이다. (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ N)
	2. i부터 j번 까지 같은 숫자로 채운다.
*/
#include<stdio.h>

int N, M;
int basket[101] = { 0, };

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int start, end, k;

		scanf("%d %d %d", &start, &end, &k);

		for (int j = start; j <= end; j++)
		{
			basket[j] = k;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		printf("%d ", basket[i]);
	}
	printf("\n");

	return 0;
}