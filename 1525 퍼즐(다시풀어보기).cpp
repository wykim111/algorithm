/*
	참고 https://yabmoons.tistory.com/75

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

//1차원 문자열 기준으로 상하 좌우 비교는 동서남북과 차이점이 있음
int ds[] = { 1,-1,3,-3 };//dy, dx와 같이 1차원 문자열이 2차원 테이블에 묘사 될때 상하좌우 구분하는 방법

//동서남북
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

string dest = "123456780";
string src;

//set 기반 (이진트리)
set<string> visit;
queue<pair<string, int>> Que;
int res = 0;

int BFS()
{
	//방문 배열로 시작 문자열 방문 확인 및 큐에 저장
	visit.insert(src);
	Que.push(make_pair(src, 0));

	while (!Que.empty())
	{
		string cur = Que.front().first;
		int cnt = Que.front().second;
		Que.pop();

		//목적지(dest)와 일치하면 return
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

			//범위 초과 시
			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
			{
				continue;
			}
			//현재 위치한 상태의 위치에서 다음위치로 바꾼다. -> 2차원 배열의 포지션을 1차원 포지션으로 변환하여 접근
			string next = cur;
			swap(next[y * 3 + x], next[ny * 3 + nx]);

			//변경된 문자열이 기존에 없는 경우
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

		//목적지(dest)와 일치하면 return
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

			//범위 초과 시
			if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
			{
				continue;
			}
			string next = cur;
			swap(next[y*3 + x], next[ny*3 + nx]);

			//변경된 문자열이 기존에 없는 경우
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