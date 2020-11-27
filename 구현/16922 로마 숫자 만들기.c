/*
	로마 숫자에서는 수를 나타내기 위해서 I, V, X, L을 사용
	각 문자는 1, 5, 10, 50을 의미(다른문자 사용 x)

*/

#include<stdio.h>

int N;
int retCnt = 0;
int visit[4];
int romeNum[4] = { 1,5,10,50 };
int check[10000];
int maxData = 0;

//중복조합
void comb(int dep, int idx, int sum)
{
	if (dep == N)
	{
		//printf("%d\n", sum);
		

		if (check[sum] > 0)
		{
			return;
		}
		if (maxData < sum)
			maxData = sum;


		check[sum] = 1;


		return;
	}

	for (int i = idx; i < 4; i++)
	{
		//중복조합은 기존 조합에서 i+1을 넘기는게 아닌 같은 데이터를
		//조합해야 하므로 i를 파라미터로 넘긴다.
		comb(dep+1,i,sum + romeNum[i]);
	}

}

int main()
{
	scanf("%d", &N);

	comb(0,0,0);

	for (int i = 0; i <= maxData; i++)
	{
		if (check[i] > 0)
		{
			retCnt++;
		}
	}

	printf("%d\n", retCnt);

	return 0;
}
