/*
1.���� ��ġ�� û���Ѵ�.
2.���� ��ġ���� ���� ������ �������� ���ʹ������ ���ʴ�� Ž���� �����Ѵ�. 
a.���� ���⿡ ���� û������ ���� ������ �����Ѵٸ�, �� �������� ȸ���� ���� �� ĭ�� �����ϰ� 1������ �����Ѵ�.
b.���� ���⿡ û���� ������ ���ٸ�, �� �������� ȸ���ϰ� 2������ ���ư���.
c.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���� ��쿡��, �ٶ󺸴� ������ ������ ä�� �� ĭ ������ �ϰ� 2������ ���ư���.
d.�� ���� ��� û�Ұ� �̹� �Ǿ��ְų� ���̸鼭, ���� ������ ���̶� ������ �� �� ���� ��쿡�� �۵��� �����.
*/

#include<stdio.h>
#include<iostream>
#define NORTH 0//��
#define EAST 1 //��
#define SOUTH 2 //��
#define WEST 3 //��

using namespace std;
//�ϵ����� ��
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

// �ٶ󺸴� ���⿡ ���� ���� (��, ��, ��, ��)
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

		// ���� ��� ���
		if ( nextY >= N || nextY <0 || nextX >=M || nextX<0)
			continue;
		//û�Ҹ� �߰ų� ���� ��� ���� �ٲٱ� 
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

	//4���� ��� �˻��ؼ� û�Ҹ� �� �� ���
	//���� ��ġ���� ������ �� �ִ� ������ ����
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