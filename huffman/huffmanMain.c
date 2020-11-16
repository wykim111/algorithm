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

int heapSize = 0;
NODE* heapTable[MAX_SIZE];

void init();
void convLower(char* pStr, int size);
void calculateFrequency(char* pStr, int size, int* pAlphabetFrequnecy);

//string
char* wy_strdup(char* pStr);

//PriorityQueue
void heapfipy(int index);
void insert(NODE* newNode);
NODE* extractMin();

//Build huffman
NODE* buildHuffman();
void traverse(NODE* t);
void setEncode(char* encode[], char*tempEncode, int dep, NODE* curTree);




int main()
{
	char str[100];
	int strLen = 0;
	int alphabetFrequency[26] = { 0, };
	NODE* huffmanCode;
	char* encode[256],tempEncode[256];

	//init
	init(str, 100);
	memset(encode, 0, sizeof(encode));
	memset(tempEncode, 0, sizeof(tempEncode));

	fgets(str, sizeof(str), stdin);

	//마지막 행에 개행이 있으므로 이 인덱스에 널을 삽입
	strLen = strlen(str);

	str[strLen - 1] = '\0';

	strLen = strlen(str);

	//소문자로 변환
	convLower(str, strLen);
	//빈도 수 계산
	calculateFrequency(str, strLen, alphabetFrequency);

	/*
	printf("%s\n",str);
	for(int i=0;i<26;i++)
	{
		printf("alphbet : %c frequency :%d\n",i+'a',alphabetFrequency[i]);
	}
	*/
	
	huffmanCode = buildHuffman(alphabetFrequency);

	

	printf("heapSize = %d ,huffmancode %d\n",heapSize, huffmanCode->prequency);

	traverse(huffmanCode);
	setEncode(encode,tempEncode,0,huffmanCode);

	for (int i = 0; i < 26; i++)
	{
		if (encode[i] != NULL)
		{
			printf("%c %s\n", i + 'a', encode[i]);

		}
	}
	return 0;
}

char* wystrdup(char* pStr)
{
	char * newStr = (char*)malloc(strlen(pStr) + 1);

	if (newStr != NULL)
	{
		strcpy(newStr, pStr);
	}

	return newStr;
}


void init(char* pStr, int size)
{
	memset(pStr, 0, size);
}

void convLower(char* pStr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (pStr[i] >= 'A' && pStr[i] <= 'Z')
		{
			pStr[i] += 32;
		}
	}
}

void calculateFrequency(char* pStr, int size, int* pAlphabetFrequency)
{
	for (int i = 0; i < size; i++)
	{
		pAlphabetFrequency[pStr[i] - 'a']++;
	}

}

void heapfipy( int index)
{
	int smallest = index;
	int leftIdx = index * 2;
	int rightIdx = (index * 2) + 1;
	NODE * temp;

	if (leftIdx <= heapSize && heapTable[smallest]->prequency > heapTable[leftIdx]->prequency)
	{
		smallest = leftIdx;
	}

	if (rightIdx <= heapSize && heapTable[smallest]->prequency > heapTable[rightIdx]->prequency)
	{
		smallest = rightIdx;
	}

	if (smallest != index)
	{
		temp = heapTable[index];
		heapTable[index] = heapTable[smallest];
		heapTable[smallest] = temp;

		heapfipy(smallest);
	}
}


void insert(NODE* newNode)
{
	int curIdx;
	//사이즈를 증가시키고 2개 이상인 경우 현재 위치에서 2로 나누어 부모인덱스와 비교
	//새로운 노드가 더 작은 값이면 부모 값을 내림
	 heapSize++;
	 curIdx = heapSize;

	while (curIdx != 1 && newNode->prequency < heapTable[curIdx / 2]->prequency)
	{
		heapTable[curIdx] = heapTable[curIdx / 2];
		curIdx /= 2;
	}

	heapTable[curIdx] = newNode;
}

NODE* extractMin()
{
	NODE* remove;

	if (heapSize == 0)
	{
		return NULL;
	}

	remove = heapTable[1];

	heapTable[1] = heapTable[heapSize--];

	heapfipy(1);

	return remove;
}
/*
	우선순위 큐(힙a정렬)을 이용
	1. 최소 힙 데이터 삽입
	2. 루트에 위치한 가장 작은 노드와 그 다음으로 가장 작은 노드 추출
	3. 새 노드를 생성해성 이 2개의 노드를 더하여 저장

*/

NODE* buildHuffman(int * paramAlphabetFrequency)
{
	NODE* x, *y, *z;

	for (int i = 0; i < 26; i++)
	{
		if (paramAlphabetFrequency[i] > 0)
		{
			NODE* newNode = (NODE*)malloc(sizeof(NODE));

			newNode->alphbet = i + 'a';
			newNode->prequency = paramAlphabetFrequency[i];
			newNode->left = NULL;
			newNode->right = NULL;

			insert(newNode);
		}
	}

	for (int i = 1; i <= heapSize; i++)
	{
		printf(" %c %d\n", heapTable[i]->alphbet, heapTable[i]->prequency);
	}

	while (heapSize > 1)
	{
		x = extractMin();
		y = extractMin();

		z = (NODE*)malloc(sizeof(NODE));

		z->left = x;
		z->right = y;

		
		z->prequency = x->prequency + y->prequency;

		insert(z);
	}


	return extractMin();
}
//중위 순회
void traverse(NODE* t)
{
	if (t == NULL)
	{
		return;
	}

	traverse(t->left);
	printf("%s cnt = %d data %c\n",__FUNCTION__,t->prequency,t->alphbet);
	traverse(t->right);

}

void setEncode(char* encode[],char*tempEncode ,int dep, NODE* curTree)
{

	if (curTree->left == NULL && curTree->right == NULL)
	{
		char ch = curTree->alphbet;
		tempEncode[dep] = '\0';

		encode[ch -'a'] = wystrdup(tempEncode);
		
		return;
	}
	//왼쪽으로 이동
	tempEncode[dep] = '0';
	setEncode(encode, tempEncode,dep+1, curTree->left);

	//오른쪽으로 이동
	tempEncode[dep] = '1';
	setEncode(encode, tempEncode,dep+1, curTree->right);


}
