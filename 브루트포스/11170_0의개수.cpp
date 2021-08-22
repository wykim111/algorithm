/*
	1.숫자를 문자열로 변환
	2. '0'의 갯수 카운트
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>

using namespace std;
int T;

int zero_count(string& s)
{
	int strLen = s.length();
	int zero_cnt = 0;

	for (int i = 0; i < strLen; i++)
	{
		if (s.at(i) == '0')
		{
			zero_cnt++;
		}
	}
	return zero_cnt;
}

int main()
{
	cin >> T;
	
	while (T--)
	{
		int N, M;

		cin >> N >> M;

		int zero_sum = 0;

		for (int i = N; i <= M; i++)
		{
			string str = to_string(i);
		//	cout << "str = " << str << '\n';
			zero_sum += zero_count(str);

		}
		cout << zero_sum<<'\n';
	}

	return 0;
}
