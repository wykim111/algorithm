/*
	중복조합 이용

	1. 중복조합으로 N개의 수 구함
	2. N개 뽑은 숫자를 모두 더함

*/


#include<stdio.h>

int N, sum = 0;
int arr[1001];
int ret[1001];

void go(int dep, int curIdx)
{
	if (dep == 2)
	{		
		for (int i = 0; i < dep; i++)
		{
			sum += ret[i];
		}

		return;
	}

	for (int i = curIdx; i <= N; i++)
	{
		ret[dep] = arr[i];
		go(dep + 1, i);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i <= N; i++)
	{
		arr[i] = i;
	}

	go(0, 0);

	printf("%d\n", sum);

	return 0;
}



/*
	

*/
