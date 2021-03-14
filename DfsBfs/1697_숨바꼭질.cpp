/*
	BFS 풀이

	- 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동
	- 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동

	BFS로 큐에 현재 위치를 집어 넣고 걷는 경우, 순간이동 하는 경우
	모두 집어넣는다.
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

queue<pair<int, int>>Que;//first : 위치, second : 이동 횟수
int subin, brother; //수빈과 수빈의 동생 위치 입력
//->현재위치 *2 해서 100002번째인 경우 타겟 100000번째에 2번 이동하면 되는 경우가 있음 
int visit[200000];//여기에서 틀렸습니다 발생!!!!!!! 
int minRet = 123456789;

int main()
{
	scanf("%d %d", &subin, &brother);

	Que.push(make_pair(subin, 0));


	//수빈과 동생이 처음부터 같은 위치에 있는 경우
	if (subin == brother)
	{
		printf("0");

		return 0;
	}

	while (!Que.empty())
	{
		int curX = Que.front().first;
		int cnt = Que.front().second;

		visit[curX] = 1;
		Que.pop();

		if (curX == brother)
		{
			minRet = min(minRet, cnt);
		}

		int nextX = curX + 1;

		if (nextX >= 0 && nextX <= 100000 && visit[nextX]==0)
		{
			Que.push(make_pair(nextX,cnt+1));
		}
		nextX = curX - 1;
		if (nextX >= 0 && nextX <= 100000 && visit[nextX]==0)
		{
			Que.push(make_pair(nextX, cnt + 1));
		}
		nextX = curX * 2;
		if (nextX>= 0 && nextX <= 100000  && visit[nextX]==0)
		{
			Que.push(make_pair(nextX, cnt + 1));
		}
	}

	printf("%d\n", minRet);

	return 0;
}
