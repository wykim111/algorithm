/*
	BFS 접근
	수빈이가 걷는 경우 : X+1, X-1
	순간이동 하는 경우 : 2*X

	현재 위치에서 위에 해당하는 이동을 하여 해당하는 위치에 접근한다.
	접근하면서 1초씩 더한다.

	from 배열을 이용해 이전에 어떤 위치에 있었는지 저장한다.
	재귀를 이용하여 추적
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> vt;
//비용, 위치
queue<pair<int,int>> Que;
int N, K;
int visit[100001];
int from[100001];
int dir[3] = { -1,1,2 };//2인 경우 곱하기
int ret = 0;

void BFS()
{

	while (!Que.empty())
	{
		int size = Que.size();
		int cur = Que.front().second;
		int cnt = Que.front().first;

		Que.pop();

		//도착지에 도달한 경우
		if (cur == K)
		{
			ret = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int next;

			if (i < 2)
			{
				next = cur + dir[i];
			}
			else
			{
				next = cur * dir[i];

			}

			if (next < 0 || next >= 100001 || visit[next] == 1)
				continue;

			if (visit[next] == 0)
			{
				Que.push(make_pair(cnt + 1, next));
				visit[next] = 1;
				from[next] = cur;
			}
		}


	}
}

void trace(int n,int m)
{
	if (n != m)
	{
		trace(n, from[m]);
	}

	printf("%d ", m);
}

int main()
{
	scanf("%d %d", &N, &K);

	Que.push(make_pair(0,N));
	visit[N] = 1;

	//빠른시간 출력
	BFS();
	printf("%d\n", ret);

	trace(N, K);
	return 0;
}