/*
	BFS ����
	�����̰� �ȴ� ��� : X+1, X-1
	�����̵� �ϴ� ��� : 2*X

	���� ��ġ���� ���� �ش��ϴ� �̵��� �Ͽ� �ش��ϴ� ��ġ�� �����Ѵ�.
	�����ϸ鼭 1�ʾ� ���Ѵ�.

	from �迭�� �̿��� ������ � ��ġ�� �־����� �����Ѵ�.
	��͸� �̿��Ͽ� ����
*/

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> vt;
//���, ��ġ
queue<pair<int,int>> Que;
int N, K;
int visit[100001];
int from[100001];
int dir[3] = { -1,1,2 };//2�� ��� ���ϱ�
int ret = 0;

void BFS()
{

	while (!Que.empty())
	{
		int size = Que.size();
		int cur = Que.front().second;
		int cnt = Que.front().first;

		Que.pop();

		//�������� ������ ���
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

	//�����ð� ���
	BFS();
	printf("%d\n", ret);

	trace(N, K);
	return 0;
}