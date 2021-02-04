#include<stdio.h>

int computer;
int network;

int parent[101] = { 0, };

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}
	else
	{
		int p;
		p = find(parent[x]);
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x != y)
	{
		parent[y] = x;
	}

}

int main()
{
	int cnt = 0;

	scanf("%d", &computer);
	scanf("%d", &network);

	for (int i = 1; i <= computer; i++)
	{
		parent[i] = i;
	}

	//유니온 파인드를 이용해 각 영역의 root를 나눈다.
	//영역별로 나눔
	for (int i = 1; i <= network; i++)
	{
		int u, v;

		scanf("%d %d", &u, &v);
		Union(u, v);
	}
	/* 부모 노드 체크
	for (int i = 1; i <= computer; i++)
	{
		printf("%d ", parent[i]);
	}
	*/
	for (int i = 2; i <= computer; i++)
	{
		if (find(1) == find(i))
			cnt++;
	}

	printf("%d\n", cnt);

	return 0;
}
