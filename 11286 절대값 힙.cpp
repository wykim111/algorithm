#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;
int N;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//ÃÖ¼Ò Èü


int main()
{
	scanf("%d", &N);


	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);

		if (num)
		{
			pq.push({ abs(num),num });
		}
		else
		{
			if (pq.empty())
			{
				printf("0\n");
			}
			else
			{
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}

	}

		return 0;
}