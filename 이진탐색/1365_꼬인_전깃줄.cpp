/*
	- 오름차순 정렬
	- lower bound로 탐색
	
	1. 배열 입력
	2. LIS 배열에에 lower bound를 통해 입력된 원소가 어디로 들어갈지 인덱스 탐색
	3. LIS 배열의 마지막 원소보다 큰 경우 추가
	4. LIS 배열의 마지막 원소보다 작은 경우 LIS 원소를 lower_bound를 통해 
	   반환된 인덱스에 있는 기존의 데이터를 지우고 저장
	5. LIS 배열의 사이즈에는 잘라내지 않을 전선의 갯수이므로 N에서 뺸 값이 잘라야 하는 최소의 갯수이다.

*/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr[100001] = { 0, };
int LIS[100001] = { 0, };
int N;
int len = 0;

int lower_bound1(int arr[], int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start) 
	{
		mid = (start + end) / 2;
		if (arr[mid] >= target) 
			end = mid;
		else start = mid + 1; 
	}
	return end;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	LIS[0] = arr[0];
	len = 1;
	int idx = 0;

	for (int i = 1; i < N; i++)
	{
		//LIS 배열에 있는 마지막 원소보다 큰 경우 다음 인덱스에 원소 저장
		if (LIS[len - 1] < arr[i])
		{
			LIS[len] = arr[i];
			len++;
			continue;
		}
		idx = lower_bound1(LIS, arr[i], len);
		LIS[idx] = arr[i];
	}
	/*
	for(int i=0;i<len;i++)
	{
		printf("%d ", LIS[i]);
	}
	printf("\n");
	*/
	printf("%d\n", N - len);

	return 0;
}
