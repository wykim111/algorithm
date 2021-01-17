/*
1.현재 위치를 청소한다.
2.현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다. 
a.왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
b.왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
c.네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
d.네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
*/

#include<stdio.h>
#include<iostream>
#define NORTH 0//북
#define EAST 1 //동
#define SOUTH 2 //남
#define WEST 3 //서

using namespace std;
//북동남서 순
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

// 바라보는 방향에 따른 후진 (남, 서, 북, 동)
int back_dy[4] = { 1,0,-1,0 };
int back_dx[4] = { 0,-1,0,1 };

int N, M;
int r, c,d;
int map[51][51];
int visit[51][51];
int cnt = 0;

void dfs(int curY, int curX, int dir)
{
	if (map[curY][curX] == 1)
		return;
	if (map[curY][curX] == 0)
	{
		cnt++;
		map[curY][curX] = 2;
	}
	//printf("cnt = %d curY = %d, curX = %d\n",cnt, curY, curX);
	for (int i = 0; i < 4; i++)
	{
		int nextDir = dir - 1 < 0 ? 3 : dir - 1;
		int nextY = curY + dy[nextDir];
		int nextX = curX + dx[nextDir];

		// 맵을 벗어난 경우
		if ( nextY >= N || nextY <0 || nextX >=M || nextX<0)
			continue;
		//청소를 했거나 벽인 경우 방향 바꾸기 
		if (map[nextY][nextX] == 1 ||map[nextY][nextX] == 2)
		{
			dir = nextDir;
			continue;
		}
		if (map[nextY][nextX] == 0)
		{
			dfs(nextY, nextX, nextDir);
			return;
		}
		
	}

	//4방향 모두 검사해서 청소를 다 한 경우
	//현재 위치에서 후진할 수 있는 방향을 저장
	int nextY = curY + back_dy[dir], nextX = curX + back_dx[dir];

	dfs(nextY, nextX, dir);
}

int main()
{
	scanf("%d %d", &N, &M);

	scanf("%d %d %d", &r, &c, &d);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	dfs(r, c, d);

	printf("%d\n", cnt);

	return 0;
}