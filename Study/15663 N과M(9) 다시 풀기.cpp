/*
	������ �� �����ϵ� �ߺ��� ���ڷ� �� ���� ���ܽ����ش�. (prev�� ���� ������ ����)
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
		//�̹� �ش� �ε����� �湮�߰ų� �ش� �����͸� �̹� ���
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
	//����(��������)
	sort(arr + 0, arr + N);

	go(0);

	return 0;
}