/*
	조합 활용
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
int sourness[11]; //신맛
int bitter[11];//쓴맛
long long int ret = 1e9;

//idx와 r은 뽑을 갯수,s와 b는 선택하거나 선택 안 한 경우 연산되는 수
void go(int idx, int r, long long int s, long long int b)
{
	if (idx == r)
	{
		int temp = abs(s - b);

		if (temp < ret)
		{
			ret = temp;
		}
		return;
	}
	/*
	//현재  재료를 선택하는 경우
	go(idx + 1, s*sourness[idx], b + bitter[idx]);
	//현재 재료를 선택 하지 않은 경우
	go(idx + 1, s, b);
	*/
	for (int i = idx + 1; i < N; i++)
	{
		go(i, r, s * sourness[i], b + bitter[i]);
	}
	return;
}
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &sourness[i], &bitter[i]);
	}
	for (int i = 0; i < N; i++)//r개 선택하는 경우
	{
		for (int j = 0; j < N; j++)//선택한 후 조합 진행
		{
			go(j, i, sourness[j], bitter[j]);
		}
	}

	printf("%lld\n", ret);
	return 0;
}
