#include<stdio.h>

#define SIZE 3

int arr[3] = { 1,2,3 };

int set[10];
int comb[10];

int visit[10];
int perm[10];

void subset(int dep,int set_size, int curIdx)
{
	if (dep == SIZE)
	{
		for (int i = 0; i < set_size; i++)
		{
			printf("%d ", set[i]);
		}
		printf("\n");

		return;
	}
	set[set_size] = arr[curIdx];
	
	subset(dep + 1,set_size+1, curIdx + 1);//pick

	subset(dep + 1, set_size , curIdx + 1);// not pick
}

void permutation(int dep)
{
	if (dep == 2)
	{
		for (int i = 0; i < dep; i++)
		{
			printf("%d ", perm[i]);
		}
		printf("\n");

		return;
	}

	

	for (int i = 0; i < SIZE; i++)
	{
		if (visit[arr[i]] == 1)
		{
			continue;
		}
		visit[arr[i]] = 1;
		perm[dep] = arr[i];
		permutation(dep + 1);
		visit[arr[i]] = 0;
	}
}

void combination(int dep,int set_size, int curIdx,int pick)
{
	
	if (pick == 2)
	{
		for (int i = 0; i < set_size; i++)
		{
			printf("%d ", comb[i]);
		}
		printf("\n");
		
		return;
	}
	/*
		중요 : 모든 조합을 탐색해야 하는데 dep == SIZE가  함수 맨 위에 존재하면 배열의 마지막 데이터를 출력할 수 없음
	*/
	if (dep == SIZE)
		return;

	
	
	comb[set_size] = arr[curIdx];

	combination(dep + 1, set_size + 1, curIdx + 1,pick+1);//pick

	combination(dep + 1, set_size, curIdx + 1,pick);// not pick
}


int main()
{
	printf("부분집합\n");
	subset(0, 0, 0);

	printf("조합\n");
	combination(0, 0, 0, 0);

	printf("순열\n");
	permutation(0);

	return 0;
}
