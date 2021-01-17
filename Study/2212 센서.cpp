/*
	그리디 알고리즘

*/
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int N,K;
int arr[10000];
int dist[10000];

int main()
{
	int sum = 0;

	scanf("%d", &N);
	scanf("%d", &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	//오름차순 정렬
	sort(arr + 0, arr + N);

	//각 구간마다 차이를 저장
	for (int i = 0; i < N - 1; i++)
	{
		dist[i] = arr[i + 1] - arr[i];
	}
	//각 구간의 차이값을 오름차순으로 저장
	sort(dist + 0, dist + (N - 1));

	for (int i = 0; i < N - K; i++)
	{
		sum += dist[i];
	}

	printf("%d\n", sum);

	return 0;
}
