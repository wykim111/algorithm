#include<stdio.h>

int grape[10000];
int N;
int ret = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

/*
	�ش� �����ָ� ���ô� ���/ �� ���ô� ���� ������
	���� 3���� ���� �� ���� cont�� ī��Ʈ�Ѵ�.
*/
void go(int dep, int sum, int cont)
{
	if (dep == N )
	{
		ret = max(ret, sum);
		return;
	}
	//�� ���ô� ���
	go(dep + 1, sum, 0);

	//���� 3���� �ƴ� �̻� ���ô� ���
	if (cont < 2)
	{
		go(dep + 1, sum+ grape[dep], cont+1);
	}
	return;
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &grape[i]);
	}

	go(0,0,0);
	printf("%d\n", ret);

}