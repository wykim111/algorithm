/*
LowerBound를 구하는 알고리즘은 이분탐색과 거의 유사한 구조로 다음과 같이 작동한다.
•start가 end와 같거나 end보다 커지면 그 때 end값이 lower bound이므로 반복문을 종료하고 리턴한다.
•중간값이 원하는 값보다 작으면 start를 중간값으로 설정하여 다시 탐색한다.
•중간값이 원하는 값보다 크거나 같으면 end를 중간값으로 설정하여 다시 탐색한다

*/
#include<stdio.h>


int arr[1000000];
int ret[1000000];

int lowerBound(int size,int key)
{
	int start = 0;
	int end = size;

	while (start < end)
	{
		int mid = (start + end) >> 1;

		if (ret[mid] >= key)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}

	}

	return end;
}

int main()
{
	int N;
	int Idx = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	ret[0] = arr[0];

	for (int i = 1; i < N; i++)
	{
		if (ret[Idx] < arr[i])
		{
			ret[++Idx] = arr[i];
		}
		else
		{
			int lowerIdx = lowerBound(Idx, arr[i]);

			ret[lowerIdx] = arr[i];
		}
	}
	/*
	for (int i = 0; i <= Idx; i++)
	{
		printf("%d ", ret[i]);
	}
	*/
	printf("%d\n",Idx+1);

	return 0;
}