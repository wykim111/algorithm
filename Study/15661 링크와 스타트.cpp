/*
  팀은 2팀으로 각 경우의 수를 나눠야 한다. 4명일 시 {(1,3) (2,4)}, {(1,2),(3,4)}, {(1,4),(2,3)} 등

 */
#include<stdio.h>
#include<math.h>
#include<string.h>

int Team[31][31] = { 0, };
int N;
int retMin = 1e9;

int visit[21] = { 0, };
int start[21] = { 0, };
int link[21] = { 0, };


//조합
void comb(int dep, int curIdx, int size)
{
	if (dep == (size+1))
	{
		int startSum = 0;
		int linkSum = 0;
		int linkIdx = 1;

		//선택되지 않은 멤버들 저장
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == 0)
			{
				link[linkIdx++] = i;
			}
		}

		//start팀 합산
		for (int i = 1; i < dep; i++)
		{
			for (int j = 1; j < dep; j++)
			{
				startSum += Team[start[i]][start[j]];
			}
		}

		//Link팀 합산
		for (int i = 1; i < linkIdx; i++)
		{
			for (int j = 1; j < linkIdx; j++)
			{
				linkSum += Team[link[i]][link[j]];
			}
		}
		//printf("\n");
		if (abs(startSum - linkSum) < retMin)
		{
			retMin = abs(startSum - linkSum);
		}

		return;
	}

	for (int i = curIdx; i <= N; i++)
	{
		visit[i] = 1;
		start[dep] = i;
		comb(dep + 1, i+1, size);
		visit[i] = 0;
	}
}
int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &Team[i][j]);
		}
	}

	for (int i = 1; i <= N / 2; i++)
	{
		memset(start, 0, sizeof(start));
		memset(link, 0, sizeof(link));
		comb(1, 1, i);

	}
	printf("%d\n", retMin);

	return 0;
}