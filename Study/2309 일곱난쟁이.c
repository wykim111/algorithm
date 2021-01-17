#include<stdio.h>
#include<stdlib.h>

int dwarf[9];
int res[7];
int visit[9];

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;//오름차순
}

int go(int dep, int cur,int sum)
{
	if (dep == 7)
	{
		if (sum == 100)
		{
			for (int i = 0; i < cur;i++)
			{
				if (visit[i] == 1)
				{
					printf("%d\n", dwarf[i]);
				}
				
			}
			return 1;
		}
		
	}

	for (int i = cur; i < 9; i++)
	{
		visit[i] = 1;
		if (go(dep + 1, i + 1, sum + dwarf[i]))//현재 난장이를 선택하는 경우
			return 1;
		visit[i] = 0;
		if (go(dep, i + 1, sum))////현재 난장이를 선택 안 하는 경우
			return 1;
	
	}
	return 0;
}


int main()
{
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &dwarf[i]);
	}
	
	qsort(dwarf, 9, sizeof(int),cmp);
	go(0,0, 0);


	return 0;
}
