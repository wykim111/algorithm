/*
	순열로 다 저장하되 중복된 숫자로 된 쌍은 제외시켜준다. (prev로 이전 데이터 저장)
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int N, M;
int visit[10];
int arr[10];
int ret[10];


void go(int dep)
{
	if (dep == M)
	{
		for (int i = 0; i < M; i++)
		{
			printf("%d ", ret[i]);
		}
		
		printf("\n");
		return;
	}


	int prev = -1;

	for (int i = 0; i < N; i++)
	{
		//이미 해당 인덱스를 방문했거나 해당 데이터를 이미 경우
		if (visit[i] == 1 || prev == arr[i])
		{
		//	printf("prev  = %d, visit[%d] = %d\n ", prev, i, visit[i]);
			continue;
		}
		prev = arr[i];
		visit[i] = 1;
		ret[dep] = arr[i];
		
		go(dep + 1);
		visit[i] = 0;
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	//정렬(내림차순)
	sort(arr + 0, arr + N);

	go(0);

	return 0;
}