/*
	투포인터 활용
	left, right

	1. left가 가르키는 원소와 right가 가르키는 원소가 같으면 right를 한칸씩 이동
	2.	left와 right가 가르키는 원소가 서로 다르면 left가 가르키는 원소 삽입
	3. right가 size를 가르키면 탐색 끝

*/

#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{

	while (1)
	{

		int N;
		
		scanf("%d", &N);

		if (N == 0)
		{
			break;
		}

		int idx = 0;
		int arr[26],ret[26];
		int left = 0,right=0;

		memset(arr, 0, sizeof(arr));
		memset(ret, 0, sizeof(ret));


		for (int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
		}

		left = 0;
		right = left+1;
		//right가 size까지 갈때까지 탐색
		while (right <= N)
		{
			if (arr[left] == arr[right])
			{
				right++;
				
			}
			else
			{
				ret[idx++] = arr[left];
				left = right;
			}


		}

		for (int i = 0; i < idx; i++)
		{
			printf("%d ", ret[i]);
		}
		printf("$");
		printf("\n");


	}


	return 0;
}
