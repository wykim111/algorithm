#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>

using namespace std;

int N;

typedef struct _position
{
	int x;
	int y;
}Position;

Position pos[100000];

bool cmp(const Position& p1, const Position& p2)
{
	if (p1.x != p2.x)
		return p1.x < p2.x;
	else
	{
		if (p1.y != p2.y)
		{
			return p1.y < p2.y;
		}
	}

	return p1.x == p2.x;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int y, x;
		scanf("%d %d", &x, &y);
		pos[i].y = y;
		pos[i].x = x;
	}
	
	sort(pos + 0, pos + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", pos[i].x, pos[i].y);
	}

	return 0;
}