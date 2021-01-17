/*
https://jaimemin.tistory.com/808
최소공배수를 이용하여 푸는 문제였습니다.

알고리즘은 아래와 같습니다.

1. 제한시간이 1초이며, M과 N이 40,000까지 주어질 수 있기 때문에 브루트 포스 형식으로는 풀 수 없는 문제였습니다.

2. M, N의 최소공배수가 멸망년도입니다.

3. 왼쪽에 주어진년도를 M으로 나누었을 때 x이여야하기 때문에 반복문 내에서 x에 M을 계속 더합니다.

4. 3번을 반복하는데 주어진 y를 만족하는 년도를 찾거나 x가 멸망년도를 초과하면 반복문에서 탈출합니다.

5. 멸망년도를 초과하면 -1을 출력하고 x, y를 만족하는 년도를 찾았다면 해당 년도를 출력합니다.
*/
#include<stdio.h>

int tc;
int M, N, x, y;

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return (a*b) / GCD(a, b);
}

int main()
{
	scanf("%d", &tc);
	
	while (tc--)
	{
		int tempM, tempN;
		int maxYear;
	
		scanf("%d %d %d %d", &M, &N, &x, &y);

		maxYear = LCM(M, N);
		while (1)
		{
			if (x > maxYear || (x-1) % N+1 == y)
			{
				break;
			}
			x += M;
		}
		if (x > maxYear)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", x);
		}
	}
	
	return 0;
}