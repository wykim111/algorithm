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
	//root�� ������ ��ȯ
	//�ش����� �θ��� Ž��
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