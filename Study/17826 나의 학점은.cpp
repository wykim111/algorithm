/*
A+: 1~5��
A0: 6~15��
B+: 16~30��
B0: 31~35��
C+: 36~45��
C0: 46~48��
F: 49~50��

������������ �����ѵ� lowerbound�� �ڽ��� ��ġ�� �ľ��ϰ� 50���� �˾Ƴ� ��ġ�� �A��.
50���� �A ��ũ�� ��¥ ��ũ�̹Ƿ� �ش� ��ũ�� �� ������ ã�´�.

*/
#include<stdio.h>
#include<stdlib.h>

int stu[50];

int cmp(const void* p1, const void* p2)
{
	int n1 = *(int*)p1;
	int n2 = *(int*)p2;


	return n1 - n2;
}

int lowerBound(int key)
{
	int left = 0;
	int right = 49;
	
	while (right > left)
	{
		int mid = (left + right) >> 1;

		if (stu[mid] >= key)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}

	return right;
}

void calGrade(int nRank)
{
	if (nRank >= 1 && nRank <= 5)
	{
		printf("A+\n");
	}
	else if (nRank >= 6 && nRank <= 15)
	{
		printf("A0\n");
	}
	else if (nRank >= 16 && nRank <= 30)
	{
		printf("B+\n");
	}
	else if (nRank >= 31 && nRank <= 35)
	{
		printf("B0\n");
	}
	else if (nRank >= 36 && nRank <= 45)
	{
		printf("C+\n");
	}
	else if (nRank >= 46 && nRank <= 48)
	{
		printf("C0\n");
	}
	else
	{
		printf("F\n");
	}
}

int main()
{
	int hongik;
	int Rank = 0;

	for (int i = 0; i < 50; i++)
	{
		scanf("%d", &stu[i]);
	}

	scanf("%d", &hongik);

	//�������� ����
	qsort(stu, 50, sizeof(int), cmp);
	/*
	for (int i = 0; i < 50; i++)
	{
		printf("%d\n", stu[i]);
	}
	*/
	Rank = 50 - lowerBound(hongik);

	//printf("Rank = %d\n", Rank);
	
	calGrade(Rank);


	return 0;
}