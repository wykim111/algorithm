#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;

string FA(string s)
{
	string temp;
	int len = s.size();

	temp = ((s[0] - '0') * len) + '0';

	return temp;
}

int main()
{
	string str;
	int ret = 0;
	getline(cin, str);

	while(1)
	{
		if (str.size() == 1)
			break;
		str = FA(str);
	}
	if (str.size() == 1)
	{
		cout << "FA"<<'\n';
	}
	else
	{
		cout << "NFA" << '\n';
	}
	return 0;
}
