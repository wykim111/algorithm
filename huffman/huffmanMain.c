#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "huffman.h"

#define MAX_SIZE 256

typedef struct _node
{
	char alphbet;
	int prequency;

	struct _node * left;
	struct _node * right;
}NODE;

int heapSize;
NODE* heapTable[MAX_SIZE];

void init();
void convLower(char* pStr,int size);
void calculateFrequency(char* pStr,int size,int* pAlphabetFrequnecy);

//PriorityQueue
void heapfipy(Node* root,int index);
void insert(Node* newNode);

int main()
{
	char str[100];
	int strLen = 0;
	int alphabetFrequency[26] = {0,};
	//init
	init(str,100);

	fgets(str,sizeof(str),stdin);
	
	//마지막 행에 개행이 있으므로 이 인덱스에 널을 삽입
	strLen = strlen(str);

	str[strLen-1] = '\0';

	strLen = strlen(str);

	//소문자로 변환
	convLower(str,strLen);
	//빈도 수 계산
	calculateFrequency(str,strLen,alphabetFrequency);

	/*
	printf("%s\n",str);

	for(int i=0;i<26;i++)
	{
		printf("alphbet : %c frequency :%d\n",i+'a',alphabetFrequency[i]);
	}
	*/
	
	
	return 0;
}


void init(char* pStr,int size)
{
	memset(pStr,0,size);
}

void convLower(char* pStr,int size)
{
	for(int i=0;i<size;i++)
	{
		if(pStr[i] >= 'A' && pStr[i] <= 'Z')
		{
			pStr[i] += 32;
		}
	}
}

void calculateFrequency(char* pStr,int size,int* pAlphabetFrequency)
{
	for(int i=0;i<size;i++)
	{
		pAlphabetFrequency[pStr[i] - 'a']++;
	}

}
