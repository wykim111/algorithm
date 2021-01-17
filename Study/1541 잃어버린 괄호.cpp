/*
		1. ������ '-'�� ������ ��ū�� �������� �з��Ѵ�.
		2. ������ '-'������ �� ���ڿ��� ������ ���Ѵ�.
		3. ������ '-' ���� ������ ���ڿ����� ������ ���Ͽ� 2.���� ���� ���տ��� ���ش�.

		ex) TC 1 -> 55-50+40+10 = 55-(50 +40 +10) = -45 
		Tc 2 -> 55-10-20+30 =  55 -(10+20+30) = 55-10-(20+30) --> 2������ �����µ� �� ������ ���� �߰��� �ִ� ���� �� ���� 
		 
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
	//'-' �������� ��ū�� ����
	token = strtok(str, "-");
	strcpy(tokenTemp, token);
	//token�� '-'������ ���ڿ��� ����Ŵ
	token = strtok(NULL, "");
	//���� "-"������ ���ڿ��� ����
	ret = cal(tokenTemp);
	
	//���� '-'������ ���ڿ��� "+-" ������� ��� ���Ѵ�.
	if(token != NULL)
		ret -= cal(token);


	printf("%d\n", ret);

	return 0;
}