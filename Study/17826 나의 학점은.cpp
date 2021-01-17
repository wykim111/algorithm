/*
A+: 1~5등
A0: 6~15등
B+: 16~30등
B0: 31~35등
C+: 36~45등
C0: 46~48등
F: 49~50등

오름차순으로 정렬한뒤 lowerbound로 자신의 위치를 파악하고 50에서 알아낸 위치를 뺸다.
50에서 뺸 랭크가 진짜 랭크이므로 해당 랭크가 들어갈 학점을 찾는다.

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

	//오름차순 정렬
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