#include<stdio.h>

int C, B;//총 비용, 총 갯수
int arr[21];
int retLen = 0;
int ret = 0;
void knapsack(int cnt,int curIdx, int sum,int Len)
{
	if (sum > C) //설정한 총 비용을 넘어서는 경우
	{
		return;
	}

	if (cnt == B) //설정된 모든 갯수를 탐색 완료하는 경우
	{
		if (sum > ret)
		{   //선택한 총 합 중 가장 큰 경우
			ret = sum;
		 }
		return;
	}

    //해당 상품을 선택하는 경우
	knapsack(cnt + 1, curIdx+1, sum + arr[curIdx],Len+1);
	//해당 상품을 선택하지 않은 경우
    knapsack(cnt + 1, curIdx+1, sum, Len);
}
int main()
{
	scanf("%d %d", &C, &B);

	for (int i = 0; i < B; i++)
	{
		scanf("%d", &arr[i]);
	}
	knapsack(0, 0, 0, 0);

	printf("%d\n", ret);

	return 0;
}
