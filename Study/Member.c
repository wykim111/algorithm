#include<stdio.h>
#include<string.h>
#include "Member.h"


/* ȸ�� ��ȣ �� �Լ� */
int MemberNoCmp(const Member* x, const Member* y)
{
	return x->no > y->no;
}

/* ȸ�� �̸� �� �Լ� */
int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

/* ȸ�� �����͸�  ���(���� x) */
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}

/* ȸ�� �����͸�  ���(���� o) */
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}

/* ȸ�� �����͸� �о� ���� */
Member ScanMember(const char* message, int sw)
{
	Member tempMember;

	printf("%s�ϴ� �����͸� �Է��ϼ���\n", message);

	/*
	 MEMBER_NO�� 1�̹Ƿ� ������ ��Ʈ�� 1�� �Ǹ�
	 MEMBER_NAME�� 2�̹Ƿ� 2��° ��Ʈ�� 1�̰� ������ ��Ʈ�� 0�̹Ƿ� 
	 1~5���� �޴����� ������ �� 4�� ������ ��Ʈ�� 0�̹Ƿ� �Ʒ� if���� �ش���� �ʴ´�.
	*/
	if (sw & MEMBER_NO)
	{
		printf("��ȣ: ");
		scanf("%d", &tempMember.no);
	}
	if (sw & MEMBER_NAME)
	{
		printf("�̸�: ");
		scanf("%s", tempMember.name);
	}

	return tempMember;
}
