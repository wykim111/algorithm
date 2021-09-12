/*
	인접해 있는 모든 문자가 같지 않은 문자열 카운트
	1. 문자 재배치 -> 순열 이용
	2. 행운문자 판별 -> 현재문자로부터 우측 문자와 비교
	3. 같은 데이터가 순열에 있으면 답이 중복되는 경우도 존재
		- ex) aba의 경우 "aba", "aab", "baa", "baa", "aba","aab" 와 같음
		- 이 중복을 어떻게 해결?
		  -> 알파벳 배열을 이용하여 문자열의 알파벳 카운트
		  -> 중복횟수를 구한다!***** : ( factorial(a의 갯수) * factorial(b의 갯수) )로 중복된 경우의 수를 나눈다.
=============================================위는 중복을 처리하는 방법에서 막힘,아래는 고민하다가 쉽게 해결한 방법====================================================================================
	1. 문자열에 구성된 알파벳을 카운트
	2. 문자열을 현재 존재하는 알파벳과 카운트를 이용해 구성
		- a부터 z까지 탐색하면서 각 알파벳 카운트를 감소시켜 문자열 구성
		- 감소시킨 알파벳의 카운트는 다시 원래대로 복구(순열 알고리즘)
	3. 문자열을 구성하면  0번째부터 문자열길이 -1까지 탐색하여 우측문자와 같은지 비교

*/
#include<stdio.h>
#include<string.h>

char str[11];
int visit[11];
char perm_arr[11];
int retCnt = 0;
char alphabet[26];

int fact(int num)
{
	int sum = 1;

	for (int i = 0; i < num; i++)
	{
		sum *= num;
		num--;
	}

	return sum;
}

int is_lucky(char* pStr, int size)
{
	int flag = 1;

	for (int i = 0; i < size-1 ; i++)
	{
		//현재 문자로부터 우측문자와 비교
		if (((pStr[i] != pStr[i + 1])) == 1)
		{
			flag = 1;
		}
		else
		{
			flag = 0;
			break;
		}
	}

	return flag;
}

void perm(int dep, int size)
{
	if (dep == size)
	{
#if 0
		for (int i = 0; i < size; i++)
		{
			printf("%c", perm_arr[i]);
		}
		printf("\n");
#endif
		//기존에 쓰인 문자열이면 스킵
	//	printf("진입 %s", perm_arr);
		retCnt += is_lucky(perm_arr, size);

		return;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alphabet[i] == 0 && dep == size-1)//마지막 자리인데 알파벳이 없는 경우 계속 탐색
		{
			continue;
		}
		if (alphabet[i] > 0)
		{
			alphabet[i]--;
			perm_arr[dep] = i+'a';
			perm(dep + 1, size);
			alphabet[i]++;

		}
		
	}
}

int main()
{
	int strLen = 0;
	int divisor = 1;

	scanf("%s", str);

	strLen = strlen(str);

	for (int i = 0; i < strLen; i++)
	{
		alphabet[str[i]-'a']++;
	}

	perm(0, strLen);

	

	printf("%d\n", retCnt);


	return 0;
}
