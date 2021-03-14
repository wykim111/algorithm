/*
	segment Tree 구성

	- init
	- query

*/

#include<iostream>
#include<algorithm>
#include <cstdio>
#include<vector>

using namespace std;

int arr[100001];
vector<pair<int, int>> segment(100001 * 4);

int N, M;





long long initMin(int start, int end, int node)
{
	if (start == end)
	{
		segment[node].first = arr[start];

		return segment[node].first;
	}
	int mid = (start + end) >> 1;

	segment[node].first = min(initMin(start, mid, node * 2),initMin(mid + 1, end, (node * 2) + 1));

	return segment[node].first;
}


long long initMax(int start, int end, int node)
{
	if (start == end)
	{
		segment[node].second = arr[start];

		return segment[node].second;
	}
	int mid = (start + end) >> 1;

	segment[node].second = max(initMax(start, mid, node * 2), initMax(mid + 1, end, (node * 2) + 1));

	return segment[node].second;
}

long long queryMin(int start, int end, int node, int left, int right)
{
	//범위 내에 만족하지 않은 경우
	if (end < left || right < start)
	{
		return 1e9;
	}

	if (left <= start && end <= right)
	{
		return segment[node].first;
	}



	int mid = (start + end) >> 1;

	return min(queryMin(start, mid, node * 2, left, right), queryMin(mid + 1, end, (node * 2) + 1, left, right));
}

long long queryMax(int start, int end, int node, int left, int right)
{
	//범위 내에 만족하지 않은 경우
	if (end < left || right < start)
	{
		return -1;
	}

	if (left <= start && end <= right)
	{
		return segment[node].second;
	}



	int mid = (start + end) >> 1;

	return max(queryMax(start, mid, node * 2, left, right), queryMax(mid + 1, end, (node * 2) + 1, left, right));
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	initMin(1, N, 1);
	initMax(1, N, 1);

	for (int i = 0; i < M; i++)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		
		printf("%lld %lld\n", queryMin(1, N, 1, a, b), queryMax(1, N, 1, a, b));
	}


	return 0;
}
