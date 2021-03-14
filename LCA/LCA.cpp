/*
https://www.crocus.co.kr/660 의 포스팅을 보고 배웠습니다.

공통조상 알고리즘

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

/*
	depth : 트리 노드의 깊이
	ac[x][y] : x의 2^y번째 조상
*/
int depth[1001];
int ac[1001][20]; 


vector<int>graph[1001];

int maxLevel;

void swap(int* n1, int* n2)
{
	int temp = *n1;
		*n1 = *n2;
		*n2 = temp;

}

void getTree(int cur, int parent)
{
	//현재 cur(자식노드)의 깊이는 부모노드 + 1
	depth[cur] = depth[parent] + 1;
	//cur의 1번쨰  부모는 바로 root 부모 노드
	ac[cur][0] = parent;


	maxLevel = (int)floor(log2(1001));
	for (int i = 1; i <= maxLevel; i++)
	{
		/*
			temp = cur의 2^i번째 조상
			
			i = 3이면, cur의 8번째 조상은 cur의 4번째 조상(temp)의 4번째와 같음
		*/

		int temp = ac[cur][i - 1];
		ac[cur][i] = ac[temp][i - 1];
	}


	//dfs
	int len = graph[cur].size();

	for (int i = 0; i < len; i++)
	{
		int there = graph[cur][i];

		if (there != parent)
		{
			getTree(there, cur);
		}

	}

}

int main()
{
	int n, m;

	scanf("%d", &n);
	//양방향 그래프 생성
	for (int i = 1; i < n; i++)
	{
		int from, to;

		scanf("%d %d", &from, &to);
		graph[from].push_back(to);
		graph[to].push_back(from);
	}


	//쿼리
	scanf("%d", &m);

	//depth[1] = depth[0] +1 이므로
	//depth[0]을 -1로 설정해야함
	depth[0] = -1;
	getTree(1, 0);


	while (m--)
	{
		int a, b;

		scanf("%d %d", &a, &b);

		if (depth[a] != depth[b])
		{
			//depth[b] >= depth[a]가 되도록 swap하여 깊이 조정
			swap(&a, &b);

			/*
					b의 depth를 올려서 맞춤
					(-> 서로 다른 깊이를 가진 노드를 같은 깊이로 맞춤)

					maxLevel이 4라면
					2^4 -> 2^3 -> 2^2 -> 2^1 -> 2^0방식

					depth[a] <= depth[ac[b][4]]에 의해
					b = ac[b][4]가 되어 b는 b의 16번째 조상 참조
					b는 b의 16번쨰 조상을 참조하며
					depth[a] <= depth[ac[b][1]]에 의해 
					b = ac[b][1]이 되어 b는 b의 2번쨰 조상을 참조하게 됨
			
			*/

			for (int i = maxLevel; i >= 0; i--)
			{
				//b의 조상이 a의 depth보다 크거나 같으면 위로 이동
				if (depth[a] <= depth[ac[b][i]])
				{
					b = ac[b][i];
				}
			}


		}//if depth[a] depth[b]

		int lca = a;

		if (a != b)
		{
			for (int i = maxLevel; i >= 0; i--)
			{
				if (ac[a][i] != ac[b][i])
				{
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}//if a!= b

		printf("%d\n", lca);

	}//while m


	return 0;
}
