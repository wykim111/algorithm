/*
	1. Å½»ö
		for(i = 0 ~ N)
		{
			for(j = 0 ~ K)
			{
				int idx = ((i * K) + j);

				if(bread[idx] == 0)
				{
					++no_cream_cnt
				}
			}

			if(no_cream_cnt < P)
			{
				++result;
			}
		}
		

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K, P;
int result = 0;
vector<int> bread_vt;

void input()
{
	cin >> N >> K >> P;

	for (int i = 0; i < (N * K); i++)
	{
		int cream;

		cin >> cream;

		bread_vt.push_back(cream);
	}
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		int no_cream_cnt = 0;

		for (int j = 0; j < K; j++)
		{
			int idx = ((i * K) + j);

			if (bread_vt[idx] == 0)
			{
				++no_cream_cnt;
			}
		}

		if (no_cream_cnt < P)
		{
			++result;
		}

	}

	cout << result << '\n';
}

int main()
{
	input();
	solution();

	return 0;
}