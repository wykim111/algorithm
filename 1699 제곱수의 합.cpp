/*
	���� �˰���

	-> ��� dp�� �ذ�
	https://blog.naver.com/PostView.nhn?blogId=1ilsang&logNo=221415667120&categoryNo=50&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView
	(�ٸ� ���ٹ��:2���� dp�� �ذ��ϴ� ���)
	https://girlfriend-yerin.tistory.com/35
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define INF 99999999
using namespace std;

int N;
int dp[100001];

int go(int n)
{	
	if (n < 0)
	{
		return INF;
	}
	int& ret = dp[n];
	
	if (ret != 0)
		return ret;

	if (n == 0)
	{
		return 0;
	}
	
	int res = INF;

	for (int i = 1; i*i <= N; i++)
	{
		n -= (i*i);
		res = min(res,go(n)+1);
		n += (i*i);
	}
	ret = res;
	
	return ret;
}

int main()
{
	scanf("%d", &N);

	printf("%d\n",go(N));

	return 0;
}