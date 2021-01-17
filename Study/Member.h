#pragma once
#ifndef __Member
#define __Member

/* ȸ�� ������*/
typedef struct {
	int no;
	char name[20];
}Member;

#define MEMBER_NO 1 //��ȣ�� ��Ÿ���� ��Ʈ �˻�
#define MEMBER_NAME 2 //�̸��� ��Ÿ���� ��Ʈ �˻�

/* ȸ�� ��ȣ �� �Լ� */
int MemberNoCmp(const Member* x, const Member* y);

/* ȸ�� �̸� �� �Լ� */
int MemberNameCmp(const Member* x, const Member* y);

/* ȸ�� �����͸�  ���(���� x) */
void PrintMember(const Member* x);

/* ȸ�� �����͸�  ���(���� o) */
void PrintLnMember(const Member* x);

/* ȸ�� �����͸� �о� ���� */
Member ScanMember(const char* message, int sw);
#endif