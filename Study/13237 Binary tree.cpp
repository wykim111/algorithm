#include<cstdio>
#include<iostream>

using namespace std;

int n;
int node[21];
int parent[21];
int root;
int num;

int dfs(int vertax, int level)
{
	//root를 만나면 반환
	//해당노드의 부모노드 탐색
	if (parent[vertax] == -1 || parent[vertax] == 0)
	{
		return level;
	}
	
	return dfs(parent[vertax], level + 1);
}

int main()
{
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &parent[i]);
	
		
	}

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", dfs(i, 0));
	}
	
	return 0;
}
