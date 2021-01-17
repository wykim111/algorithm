/*
		1. 최초의 '-'가 나오는 토큰을 기준으로 분류한다.
		2. 최초의 '-'나오기 전 문자열의 총합을 구한다.
		3. 최초의 '-' 나온 이후의 문자열들의 총합을 구하여 2.에서 구한 총합에서 뺴준다.

		ex) TC 1 -> 55-50+40+10 = 55-(50 +40 +10) = -45 
		Tc 2 -> 55-10-20+30 =  55 -(10+20+30) = 55-10-(20+30) --> 2가지가 나오는데 더 간단히 보면 중간에 있는 항이 더 심플 
		 
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
char str[51];
char* token;
char tokenTemp[51];

//
int cal(char* str)
{
	int sum = 0;
	char* s = strtok(str, "+-");

	sum += atoi(s);

	while (s = strtok(NULL, "+-"))
	{
		sum += atoi(s);
	}

	return sum;
}

int main()
{
	int ret;

	scanf("%s", str);
	//'-' 기준으로 토큰을 나눔
	token = strtok(str, "-");
	strcpy(tokenTemp, token);
	//token은 '-'이후의 문자열을 가르킴
	token = strtok(NULL, "");
	//최초 "-"이전의 문자열을 구함
	ret = cal(tokenTemp);
	
	//최초 '-'이후의 문자열은 "+-" 상관없이 모두 더한다.
	if(token != NULL)
		ret -= cal(token);


	printf("%d\n", ret);

	return 0;
}