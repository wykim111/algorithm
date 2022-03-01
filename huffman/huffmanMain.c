#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include "huffman.h"

#define MAX_SIZE 1024
#define PRINT_HEAP_TABLE 1

typedef struct _node
{
	char alphbet;
	int prequency;

	struct _node * left;
	struct _node * right;
}NODE;

int heapSize = 0;
NODE* heapTable[MAX_SIZE];

// decode 변수
char decode[MAX_SIZE];
int decode_idx = 0;

//encode 변수
char encode[MAX_SIZE];


void init(char* pStr, int size);
void convLower(char* pStr, int size);
void calculateFrequency(char* pStr, int size, int* pAlphabetFrequnecy);

//string
char* wy_strdup(char* pStr);

//PriorityQueue
void heapify(int index);
void insert(NODE* newNode);
NODE* extractMin();

//Build huffman
NODE* buildHuffman(int * paramAlphabetFrequency);
void huffman_preorder(NODE* t);
void huffman_inorder(NODE* t);
void setencode_table(char* encode_table[], char*tempencode_table, int dep, NODE* curTree);

void write_huffman_code(char* str,char* encode_table[], FILE* fp_out);
void check_huff_table(char* encode_table[]);

//Decode func
void set_decode(NODE* root);

int main()
{
	FILE* in, *out;

	char str[100];
	int strLen = 0;
	int alphabetFrequency[26] = { 0, };
	NODE* huffmanCode;
	char* encode_table[256], tempencode_table[256];

	//init
	init(str, 100);
	memset(encode_table, 0, sizeof(encode_table));
	memset(tempencode_table, 0, sizeof(tempencode_table));


	in = fopen("D:\\input.txt", "r");
	out = fopen("D:\\output.txt", "w");

	fgets(str, sizeof(str), in);

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

	printf("heapSize = %d ,huffmancode %d\n", heapSize, huffmanCode->prequency);

	huffman_preorder(huffmanCode);


	setencode_table(encode_table, tempencode_table, 0, huffmanCode);

#if 0
	for (int i = 0; i < 26; i++)
	{
		if (encode_table[i] != NULL)
		{
			printf("%c %s\n", i + 'a', encode_table[i]);

		}
	}
#endif
	write_huffman_code(str,encode_table, out);
	//check_huff_table(encode_table);

	/*
		  Decode

	*/


	//out file을 읽음
	set_decode(huffmanCode);
	printf("decode -> %s\n",decode);



	return 0;
}

void set_decode(NODE* root)
{
	int str_len = strlen(encode);
	NODE* iter = root;
	printf("%s :%s\n", __FUNCTION__, encode);

	if (iter == NULL)
	{
		printf("no ref iter\n");
		return;
	}


	if (str_len == 0)
	{
		printf("no encode length\n");
		return;
	}

	for (int i = 0; i < str_len; i++)
	{
		if (encode[i] == '0')
		{
			iter = iter->left;
		}
		else if (encode[i] == '1')
		{
			iter = iter->right;
		}
		else
		{
			//skip
		}
		if ((iter->left == NULL) && (iter->right == NULL))
		{
			decode[decode_idx++] = iter->alphbet;
			iter = root;
		}
	}

	decode[decode_idx] = '\0';

}
void check_huff_table(char* encode_table[])
{

	for (int i = 0; i < 256; i++)
	{
		if (encode_table[i] != NULL)
		{
			printf("encode_table[%c] -> %s\n", i + 65, encode_table[i]);
		}
	}
}


void write_huffman_code(char* str,char* encode_table[], FILE* fp_out)
{
	int str_len = strlen(str);

	if (fp_out == NULL)
	{
		printf("fp_out Not Open error\n");
		exit(-1);
	}

	for (int i = 0; i < str_len; i++)
	{
		if (encode_table[str[i]-'a'] != NULL)
		{
			printf("encode_table[%c] -> %s\n", str[i], encode_table[str[i] - 'a']);
			fputs(encode_table[str[i] - 'a'], fp_out);
			strcat(encode, encode_table[str[i] - 'a']);
		}
	}

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

void heapify(int index)
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

		heapify(smallest);
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

	heapify(1);

	return remove;
}
/*
   우선순위 큐(힙 정렬)을 이용
   1. 최소 힙 데이터 삽입
   2. 루트에 위치한 가장 작은 노드와 그 다음으로 가장 작은 노드 추출
   3. 새 노드를 생성해서 이 2개의 노드를 더하여 저장

*/

NODE* buildHuffman(int * paramAlphabetFrequency)
{
	NODE* x, *y, *z;
	int size = 0;

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

#if PRINT_HEAP_TABLE
	printf("=====================start priority heap table====================\n");
	for (int i = 1; i <= heapSize; i++)
	{
		printf(" %c %d\n", heapTable[i]->alphbet, heapTable[i]->prequency);
	}
	printf("=====================end priority heap table====================\n");
#endif

	size = heapSize;

	while (size > 1)
	{
		x = extractMin();
		y = extractMin();

		printf("x=%c, %d\n", x->alphbet, x->prequency);
		printf("y=%c, %d\n", y->alphbet, y->prequency);

		z = (NODE*)malloc(sizeof(NODE));

		z->left = x;
		z->right = y;


		z->prequency = (x->prequency + y->prequency);

		insert(z);
		size--;
	}


	return extractMin();
}
//중위 순회
void huffman_ineorder(NODE* t)
{
	if (t == NULL)
	{
		return;
	}

	huffman_ineorder(t->left);
	printf("%s cnt = %d data %c\n", __FUNCTION__, t->prequency, t->alphbet);
	huffman_ineorder(t->right);

}
//전위 순회
void huffman_preorder(NODE* t)
{
	if (t == NULL)
	{
		return;
	}

	printf("%s cnt = %d data %c\n", __FUNCTION__, t->prequency, t->alphbet);
	huffman_preorder(t->left);
	huffman_preorder(t->right);

}

void setencode_table(char* encode_table[], char*tempencode_table, int dep, NODE* curTree)
{
	if (curTree->left == NULL && curTree->right == NULL)
	{
		char ch = curTree->alphbet;
		tempencode_table[dep] = '\0';

		encode_table[ch - 'a'] = wystrdup(tempencode_table);

		return;
	}
	//왼쪽으로 이동
	tempencode_table[dep] = '0';
	setencode_table(encode_table, tempencode_table, dep + 1, curTree->left);

	//오른쪽으로 이동
	tempencode_table[dep] = '1';
	setencode_table(encode_table, tempencode_table, dep + 1, curTree->right);

}
