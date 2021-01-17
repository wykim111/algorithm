#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

/* 해시 함수 */
static int hash(int key, int size)
{
	return key % size;
}
/* 노드의 각 멤버에 값을 설정*/
static void SetNode(Node* n, const Member* x, const Node* next)
{
	n->data = *x;
	n->next = next;
}
/* 해시 테이블 초기화 */
int Initialize(ChainHash* h, int size)
{
	if ((h->table = calloc(size, sizeof(Node*))) == NULL)
	{
		h->size = 0;
		return 0;
	}

	h->size = size;

	for (int i = 0; i < size; i++)
	{
		h->table[i] = NULL;
	}

	return 1;
}
/* 검색 */
Node* Search(const ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);//검색하고자 하는 데이터 no의 해시값
	Node* p = h->table[key];

	while (p != NULL)
	{
		//검색 성공 시
		if (p->data.no == x->no)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}
/*데이터 추가*/
int Add(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];
	Node* temp;

	while (p != NULL)
	{
		//이미 데이타의 no가 존재
		if (p->data.no == x->no)
			return 1;
		p = p->next;
	}
	if ((temp = calloc(1, sizeof(Node))) == NULL)
	{
		return 2;
	}

	SetNode(temp,x,h->table[key]);
	h->table[key] = temp;

	return 0;
}
/*데이터 삭제*/
int Remove(ChainHash* h, const Member* x)
{
	int key = hash(x->no, h->size);
	Node* p = h->table[key];
	Node** temp = &h->table[key];

	while (p != NULL)
	{
		//삭제할 데이터의 넘버를 찾은 경우
		if (p->data.no == x->no)
		{
			//삭제할 데이터 no의 다음 변수를 저장
			*temp = p->next;
			free(p);
			return 0; //삭제 성공
		}
		temp = &p->next;//싱글 포인터의 주소를 가르킴(temp는 더블 포인터 변수)
		p = p->next;
	}
	return 1;//삭제 실패
}
/*--- 해시 테이블 덤프 ---*/
void Dump(const ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];
		printf("%02d ", i);

		while (p != NULL) {
			printf("→ %d :(%s) ", p->data.no, p->data.name);
			p = p->next;
		}
		putchar('\n');
	}
}

/*--- 모든 데이터 삭제 ---*/
void Clear(ChainHash *h)
{
	int i;
	for (i = 0; i < h->size; i++) {
		Node *p = h->table[i];			/* 현재 선택한 노드 */

		while (p != NULL) {
			Node *next = p->next;
			free(p);					/* 현재 선택한 노드의 메모리 해제 */
			p = next;					/* 다음 노드 선택 */
		}
		h->table[i] = NULL;
	}
}

/*--- 해시 테이블 종료 ---*/
void Terminate(ChainHash *h)
{
	Clear(h);						/* 모든 데이터 삭제 */
	free(h->table);					/* 해시 테이블 배열의 메모리 해제 */
	h->size = 0;					/* 해시 테이블 크기를 0으로 초기화(clear) */
}