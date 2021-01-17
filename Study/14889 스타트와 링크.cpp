/*
	1. s[i][j]와 s[j][i]는 다를수 있음
	2. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 합
	3. i번 사람과 j번 사람이 같은 팀에 속했을 때 팀에 더해지는 능력치는 
	   s[i][j]와 s[j][i]
	4.조합이용까지는 내가 생각했지만 이후 계산하는 방법은 나만의 방법으로 다시 한번 생각해보자!!!!!!!!!!
*/
#include<stdio.h>
#include<math.h>
int N;
int s[21][21];
int Team[21];
int visit[21];
int ret[21];
int cnt = 0;
int minRet = 1e9;

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;

	return n1;
}

void comb(int idx,int curIdx)
{
	
	//팀이 정해진 경우
	if (idx == N/2)
	{
		int start = 0;
		int link = 0;
		int temp;
		/*
		//조합
		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("\n");
		*/
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (visit[i] == 1 && visit[j] == 1)
					start += s[i][j];
				if (visit[i] == 0 && visit[j] == 0)
					link += s[i][j];
			}
		}
		temp = abs(start - link);

		minRet = min(minRet, temp);


		return;
	}


	for (int i = curIdx; i < N; i++)
	{
		if (visit[i] == 1)
			continue;
		//ret[idx] = Team[i];
		visit[i] = 1;
		comb(idx+1,i+1);
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
			scanf("%d", &s[i][j]);
		}
	}
	
	//스타트팀과 링크팀으로 나눔
	//순열의 원리
	comb(0,1);
	//printf("cnt = %d\n", cnt);

	printf("%d\n", minRet);
	return 0;
}
