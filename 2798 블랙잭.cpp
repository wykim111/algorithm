/*
	���� M�� ���� �ʴ� ī��
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
	//3�� ����
	if (idx == 3)
	{
		//M ������ �� ã��
		if (sum <= M)
		{
	//		printf("sum = %d\n", sum);
			ret = min(ret, M - sum);
		}
		return;
	}
	//���� �ʰ���
	if (curIdx >= N)
		return;

	//�ش� ī�带 �����ϴ� ���,�ش�ī�带 ���� �� �ϴ� ���
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