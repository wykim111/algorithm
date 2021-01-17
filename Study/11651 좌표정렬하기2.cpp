/*
	qsort  �̿��Ͽ�  y��ǥ�� �����ϴ� ������, 
	y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include<stdio.h>
#include<stdlib.h>

int N;

typedef struct _pos
{
	int x;
	int y;
}Pos;

Pos P[100000];

int cmp(const void* p1, const void* p2)
{
	Pos n1 = *(Pos*)p1;
	Pos n2 = *(Pos*)p2;

	if (n1.y > n2.y)
		return 1;
	else if (n1.y == n2.y)
	{
		if (n1.x > n2.x)
			return 1;
	}

	return 0;
}

void Print()
{
	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", P[i].x, P[i].y);
	}
}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &(P[i].x), &(P[i].y));
	}

	qsort(P, N, sizeof(Pos), cmp);

	Print();

	return 0;
}