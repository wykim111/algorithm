/*
	1. 각 단어를 순열을 이용한 경우의 수로 2개 조합
	2. 팰린드롬인지 확인
		- 길이를 2로 나눔(mid)
		- 0부터 미드까지 비교
			-> i와 len-i-1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
char str[100][10001];
int visit[100];
int perm_arr[2];
char merge_str[10001];

void init()
{
	memset(visit, 0, sizeof(visit));
	memset(merge_str, 0, sizeof(merge_str));
	for (int i = 0; i < 100; i++)
	{
		memset(str[i], 0, sizeof(str[i]));
	}
}

int is_palindrome(char* pStr)
{
	int size = strlen(pStr);

	
	for (int i = 0; i < size/2; i++)
	{
		if (pStr[i] != pStr[size - i - 1])
		{
			return 0;
		}
	}
	return 1;
}

void merge_string(char* pStr1,char* pStr2)
{
	memset(merge_str, 0, sizeof(merge_str));
	strcat(merge_str, pStr1);
	strcat(merge_str, pStr2);
}
void perm(int dep,int size)
{
	if (dep == 2)
	{
	//	printf("%d %d\n", perm_arr[0], perm_arr[1]);
		merge_string(str[perm_arr[0]], str[perm_arr[1]]);
		printf("%s\n", merge_str);
		
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (visit[i] == 1)
			continue;
		visit[i] = 1;
		perm_arr[dep] = i;
		perm(dep + 1, size);
		visit[i] = 0;
	}
}
int main()
{
	scanf("%d", &N);

	while (N--)
	{
		int k;
		int flag = 0;

		scanf("%d", &k);

		init();
		for (int i = 0; i < k; i++)
		{
			scanf("%s", str[i]);
		}

		//perm(0,k);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i == j)
				{
					continue;
				}
				merge_string(str[i], str[j]);
				//printf("%s\n", merge_str);
				if (is_palindrome(merge_str) == 1)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}

		if (flag == 1)
		{
			printf("%s\n", merge_str);
		}
		else
		{
			printf("0\n");
		}
		
	}

	return 0;
}
