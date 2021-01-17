#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int N, M;
int card1[500000];
int card2[500000];

int binarySearch(int key,int start,int end)
{
	int cnt = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		/*
			key와 같은 수를 찾는 경우 카운트 시작
		*/
		if (card1[mid] == key)
		{
			//start부터 end까지 같은 수 카운트
			for (int i = start; i <= end; i++)
			{
				if (card1[i] == key)
				{
					cnt++;
				}
			}


			return cnt;
		}
		else if (card1[mid] > key)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	
	return 0;
}

bool cmp(int n1, int n2)
{
	return n1 < n2;//오름차순
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card1[i]);
	}

	sort(card1, card1 + N, cmp);

	scanf("%d", &M);
	
	for (int j = 0; j < M; j++)
	{
		scanf("%d", &card2[j]);
	}

	for (int i = 0; i < M; i++)
	{
		printf("%d ", binarySearch(card2[i], 0, N - 1));
	}
	printf("\n");
	/*
	for (int i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	*/


	return 0;
}