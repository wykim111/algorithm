/*
	N-1에서부터 탐색 시작

	현재 pos하고 pos-1과 비교하여 pos가 pos-1보다 작으면 
	arr[pos-1]을 arr[pos]보다 작을 때까지 1씩 감소시키고 카운트 한다.
*/

#include<stdio.h>

int arr[101];
int N;
int retCnt = 0;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int pos = N - 1; pos > 0; pos-- )
	{
		while (arr[pos] <= arr[pos - 1])
		{
			arr[pos - 1]--;
			retCnt++;
		}
	}
/*
	for (int pos = N - 1; pos >= 0; pos--)
	{
		printf("%d\n", arr[pos]);
	}
*/


	printf("%d\n", retCnt);

	return 0;
}
