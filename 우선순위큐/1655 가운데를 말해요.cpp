*
	지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 
	그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서
	작은 수를 말해야 한다.

	1. MIN 우선순위 큐 선언, MAX 우선순위 큐 선언
	2. MIN 우선순위 큐의 원소는 MAX 우선순위 큐 원소보다 크다
	  - 작은 경우 MIN의 top과 MAX의 top을 바꿔준다.
	3. MAX 우선순위 큐의 크기 > MIN 우선순위 큐 ( MIN 우선순위 큐 원소보다 1 차이) 
	   ***** pq.size()를 반복문의 조건으로 넘기면 이 사이에 push,pop하는 동안 size가 가변적으로 변하므로 변수로 따로 저장 할 것!!
	   ***** 
	 MIN			MAX
	{}			{1}
	{5}			{1}
	{5}			{2,1} - > 2
	{10,5}			{2,1}
	{10,5}		{2,1,-99}
	{10,7,5}	{2,1,-99}
	{10,7,5}	{5,2,1,-99}
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<functional>
#include<vector>

using namespace std;
vector<int>vt;
priority_queue<int, vector<int>, greater<int>>pq1;//MIN
priority_queue<int, vector<int>, less<int>>pq2;//MAX
int N;

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int num;
		int tempSize;

		scanf("%d", &num);
		
		if (pq2.size() > pq1.size())
			pq1.push(num);
		else
			pq2.push(num);

		if (pq1.size() > 0 && pq2.size() > 0)
		{
			if (pq2.top() > pq1.top())
			{
				int MaxData, MinData;

				MaxData = pq2.top();
				MinData = pq1.top();

				pq1.pop();
				pq2.pop();

				pq1.push(MaxData);
				pq2.push(MinData);
				
			}
		}
		printf("%d\n", pq2.top());
	}
}
