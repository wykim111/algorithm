/*
	1 . �ٱ��Ͽ� �Է�
	(�� ����� �� ���� i j k�� �̷���� ������, i�� �ٱ��Ϻ��� j�� �ٱ��ϱ����� k�� ��ȣ�� ������ �ִ� ���� �ִ´ٴ� ���̴�. 
	���� ���, 2 5 6�� 2�� �ٱ��Ϻ��� 5�� �ٱ��ϱ����� 6�� ���� �ִ´ٴ� ���̴�. (1 �� i �� j �� N, 1 �� k �� N)
	2. i���� j�� ���� ���� ���ڷ� ä���.
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