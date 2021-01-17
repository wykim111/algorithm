#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int N;

typedef struct person
{
	int id; //�������� ���� ����
	int S;//������ ����
	int C;//����Ƚ��
	int L;//���ε� �ð�
}Person;

Person student[10000];
/*
	1. �ذ��� ���� ������ ������ �����ڰ� ���� ����
	2. ������ ���� ���, ���� Ƚ���� ���� �����ڰ� �� ���� ����
	3. ���� ����Ƚ���� ������� ���ε� �ð��� ���� ��� ����
*/
bool cmp(const Person& p1, const Person& p2)
{
	if (p1.S != p2.S)
		return p1.S > p2.S;//���� ��������
	else
	{
		if (p1.C != p2.C)
			return p1.C < p2.C;//��������
		else
		{
			if (p1.L != p2.L)
			{
				return p1.L < p2.L;//���� ����� ����� ���ƾ� �ϹǷ� ��������
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		student[i].id = i + 1;
		scanf("%d %d %d", &(student[i].S), &(student[i].C), &(student[i].L));
	}

	sort(student, student + N,cmp);
	/*
	for (int i = 0; i < N; i++)
	{
		printf("%d ", student[i].id);
	}
	*/
	printf("%d\n", student[0].id);

	return 0;
}