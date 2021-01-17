#include <stdio.h>

int weight[] = { 2, 3, 4, 5 };
int value[] = { 3, 4, 5, 6 };

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}
/*
int knapSack(int C,int sum, int*w, int* v, int dep)
{

	//무게가 가득차거나  전부 탐색한 경우
	if (C < 0 || dep < 0)
	{
		return 0;
	}
	if (C == 0)
	{
		return sum;
	}
	//물건의 무게가 큰 경우 넣을 수 없음
	if (w[dep - 1] > C)
	{
		knapSack(C, sum, w, v, dep - 1);
	}
	//해당 아이템을 선택하는 경우와 선택하지 않은 경우
	return max(knapSack(C - w[dep - 1], sum + v[dep - 1], w, v, dep - 1), knapSack(C, sum, w, v, dep - 1));
}
*/
int knapSack(int dep, int v,int w)
{
	//무게 초과 되는 경우
	if (w > 5)
	{
		return -weight[dep-1];
	}
	//모두 탐색한 경우
	if (dep == 4)
	{
		return v;
	}
	return max(knapSack(dep + 1, v + value[dep], w + weight[dep]), knapSack(dep + 1, v, w));
}
int main()
{

	printf("도둑이 가지고 갈 수 있는 가치의 최댓값은 %d입니다.\n",knapSack(0,0,0));
	return 0;
}