#pragma once

#ifndef _ChainHash
#define _ChainHash

#include "Member.h"

/* ��Ŷ�� ��Ÿ���� ���*/
typedef struct _node
{
	Member data;
	struct _node* next;
}Node;

/* �ؽ� ���̺� */
typedef struct
{
	int size;
	Node** table;
}ChainHash;

/* �ؽ� ���̺� �ʱ�ȭ */
int Initialize(ChainHash* h, int size);
/* �˻� */
Node* Search(const ChainHash* h, const Member* x);
/*������ �߰�*/
int Add(ChainHash* h, const Member* x);
/*������ ����*/
int Remove(ChainHash* h, const Member* x);
/*�ؽ� ���̺� ����*/
void Dump(const ChainHash* h);
/*��� ������ ����*/
void Clear(const ChainHash* h);
/*�ؽ����̺� ����*/
void Terminate(ChainHash* h);
#endif