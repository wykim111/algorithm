/*
	(MAX 힙에는 중앙값 이하, MIN 힙에는 중앙값보다 큰 값)
	2개의 우선순위 큐를 이용하여 중앙값을 구함(MIN ,MAX)
	MAX우선순위 큐와 Min 우선순위 큐 2개를 두고 데이터를
	넣어주면 MAX우선순위 큐의 루트 값이 중앙값이 되도록 한다.

	사이즈가 양쪽 다 같은 경우
	MAX힙에서 중앙값을 기준으로  크면 MIN, 작으면 MAX에 저장한다.

	사이즈가 다른 경우
	중앙값이 큰 경우 현재 중앙값을 MIN으로 삽입하고
	MAX힙에 데이터를 넣어준다.

	1, 첫 데이터는 max힙에 넣는다.
	2-1 이후 max힙과 min힙의 사이즈가 다른 경우max 힙의 top이 num보다 큰 경우 min힙에 max힙 탑의 데이터를 넣고, max힙은 pop
       하고, num을 max힙에 넣는다.
	2-2 max힙과 min힙의 사이즈가 다른 경우 max 힙의 top이 num 보다 작은 경우 min 힙에 num을 push
	3-1 max 힙과 min 힙의 사이즈가 같은 경우, min 힙의 top이 num보다 작으면 max 힙에 min힙의 top을 push 후 pop하고
	  min 힙에 num push
	3-2 max 힙과 min 힙의 사이즈가 같은 경우, min 힙의 top이 num보다 큰 경우, max 힙에 num push

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;
int tc;

int main()
{
	scanf("%d", &tc);

	while (tc--)
	{

		vector<int>vt;
		priority_queue<int, vector<int>, greater<int> >minPq;//최소 힙
		priority_queue<int, vector<int>, less<int> >maxPq;//최대 힙
		int M;
		int cnt = 0;

		scanf("%d", &M);



		for (int i = 1; i <= M; i++)
		{
			int num;
			scanf("%d", &num);

			if (maxPq.size() == minPq.size())
			{
				//최소힙이 비워져있는 경우
				if (minPq.empty())
				{
					maxPq.push(num);
				}
				else//minPq 사이즈가 0이 아닌 경우
				{
					if (minPq.top() <= num)
					{
						maxPq.push(minPq.top());
						minPq.pop();
						minPq.push(num);

					}
					else
					{
						maxPq.push(num);
					}
				}//else
			}
			else
			{
				if (maxPq.top() > num)
				{
					minPq.push(maxPq.top());
					maxPq.pop();
					maxPq.push(num);
				}
				else
				{
					minPq.push(num);

				}
			}//else

			//홀수인 경우
			if (i % 2 == 1)
			{
				vt.push_back(maxPq.top());
			}

		}//for
		printf("%d\n", (M / 2) + 1);
		for (int i = 0; i < vt.size(); i++)
		{
			printf("%d ", vt[i]);

		}
		printf("\n");

	}//tc
	return 0;
}
