/*
	1.알파벳 배열에 입력된 문자열 알파벳 카운트
	2. dfs 탐색
		- A부터 Z까지 순서대로 탐색
		- 해당 알파벳 배열에 데이터가 0이면 스킵
		- 해당 알파벳 배열에 데이터가 0이 아니면 감소하고 순열 데이터에 저장
*/
#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map> 
using namespace std;

int N;
char str[1001];
char permArr[1001];
int alphabet[26];
int cnt = 0;

void perm(int size, int curIdx)
{
	if (curIdx == size)
	{
		for (int i = 0; i < size; i++)
		{
			printf("%c", permArr[i]);
		}
		printf("\n");

		return;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == 0)
		{
			continue;
		}

		if (alphabet[i] > 0)
		{
			alphabet[i]--;
		}
		
		permArr[curIdx] = i + 'a';
		perm(size, curIdx + 1);
		alphabet[i]++;

	}
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int len = 0;
		
		cnt = 0;
		memset(str, 0, sizeof(str));
		memset(permArr, 0, sizeof(permArr));
		memset(alphabet, 0, sizeof(alphabet));

		scanf("%s", str);

		len = strlen(str);

		for (int j = 0; j < len; j++)
		{
			alphabet[str[j] - 'a']++;
		}
	//	printf("%s\n", str);
		perm(len, 0);

	}



	return 0;
}
