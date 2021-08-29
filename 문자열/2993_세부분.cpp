/* 20210829
	1) 이중 반복문으로 3부분으로 나눈다.
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{

		}
	}
	2) 오름차순 즉 제일 작은 문자열을  구한다.
*/
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string str;
string ret_str;
int main()
{
	int len = 0;

	cin >> str;

	len = str.length();
	ret_str = 'z';
	for (int i = 0; i < len - 2; i++)
	{
		for (int j = i + 1; j < len - 1; j++)
		{
			string temp = str;

			reverse(temp.begin(),temp.begin()+(i+1));
			reverse(temp.begin()+(i+1), temp.begin() + (j + 1));
			reverse(temp.begin()+(j+1), temp.end());

			ret_str = min(ret_str, temp);
		}
	}
	cout << ret_str << '\n';

	return 0;
}
