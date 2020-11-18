#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<functional>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq; //최소힙

int main()
{
	int N;
	int num = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;

			scanf("%d", &num);

			pq.push(num);

			if (pq.size() > N)
			{
				pq.pop();
			}

		}
	}

	
	printf("%d\n", pq.top());

	return 0;
}
