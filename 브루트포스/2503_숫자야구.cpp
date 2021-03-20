/*
	- 모든 경우의 수를 순열로 구함( 123 ~ 987 )
	
	- 입력한 숫자와 strike와 ball을  비교
	  -> 같은 인덱스에 같은 데이터가 있으면 strike
	  -> 다른 인덱스에 같은 데이터가 있으면 ball

	- 모든 순열을 입력한 데이터와 비교를 통해 스트라이크나 볼이
	  입력한 데이터의 스트라이크와 볼이 모두 같으면 카운트
	  

*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int N;
int visit[10];
int permutation[3];
int retCnt = 0;



typedef struct _baseball
{
	char num[4];
	int s;
	int b;
}BaseBall;

BaseBall stBaseBall[100];


int check()
{
	int flag = true;

	//printf("%d %d %d\n", permutation[0], permutation[1], permutation[2]);

	//입력한 데이터
	for (int i = 0; i < N; i++)
	{
		int strike = 0, ball = 0;
		//입력한 데이터의 문자열
		for (int j = 0; j < 3; j++)
		{
		
			//순열 데이터
			for (int k = 0; k < 3; k++)
			{
				if (((stBaseBall[i].num[j])-'0') == permutation[k])
				{
					//같은 인덱스에 같은 데이터가 존재하는 경우
					if (j == k)
					{
						strike++;
					}
					else
					{
						ball++;
					}

				}

			}// for k
		}// for j

		//둘 중 하나라도 스트라이크나 볼이 다른 경우
		if ((stBaseBall[i].s != strike) || (stBaseBall[i].b != ball))
		{
			flag = false;
		}

	}//for i
	return flag;
}


//순열
void perm(int dep)
{
	if (dep == 3)
	{
		/*
		//순열 체크
		for (int i = 0; i <= 2; i++)
		{
			printf("%d ", permutation[i]);
		}
		printf("\n");

		retCnt++;
		*/
		if (check() == 1)
		{
			retCnt++;
		}

		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (visit[i] == 1)
		{
			continue;
		}
		permutation[dep] = i;
		visit[i] = 1;
		perm(dep + 1);
		visit[i] = 0;


	}

}

int main()
{

	//printf("cnt = %d\n", permCnt);
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d", stBaseBall[i].num, &stBaseBall[i].s, &stBaseBall[i].b);
		
	}

	perm(0);
	
	printf("%d\n", retCnt);
	return 0;
}
