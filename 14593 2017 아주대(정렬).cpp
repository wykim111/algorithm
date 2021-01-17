#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int N;

typedef struct person
{
	int id; //참가자의 순서 저장
	int S;//점수의 총합
	int C;//제출횟수
	int L;//업로드 시간
}Person;

Person student[10000];
/*
	1. 해결한 문제 점수의 총합이 높은자가 높은 순위
	2. 총합이 같은 경우, 제출 횟수가 적은 참가자가 더 높은 순위
	3. 총합 제출횟수가 같은경우 업로드 시간이 빠른 사람 기준
*/
bool cmp(const Person& p1, const Person& p2)
{
	if (p1.S != p2.S)
		return p1.S > p2.S;//점수 내림차순
	else
	{
		if (p1.C != p2.C)
			return p1.C < p2.C;//오름차순
		else
		{
			if (p1.L != p2.L)
			{
				return p1.L < p2.L;//빠른 사람이 등수가 높아야 하므로 오름차순
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