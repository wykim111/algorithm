/*
	다익스트라-> 우선순위 큐를 이용해 구현
	Made By KWY

*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<queue>
#include<vector>
#include<functional>

#define INF 999999999
#define MAX_V 20001

using namespace std;

typedef pair<int, int> P;//2개의 자료형 사용 정의



vector<P>graph[MAX_V];
priority_queue<P, vector<P>, greater<P>> pq;


bool visit[MAX_V] = { 0, };
int dist[MAX_V];
int V, E;//정점, 간선의 갯수

int from,to, cost;//from 에서 to 로 가는 가중치 설정

//다익스트라 알고리즘(우선순위 큐 적용)-> C로 구현헀지만 C++ stl에 익숙해지기 위해
void dijkstra(int s)
{
	pq.push(make_pair(0,s));//간선, 정점 순
	dist[s] = 0;//시작점의 거리는 0

	//정점과 연결된 인접 정점 탐색
	//가장 작은 거리를 가진 키값을 가져옴
	while (!pq.empty())
	{
		int Cur_Dist=pq.top().first;//해당 정점의 거리
		int Cur_V = pq.top().second;//해당 정점
	
		pq.pop();

		//이전 정점의 거리가 우선순위 큐 안에 있을 때
		//이전 정점과 같은 정점이 거리가 더 짧은 경우(중복)
		if (dist[Cur_V] < Cur_Dist)
			continue;

		visit[Cur_V] = true;//정점 방문

		//인접 정점 거리 갱신
		int Size = graph[Cur_V].size();//graph의 인접한 정점 삽입의 사이즈를 나타냄
		for (int i = 0; i <Size ; i++)
		{
			int nextDist=graph[Cur_V][i].first;
			int nextV=graph[Cur_V][i].second;

			//다른 경로를 통한 현재정점거리가 현재정점까지 거리 보다 더 작은 경우 갱신
			if (dist[nextV] >Cur_Dist+nextDist)
			{
				dist[nextV] = Cur_Dist + nextDist;
				pq.push(make_pair(dist[nextV],nextV));
			}
		}

	}


}
void Print()
{
	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF)
		{
			printf("%d\n", dist[i]);
		}
		else
		{
			printf("INF\n");
		}
	}
}
int main()
{
	int start;//시작점
	scanf("%d %d", &V, &E);

	scanf("%d", &start);

	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &from, &to, &cost);
		graph[from].push_back(make_pair(cost, to));
	}

	//거리 초기화
	for (int i = 1; i <= V; i++)
	{
		dist[i] = INF;//가장 큰 값
	}

	dijkstra(start);
	Print();

	return 0;
}
