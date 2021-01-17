/*
	�׸��� �˰���

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
	//�������� ����
	sort(arr + 0, arr + N);

	//�� �������� ���̸� ����
	for (int i = 0; i < N - 1; i++)
	{
		dist[i] = arr[i + 1] - arr[i];
	}
	//�� ������ ���̰��� ������������ ����
	sort(dist + 0, dist + (N - 1));

	for (int i = 0; i < N - K; i++)
	{
		sum += dist[i];
	}

	printf("%d\n", sum);

	return 0;
}