/*
	start��°���� end�������� �������� �ٲ۴�

	mid = (start + end) /2

	start ���� mid���� Ž���Ͽ� start�� end��° ������ ���� �� ��
	start�� 1 ����, end�� 1 ���� �̵�


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