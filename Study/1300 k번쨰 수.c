/*
	n = 3, K = 7 인 경우

	1 2 3
	2 4 6
	3 6 9
	이므로 나열하면 1,2,2,3,3,4,6,6 이다.
	이 나열된 숫자중에 7번는 6인 것을 알 수 있다.


*/

#include<stdio.h>

int N,K;
int left, right;

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;
	else
		return n1;
}

int main()
{
	int res = 0;

	scanf("%d %d", &N, &K);

	left = 1, right = K;

	while (left <= right)
	{
		int mid = (left + right) >> 1;
		int cnt = 0;

		for (int i = 1; i <= N; i++)
		{
			cnt += min(mid / i, N);// 몫이 N보다 큰 경우 갯수가 N개인경우와 동일하게 함
		}

		if (cnt < K)
		{
			left = mid + 1;
		}
		else
		{
			res = mid;
			right = mid - 1;
		}
	}
	printf("%d\n", res);

	return 0;
}
