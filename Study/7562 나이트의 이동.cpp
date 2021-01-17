#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<queue>

using namespace std;

int map[301][301];

int TC;
int mapSize;
int startY, startX;
int endY, endX;
int visit[301][301];
//상하좌우 대각선
int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = { 1,2,2,1,-1,-2,-2,-1};


queue<pair<int, int>> Que;

void Init()
{
	memset(map, 0, sizeof(map));
	memset(visit, 0, sizeof(visit));
}

void Input()
{
	//길이 입력
	scanf("%d", &mapSize);
	//나이트 시작 위치 입력
	scanf("%d %d", &startY, &startX);
	//나이트 도착 위치 입력
	scanf("%d %d", &endY, &endX);
}

int BFS()
{
	Que.push(make_pair(startY, startX));
	visit[startY][startX] = 1;
//	printf("%d %d\n", Que.front().first, Que.front().second);

	while (!Que.empty())
	{
		int queLen = Que.size();

		int curY = Que.front().first;
		int curX = Que.front().second;

		Que.pop();

			//도착한경우
			if (curY == endY && curX == endX )
			{
				//큐 초기화
				while (!Que.empty())
				{
					Que.pop();
				}

				return map[curY][curX];
			}


			for (int i = 0; i < 8; i++)
			{
				int nextY = curY + dy[i];
				int nextX = curX + dx[i];

				//맵을 벗어나는 경우
				if (nextY < 0 || nextY >= mapSize || nextX < 0 || nextX >= mapSize || visit[nextY][nextX] == 1)
				{
					continue;
				}
				if (visit[nextY][nextX] == 0)
				{
					Que.push(make_pair(nextY, nextX));
					visit[nextY][nextX] = 1;
					map[nextY][nextX] = map[curY][curX] + 1;
				}
				
			}
		
	}//while Que empty()
	return 0;
}

int main()
{
	scanf("%d", &TC);

	while (TC--)
	{
		Init();
		Input();
		printf("%d\n",BFS());
		
	}
	return 0;
}