/*
	< 구현 >

	1. 3중 루프
	// 분, 초는 0부터 59까지 (< 60)
	for (int h = 0; h <= N; h++) {
		for (int m = 0; m < 60; m++) {
			for (int s = 0; s < 60; s++) {
				// 시, 분, 초 각각의 십의 자리(/10)와 일의 자리(%10) 중 하나라도 K와 같다면
				if (h / 10 == K || h % 10 == K ||
					m / 10 == K || m % 10 == K ||
					s / 10 == K || s % 10 == K) {
					count++;
				}
			}
		}
	}

*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int cnt = 0;

void input()
{
	cin >> N >> K;
}

void solution()
{
	for (int h = 0; h <= N; h++)
	{
		for (int m = 0; m < 60; m++)
		{
			for (int s = 0; s < 60; s++)
			{
				if ((h / 10) == K || (h % 10) == K || (m / 10) == K || (m % 10) == K || (s / 10) == K || (s % 10) == K)
				{
					++cnt;
				}
			}
		}
	}

	cout << cnt << "\n";
}


int main()
{
	input();
	solution();

	return 0;
}
