/*
	���� https://yabmoons.tistory.com/75

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include <map>
#include<string>

using namespace std;

//1���� ���ڿ� �������� ���� �¿� �񱳴� �������ϰ� �������� ����
int ds[] = { 1,-1,3,-3 };//dy, dx�� ���� 1���� ���ڿ��� 2���� ���̺� ���� �ɶ� �����¿� �����ϴ� ���

//��������
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

string dest = "123456780";
string src;

//set ��� (����Ʈ��)
set<string> visit;
queue<pair<string, int>> Que;
int res = 0;

int BFS()
{
	//�湮 �迭�� ���� ���ڿ� �湮 Ȯ�� �� ť�� ����
	visit.insert(src);
	Que.push(make_pair(src, 0));

	while (!Que.empty())
	{
		string cur = Que.front().first;
		int cnt = Que.front().second;
		Que.pop();

		//������(dest)�� ��ġ�ϸ� return
		if (cur == dest)
		{
			return cnt;
		}
		int zero_pos = cur.find('0');
		int y = zero_pos / 3;
		int x = zero_pos % 3;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			//���� �ʰ� ��
			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
			{
				continue;
			}
			//���� ��ġ�� ������ ��ġ���� ������ġ�� �ٲ۴�. -> 2���� �迭�� �������� 1���� ���������� ��ȯ�Ͽ� ����
			string next = cur;
			swap(next[y * 3 + x], next[ny * 3 + nx]);

			//����� ���ڿ��� ������ ���� ���
			if (visit.find(next) == visit.end())
			{
				visit.insert(next);
				Que.push(make_pair(next, cnt + 1));
			}


		}
	}
	return -1;
}

int main()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num;
			char ch;

			scanf("%d", &num);

			ch = num + '0';
			src += ch;
		}
	}



	/*
	while (!Que.empty())
	{
		string cur = Que.front().first;
		int cnt = Que.front().second;
		Que.pop();

		//������(dest)�� ��ġ�ϸ� return
		if (cur == dest)
		{
			return cnt;
		}
		int zero_pos = cur.find('0');
		int y = zero_pos / 3;
		int x = zero_pos % 3;

		for(int i=0;i<4;i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			//���� �ʰ� ��
			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
			{
				continue;
			}
			string next = cur;
			swap(next[y*3 + x], next[ny*3 + nx]);

			//����� ���ڿ��� ������ ���� ���
			if (visit.find(next) == visit.end())
			{
				visit.insert(next);
				Que.push(make_pair(next, cnt + 1));
			}


		}

	}
		*/
	printf("%d\n", BFS());

	return 0;
}