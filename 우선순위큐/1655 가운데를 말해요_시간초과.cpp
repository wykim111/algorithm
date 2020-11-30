/*
	지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 
	그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서
	작은 수를 말해야 한다.

	1. Min 우선순위 큐 선언
	2. 갯수 체크하여 짝수개라면 size/2, (size/2)+1 이 두 수 중 가장 작은거 택
	3. 홀수 개라면 (size/2)+1번째 수를 택  
	4. 해당 가운데수를 출력하고,해당수를 포함한 나머지 수도 다시 pop하고 push
	   (vector에 우선순위 큐에서 pop한걸 넣어주고 다시 push)

	   ***** pq.size()를 반복문의 조건으로 넘기면 이 사이에 push,pop하는 동안 size가 가변적으로 변하므로 변수로 따로 저장 할 것!!
	   
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>

using namespace std;
vector<int>vt;
priority_queue<int, vector<int>, greater<int>>pq;//MIN

int N;

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;
		int tempSize;

		scanf("%d", &num);
		pq.push(num);

		//홀수
		if (pq.size() % 2 == 1)
		{
			tempSize = pq.size();
			for (int j = 1; j < (tempSize / 2) + 1; j++)
			{
				vt.push_back(pq.top());
				pq.pop();
			}
			printf("%d\n", pq.top());

				for (int j = 0; j < vt.size(); j++)
				{
					pq.push(vt[j]);
				}
		
			
		}
		else//짝수
		{
			tempSize = pq.size();
			for (int j=1; j < (tempSize / 2); j++)
			{
				vt.push_back(pq.top());
				pq.pop();
			}

			printf("%d\n",pq.top());
			
			for (int j = 0; j < vt.size(); j++)
				{
					pq.push(vt[j]);
				}
			
		
		}
		vt.clear();
	}
}
