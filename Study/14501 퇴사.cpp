#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int T[16];
int P[16];
int ret;
//날짜,금액순
void go(int T_Sum, int P_Sum)
{
	
	if (T_Sum == N+1)
	{
		ret = max(ret, P_Sum);
		return;
	}
	//현재 상담을 선택 안한 경우
	go(T_Sum + 1, P_Sum);
	//현재 상담을  선택 한 경우
	//기간이 초과되면 skip
	if (T_Sum + T[T_Sum] <= N+1)
	{
		go(T_Sum + T[T_Sum], P_Sum + P[T_Sum]);
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}
	go(1, 0);

	printf("%d\n", ret);

	return 0;
}
