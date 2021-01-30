/*
	전형적인 BFS 문제
	시작위치의 횟수는 0이며 주변에 이동할 수 있는 경로에 현재 지점+1로 업데이트

*/

#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int map[201][201];
int visit[201][201];
int r1, c1, r2, c2;

int dy[] = { -2,-2,0,0,2,2 };//6개 방향
int dx[] = { -1,1,-2,2,-1,1 };

queue<pair<int, int>> Que;

int main()
{
	scanf("%d", &N);

	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	Que.push(make_pair(r1, c1));
	visit[r1][c1] = 1;

	while (!Que.empty())
	{
		int curY = Que.front().first;
		int curX = Que.front().second;
		

		Que.pop();

		for (int i = 0; i < 6; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			//범위를 벗어난 경우
			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N || visit[nextY][nextX] == 1)
				continue;

			if (visit[nextY][nextX] == 0)
			{
				Que.push(make_pair(nextY, nextX));
				map[nextY][nextX] = map[curY][curX] + 1;
				visit[nextY][nextX] = 1;

			}

		}
	}
	if (map[r2][c2] == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", map[r2][c2]);
	}
	return 0;
}
