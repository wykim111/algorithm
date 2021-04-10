/*
	- 최초 데이터는 수열을 저장하는 배열(vt)에 저장
	- 1부터 N-1까지 반복하여 vt의 마지막 원소보다 크면 vt에 저장
	- 크지 않으면 lowerbound로 들어갈 인덱스를 골라 기존의 데이터와 대체
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> vt;
vector<int> input;

int lowerBound(int start, int end, int target)
{
	while (start < end)
	{
		int mid = (start + end) / 2;

		if (vt[mid] >= target)
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
	int idx = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);

		input.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		//맨 처음 데이터는 vt에 저장
		if ( (i == 0 ) || (vt[vt.size()-1] < input[i]) )
		{
			vt.push_back(input[i]);
		}

		idx = lowerBound(0, vt.size() - 1, input[i]);
		vt[idx] = input[i];
	}
#if 0
	for (int i = 0; i < vt.size(); i++)
	{
		printf("%d ", vt[i]);
	}
	printf("\n");
#endif

	printf("%d\n", vt.size());


	return 0;
}
