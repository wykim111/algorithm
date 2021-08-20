#include <iostream>
#include <string>

using namespace std;

int pos = 0;

string convert_num(string& s)
{
	string number = "";
	int size = 0;

	if (s[pos] == 'o')
	{
		number = s.substr(pos, 3);

		if (number.compare("one") == 0)
		{
			number = "1";
			pos += 3;
			return number;
		}
	}
	else if (s[pos] == 't')
	{
		number = s.substr(pos, 3);

		if (number.compare("two") == 0)
		{
			number = "2";
			pos += 3;
			return number;
		}
		number = s.substr(pos, 5);
		if(number.compare("three") == 0)
		{
			number = "3";
			pos += 5;
			return number;
		}
	}
	else if (s[pos] == 'f')
	{
		number = s.substr(pos, 4);
		if (number.compare("four") == 0)
		{
			number = "4";
			pos += 4;
			return number;
		}
		
		if (number.compare("five") == 0)
		{
			number = "5";
			pos += 4;
			return number;
		}
	}
	else if (s[pos] == 's')
	{
		number = s.substr(pos, 3);
		if (number.compare("six") == 0)
		{
			number = "6";
			pos += 3;
			return number;
		}
		number = s.substr(pos, 5);
		if (number.compare("seven") == 0)
		{
			number = "7";
			pos += 5;
			return number;
		}
	}
	else if (s[pos] == 'e')
	{
		number = s.substr(pos, 5);
		if (number.compare("eight") == 0)
		{
			number = "8";
			pos += 5;
			return number;
		}
	}
	else if (s[pos] == 'n')
	{
		number = s.substr(pos, 4);
		if (number.compare("nine") == 0)
		{
			number = "9";
			pos += 4;
			return number;
		}
	}
	else if (s[pos] == 'z')
	{
		number = s.substr(pos, 4);
		if (number.compare("zero") == 0)
		{
			number = "0";
			pos += 4;
			return number;
		}
	}

	return number;
}
int solution(string s)
{
	int answer = 0;
	int strLen = s.length();
	string temp = "";

	for (pos = 0; pos < strLen; pos++)
	{
		if (s[pos] >= '0' && s[pos] <= '9')
		{
			temp += s[pos];
		}
		else if (s[pos] >= 'a' && s[pos] <= 'z')
		{
			string num = "";

			num = convert_num(s);
			pos--;//for문에서 pos++을 수행하므로 미리 1만큼 감소
			temp += num;
		}


	}
	//cout << temp << '\n';
	answer = atoi(temp.c_str());


	return answer;
}
int main()
{
	string str;

	cin >> str;

	solution(str);

	return 0;
}
