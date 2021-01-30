/*
	투포인터 알고리즘을 이용하여 접근(슬라이딩 윈도우와 유사)
*/

#include<stdio.h>

#define SIZE 10001

long long int arr[SIZE] = { 0, };

int main()
{
	int N, M;

	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	int start = 0, end = 0;
	int cnt = 0;
	long long int sum = arr[0];
	
	while ( end<N)
	{
		
		
		//sum이 M(찾고자 하는 값)보다 작으면
		if (sum < M)
		{
			end++;//end포인터를 증가
			sum += arr[end];
		}
		//sum이 더 크면 start인덱스를 뺴준 뒤 start포인터 증가
		else if (sum > M)
		{
			sum -= arr[start];
			start++;
		}
		else//같은 수인 경우
		{
			cnt++;//갯수 증가
			end++;//end포인터 증가
			sum += arr[end];//end인덱스의 데이터를 더함 
			
		}
		

	}
	printf("%d\n",cnt);
	return 0;
}
