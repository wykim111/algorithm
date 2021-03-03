/*
	- anta와 tica에 해당하는 아스키에 비트 체크
	- dfs를 활용하여 사용하지 않은 단어를 체크하고 
	자기 자신에게 돌아오면 체크 해제
	- K개까지 체크하면 N개의 글자와 & 연산자를 통해 연산하여
	N개의 글자와 매칭되면 카운트

*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int word[50] = { 0, };
int teach = 0;

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}

int dfs(int idx, int pick)
{
	int retCnt = 0;

	if (pick == K)
	{
		for (int i = 0; i < N; i++)
		{
			if ((word[i] & teach) == word[i])
			{
				retCnt++;
			}
		}

		return retCnt;
	}

	for (int nextIdx = idx; nextIdx < 26; nextIdx++)
	{
		//이미 비트가 켜진 경우 스킵
		if ((teach &(1 << nextIdx))!=0)
		{
			continue;
		}
		teach |= (1 << nextIdx);//체크
		retCnt = max(retCnt,dfs(nextIdx + 1, pick + 1));
		teach &= ~(1 << nextIdx);//해제
	}

	return retCnt;
}


int main()
{
	scanf("%d %d", &N, &K);

	//anta와 tica에 해당하는 아스키에 비트 체크
	teach |= 1 << ('a' - 'a');
	teach |= 1 << ('c' - 'a');
	teach |= 1 << ('i' - 'a');
	teach |= 1 << ('n' - 'a');
	teach |= 1 << ('t' - 'a');

	for (int i = 0; i < N; i++)
	{
		string str;

		cin >> str;
	
		for (int j = 0; j < str.size(); j++)
		{
			word[i] |= (1 << (str[j] - 'a'));
		}

	}
	if (K < 5)
	{
		printf("0\n");
	}
	else
	{  //왜 5개냐면 a,c,i,n,t 5개 글자를 포함하므로
		printf("%d\n", dfs(0,5));
	}
	
	

	return 0;
}
