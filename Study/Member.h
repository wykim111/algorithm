#pragma once
#ifndef __Member
#define __Member

/* 회원 데이터*/
typedef struct {
	int no;
	char name[20];
}Member;

#define MEMBER_NO 1 //번호를 나타내는 비트 검사
#define MEMBER_NAME 2 //이름을 나타내는 비트 검사

/* 회원 번호 비교 함수 */
int MemberNoCmp(const Member* x, const Member* y);

/* 회원 이름 비교 함수 */
int MemberNameCmp(const Member* x, const Member* y);

/* 회원 데이터를  출력(개행 x) */
void PrintMember(const Member* x);

/* 회원 데이터를  출력(개행 o) */
void PrintLnMember(const Member* x);

/* 회원 데이터를 읽어 들임 */
Member ScanMember(const char* message, int sw);
#endif