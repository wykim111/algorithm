/*
	start번째부터 end번쨰까지 역순으로 바꾼다

	mid = (start + end) /2

	start 부터 mid까지 탐색하여 start와 end번째 데이터 스왑 한 뒤
	start는 1 증가, end는 1 감소 이동


*/

#include<stdio.h>

int N, M;

int arr[101] = { 0, };

void setNum()
{
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
}

void reverse(int s, int e)
{
	int mid = (s + e) / 2;


	for (; s <= mid; s++)
	{
		int temp = arr[s];
		arr[s] = arr[e];
		arr[e] = temp;

		e--;
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	setNum();

	while (M--)
	{
		int start, end;

		scanf("%d %d", &start, &end);

		reverse(start, end);

	}

	for (int i = 1; i <= N; i++)
		printf("%d ", arr[i]);

	printf("\n");

	return 0;
}