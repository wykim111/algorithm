/*���� �˻�(���ʹ�)*/
#include<stdio.h>
#include<stdlib.h>
/*
	1. �˻��� ���� �߰����� ���ϰ� �迭�� ���� ������ ���
	2. �˻��� ���� ���� ��Ҹ� �߰��� ���

	N ������ ��ŭ �ξ �ε����� N-1���� Ž���Ͽ� Ű�� �������� ������ N��°�� �ִ� ���� -1 ����
	Ű�� ã���� �ش� �ε��� ����
*/
int search(int* a, int n, int key)
{
	int i = 0;
	
	a[n] = key;

	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
			break;
	}
	return i == n ? -1 : i;
}


int main()
{
	int i, nx, ky, idx;
	int* x;
	
	printf("�����˻�(���ʹ�)\n");
	printf("��� ���� : ");
	scanf("%d", &nx);
	
	x = calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�˻��� : ");
	scanf("%d", &ky);
	
	idx = search(x, nx, ky);

	if (idx == -1)
		printf("�˻��� ����\n");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�\n", ky, idx);
	
	free(x);

	return 0;
}