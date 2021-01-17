/*
	전사 탐색 시행
	각 알파벳에 직접 1부터 9까지 대입 단 같은 숫자이면 안됨 

	이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 
	같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

	1. 각 알파벳 저장
	2. 알파벳중에 중복된건 해당 위치 인덱스 리턴하며, 중복되지 않으면 -1 리턴
	3. 순열로 각 알파벳 0부터 9까지 대입(첫번째숫자에 0부터 9까지 대입 두번째 숫자에 첫번쨰 지정된 숫자 제외하고 대입)
	4. 최댓값 비교
*/
#include<stdio.h>
#include<string.h>

int N;
char str[11][11];
char alphabet[26] = { 0, };
int num[10];
int idx = 0;
int visit[10] = { 0, };
int retMax;

int checkAlphabet(char ch)
{
	for (int i = 0; i < idx; i++)
	{
		if (alphabet[i] == ch)
		{
			return i;
		}
	}

	return -1;
}


void perm(int dep)
{
	if (dep == idx)
	{
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			int cal = 0;
			int len = strlen(str[i]);

			for (int j = 0; j < len; j++)
			{
				cal = (cal * 10) + num[checkAlphabet(str[i][j])];
			}
			sum += cal;
		}

		if (sum > retMax)
		{
			retMax = sum;
		}
	}


	for (int i = 0; i < idx; i++)
	{
		if (visit[i] == 1)
			continue;

		visit[i] = 1;
		num[dep] = 9 - i;
		perm(dep + 1);
		visit[i] = 0;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", str[i]);

		while (getchar() != '\n'); //버퍼 지움
	}
	//알파벳 체크
	for (int i = 0; i < N; i++)
	{
		//NULL까지 탐색
		for (int j = 0; str[i][j] != '\0'; j++)
		{
			if (checkAlphabet(str[i][j]) == -1)
			{
				alphabet[idx++] = str[i][j];
			}
		}
	}
	/*
	for (int i = 0; i < idx; i++)
	{
		printf("%c\n", alphabet[i]);
	}
	*/
	perm(0);

	printf("%d\n", retMax);
	
	return 0;
}