#pragma once

#ifndef _ChainHash
#define _ChainHash

#include "Member.h"

/* 버킷을 나타내는 노드*/
typedef struct _node
{
	Member data;
	struct _node* next;
}Node;

/* 해시 테이블 */
typedef struct
{
	int size;
	Node** table;
}ChainHash;

/* 해시 테이블 초기화 */
int Initialize(ChainHash* h, int size);
/* 검색 */
Node* Search(const ChainHash* h, const Member* x);
/*데이터 추가*/
int Add(ChainHash* h, const Member* x);
/*데이터 삭제*/
int Remove(ChainHash* h, const Member* x);
/*해시 테이블 덤프*/
void Dump(const ChainHash* h);
/*모든 데이터 삭제*/
void Clear(const ChainHash* h);
/*해시테이블 종료*/
void Terminate(ChainHash* h);
#endif