/*
배열의 현재 인덱스값 하나만 가지고 끝내는 경우(크기가 1인 부분수열의 합은 바로 자신이다.)
지금까지 구해온 답에 현재 배열의 now 인덱스 값을 더해서 끝내는 경우
지금까지 만든 값을 버리고 현재 인덱스 값을 가지고 다시 시작하는 경우
현재 값과 지금까지 만든 값을 포함해서 계속해서 답을 찾아나가는 경우
*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
double arr[10000];
int N;
double ret = -1;

double max(double n1, double n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

void Sequence()
{
	double temp;

	for (int i = 0; i < N; i++)
	{
		temp = 1;
		for (int j = i; j < N; j++)
		{
			temp *= arr[j];

			if (ret < temp)
			{
				ret = temp;
			}
		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lf", &arr[i]);
	}
	Sequence();

	printf("%.3lf", ret);
}