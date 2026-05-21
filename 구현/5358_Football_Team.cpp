/*
	< 구현 >

	1. 문자 치환
		1-1. 모든 소문자 'i'는 'e'로 변경
		1-2. 모든 소문자 'e'는 'i'로 변경
		1-3. 모든 대문자 'I'는 'E'로 변경
		1-4. 모든 대문자 'E'는 'I'로 변경
		1-5. 그 외의 다른 문자(공백 포함)는 그대로 유지합니다.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string name_str;

int main()
{
	while (getline(cin, name_str))
	{
		for (int i = 0; i < name_str.size(); i++)
		{
			if (name_str[i] == 'i')
			{
				name_str[i] = 'e';
			}
			else if (name_str[i] == 'e')
			{
				name_str[i] = 'i';
			}
			else if (name_str[i] == 'I')
			{
				name_str[i] = 'E';
			}
			else if (name_str[i] == 'E')
			{
				name_str[i] = 'I';
			}

		}

		cout << name_str << '\n';
	}

	return 0;
}