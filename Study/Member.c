#include<stdio.h>
#include<string.h>
#include "Member.h"


/* 회원 번호 비교 함수 */
int MemberNoCmp(const Member* x, const Member* y)
{
	return x->no > y->no;
}

/* 회원 이름 비교 함수 */
int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name, y->name);
}

/* 회원 데이터를  출력(개행 x) */
void PrintMember(const Member* x)
{
	printf("%d %s", x->no, x->name);
}

/* 회원 데이터를  출력(개행 o) */
void PrintLnMember(const Member* x)
{
	printf("%d %s\n", x->no, x->name);
}

/* 회원 데이터를 읽어 들임 */
Member ScanMember(const char* message, int sw)
{
	Member tempMember;

	printf("%s하는 데이터를 입력하세요\n", message);

	/*
	 MEMBER_NO는 1이므로 마지막 비트는 1이 되며
	 MEMBER_NAME은 2이므로 2번째 비트가 1이고 마지막 비트는 0이므로 
	 1~5까지 메뉴에서 선택할 때 4는 마지막 비트가 0이므로 아래 if문에 해당되지 않는다.
	*/
	if (sw & MEMBER_NO)
	{
		printf("번호: ");
		scanf("%d", &tempMember.no);
	}
	if (sw & MEMBER_NAME)
	{
		printf("이름: ");
		scanf("%s", tempMember.name);
	}

	return tempMember;
}
