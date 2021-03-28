/*
	이진탐색 활용

	- 입력한 값들의 총 합이 maxMoney(최대 상한액)보다 작으면 입력한 값 중 최대치를 리턴
	- 입력한 값들의 총 합이 maxMoney보다 큰 경우 이진탐색 활용
	- 0원부터 입력한 최대 값 이진탐색 실행
	- mid 보다 작은 입력 데이터의 경우 sum에 그대로 합산하고, mid보다 크면 sum에 mid만큼 합산
	- sum에 합산한 금액 maxMoney에 근접하게 가까우면 정수 출력

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 

using namespace std;

vector<int>vt;
long long maxMoney = 0; //마지노선
int N;

int BinarySearch(int size)
{
	int start = 0, end = size;
	int mid = 0;
	
	long long sum = 0;

	while (start <= end)
	{
		sum = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < vt.size(); i++)
		{
			if (vt[i] < mid)
			{
				sum += vt[i];
			}
			else
			{
				sum += mid;
			}
		}

		if (sum <= maxMoney)
		{
			start = mid+1;
		}
		else
		{
			end = mid-1;
		}

	}

	return end;
}

bool cmp(int n1, int n2)
{
	return n1 < n2;
}

int main()
{	
	int sum = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);

		vt.push_back(num);
		sum += num;
	}
	scanf("%d", &maxMoney);

	sort(vt.begin(), vt.end(),cmp);

	/*
	for (int i = 0; i < vt.size(); i++)
	{
		printf("%d ", vt[i]);
	}
	printf("\n");
	*/

	if (sum < maxMoney)
	{
		printf("%d\n", vt[vt.size() - 1]);
		
	}
	else
	{
		printf("%d\n", BinarySearch(vt[vt.size()-1]));
	}

	


	return 0;
}
