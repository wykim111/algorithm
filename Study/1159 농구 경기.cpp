/*
    0. 첫 글자를 인덱스로 하여 배열에 카운트
	1. 첫 글자가 5개 이상이면 테이블 배열에 저장
	   테이블에 같은 성이 5개 미만인 경우	PREDAJA 출력 하고 종료
	2. 오름차순으로 정렬

	상근이가 선수 다섯 명을 선발할 수 없는 경우에는 "PREDAJA" (따옴표 없이)를 출력한다. PREDAJA는 크로아티아어로 항복을 의미한다. 
	선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력한다.
*/
#include<stdio.h>
#include<string.h>

char name[150][32];
int N;
int firstName[26] = { 0, };
char nameTable[26];
int nameTableIdx = 0;

int pickName()
{
	int flag = 0;

	for (int i = 0; i < 26; i++)
	{
		if (firstName[i] >= 5)
		{
			nameTable[nameTableIdx++] = i + 'a';
			flag = 1;
		}
	}

	if (flag == 0)
	{
		return 0; //5개 미만인 경우
	}

	return 1; //5개 이상인 경우
}

void bubbleSort()
{
	for (int i = 0; i < nameTableIdx-1; i++)
	{
		for (int j = 0; j < nameTableIdx - 1 - i; j++)
		{
			if (nameTable[j] > nameTable[j + 1])
			{
				char temp = nameTable[j];
				nameTable[j] = nameTable[j + 1];
				nameTable[j + 1] = temp;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", name[i]);
		while (getchar() != '\n');

		firstName[name[i][0] - 'a']++;
	}

	if (pickName() == 0)
	{
		printf("PREDAJA\n");
		
		return 0;
	}
	
	bubbleSort();

	for (int i = 0; i < nameTableIdx; i++)
	{
		printf("%c", nameTable[i]);
	}
	printf("\n");


	return 0;
}