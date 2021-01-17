/*
	이진탐색으로 B 이상인 값을 찾는다 그리고 이상인 값이 있는 인덱스 보다 이전 인덱스에 값도 찾아 키값과의 차이를 비교
	키 값과의 차이가 가장 작은 값을 기준으로 이동시킨다.
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int A, B;
int arr[5];
int N;


int main()
{
	int gap =1000;
	int ret = 0;

	scanf("%d %d", &A, &B);
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	
	for (int i = 0; i < N; i++)
	{
		if (abs(B - arr[i]) < gap)
		{
			gap = abs(B - arr[i]);
		}
	}

	if (abs(B - A) > gap + 1)
		ret = gap + 1;
	else
		ret = abs(B - A);

	printf("%d\n", ret);

	return 0;
}