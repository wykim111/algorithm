/*
	lower bound를 활용하여 port배열에 순서대로 넣어서 카운트한다.
	- port 배열에 최초인 경우 입력한 최초 원소를 넣는다
	- 이후 port 배열에 lowerbound를 이용해 인덱스에 데이터를 넣으며, 해당 인덱스에 데이터가 이미
	  존재하는 경우 그 원소를 비우고 위의 원소로 채운다.
	- 이미 체크한 포트이면 카운트를 하지 않는다.(꼬인 전깃줄 문제와 비슷)

*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int conn[40001];
int port[40001];

int N;

int lowerbound(int start, int end, int target)
{

	while (start < end)
	{
		int mid = (start + end) / 2;

		if (port[mid] >= target)
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
	int pos = 0;
	int retCnt = 0;
	int len = 0,idx=0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &conn[i]);
	}

	port[0] = conn[0];
	idx++;
	len++;
	/*
		port 배열에 원소를 새로 채우면 인덱스 길이 증가
		인덱스에 기존 원소가 있는 경우 대체
	*/
	for (int i = 1; i < N; i++)
	{
		//최대 연결선을 저장하는 port 배열의 마지막 원소와 i번째 원소 비교
		//
		if (port[len - 1] < conn[i])
		{
			port[len] = conn[i];
			len++;
			continue;
		}

		idx = lowerbound(0, len, conn[i]);
		port[idx] = conn[i];
	}

#if 0
	for (int i = 0; i < len; i++)
	{
		printf("%d ", port[i]);
	}
	printf("\n");
#endif

	printf("%d\n",len);

	return 0;
}
