/*
	- ','를 기준으로 문자열을 split
	- 토큰으로 나눈 데이터가 정수인 경우 카운트

*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream> //getline 함수 호출
#include<vector>

using namespace std;

int main()
{
	string str;
	char copy[101];
	vector<char*>vt;
	int cnt = 0, len = 0;

	memset(copy, 0, sizeof(copy));

	getline(cin, str);
	//cin.ignore();//버퍼 지움
	len = str.length();
	memcpy(copy, str.c_str(), len);

	char* token = strtok(copy, ",");

	vt.push_back(token);
	//printf("%s\n", token);
	while (token = strtok(NULL,","))
	{
	//	printf("%s\n", token);
		vt.push_back(token);
	}

	for (int i = 0; i < vt.size(); i++)
	{
		if (atoi(vt[i]))
		{
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}
