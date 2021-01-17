#include<stdio.h>

int n, m;
int parent[1000001] = { 0, };

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
	{
		int y;
		//x의 루트를 찾아냄
		y = find(parent[x]);
		parent[x] = y;

		return parent[x];
	}
}
void Union(int x, int y)
{
	 x = find(x);
	 y = find(y);

	//y의 루트는 x로 설정
	if (x != y)
	{
		parent[y] = x;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, flag;

		scanf("%d %d %d", &flag, &a, &b);
		//flag == 0인 경우 합침
		if (flag == 0)
		{
			Union(a, b);
		}
		else//flag == 1인 경우 포함 확인
		{
			int parent_A = find(a);
			int parent_B = find(b);

			if (parent_A == parent_B)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	
	}//for i
	return 0;
}