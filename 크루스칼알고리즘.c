#include<stdio.h>
#include<stdlib.h>//����Ʈ

#define TRUE 1
#define FALSE 0

typedef struct _edge
{
	int u;
	int v;
	int cost;

}Edge;


Edge e[1000];
int ret = 0;
/*
   �ش������� ��Ʈ������ �ʱ�ȭ
*/
void Init_set(int* p, int size)
{
	for (int i = 0; i < size; i++)
	{
		p[i] = i;
	}
}

/*
   �ش������� ��Ʈ��尡 ������� Ȯ���ϴ� ���
*/
int Find_set(int* p, int u)
{

	if (p[u] == u)
		return u;

	int temp = Find_set(p, p[u]);

	return temp;
}
/*
   u������ v���� ������ ��Ʈ ������ Ž���ϰ�, �����ϴ� ���

*/
void Union_set(int* p, int u, int v)
{
	int temp_u = Find_set(p, u);
	int temp_v = Find_set(p, v);


	//u ������ ��Ʈ ������ v ������ ��Ʈ������ ���Ͽ�, ���� ��Ʈ������ ���� ���� ��Ʈ�� �����Ͽ� ����
	if (temp_u < temp_v)
	{
		p[temp_v] = temp_u;//v�� ��Ʈ������ u�� ��Ʈ������ ����
	}
	else//temp_u > temp_v
	{
		p[temp_u] = temp_v;//u�� ��Ʈ������ v�� ��Ʈ������ ����
	}
}
/*
   ����Ŭ�� �����ƴ��� ���� Ȯ��
*/
int Is_Cycle(int* p, int u, int v)
{
	int temp_u = Find_set(p, p[u]);
	int temp_v = Find_set(p, p[v]);

	if (temp_u == temp_v)
		return TRUE;

	return FALSE;
}

/*
   ������ ����� �������� �������� ����
*/

int cmp(const void* p1, const void* p2)
{
	Edge* e1 = (Edge*)p1;
	Edge* e2 = (Edge*)p2;


	if (e1->cost > e2->cost)
		return 1;
	else if (e1->cost < e2->cost)
		return -1;
	else
		return 0;
}
/*
   �ش������鸶�� ��Ʈ ������ üũ
*/
void tracking(int* p, int vertax)
{
	printf("�� ������ ��Ʈ��� ����Ʈ\n");

	for (int i = 0; i < vertax; i++)
	{
		printf("%d������ ���յ� ���� %d \n", i, p[i]);
	}
	printf("\n");
}

int main()
{
	int N, M;//������ ������ ��
	int parent[1000];


	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &(e[i].u), &(e[i].v), &(e[i].cost));
	}
	//������ ����� �������� �������� ����
	qsort(e, M, sizeof(Edge), cmp);

	//�������� ���� ���� Ȯ��
	printf("���� Ȯ��\n");
	for (int i = 0; i < M; i++)
	{
		printf("%d %d %d\n", e[i].u, e[i].v, e[i].cost);
	}

	//Union_Find ����
	/*
	   �ش� ����(�ε���)�� ��Ʈ ��� �ʱ�ȭ
	*/
	Init_set(parent, N);

	/*
	   �� �����鰣�� ��Ʈ���� Ž�� �� ���� ����
	*/
	for (int i = 0; i < M; i++)
	{
		if (Is_Cycle(parent, e[i].u, e[i].v) == 1)
			continue;
		else
		{
			ret += e[i].cost;
			Union_set(parent, e[i].u, e[i].v);

		}
	}
	tracking(parent, N);
	printf("%d\n", ret);

	return 0;
}