/*
	공백을 구분하여 토큰을 기준으로 나누어 키와 값을 설정

	-> strtok가 아닌 sstream 헤더파일을 이용하여 stringstream 클래스 객체를
	   선언하여 문자열을 여기에 초기화 시킴
*/
#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>


using namespace std;

map<string, string> mp; // 키 : id 값 : nickname

vector<string> solution(vector<string> record) {
	vector<string> answer;
	
	for (vector<string>::iterator iter = record.begin(); iter != record.end(); iter++)
	{
		string id, nickname, cmd;
		//string tempStr = *iter;
		stringstream ss(*iter); //tokenize

		ss >> cmd;

		if (cmd.compare("Enter") == 0)
		{
			ss >> id >> nickname;

			mp[id] = nickname;
		}
		else if (cmd.compare("Change") == 0)
		{
			ss >> id >> nickname;

			mp[id] = nickname;
		}


	}
		
	for (vector<string>::iterator iter = record.begin(); iter != record.end(); iter++)
	{
		string id, nickname, cmd;
		//string tempStr = *iter;
		stringstream ss(*iter);

		ss >> cmd;

		if (cmd.compare("Enter") == 0)
		{
			ss >> id >> nickname;

			answer.push_back(mp[id] + "님이 들어왔습니다.");
		}
		else if (cmd.compare("Leave") == 0)
		{
			ss >> id;

			answer.push_back(mp[id] + "님이 나갔습니다.");
		}


	}


	return answer;
}


int main()
{
	string str;
	vector<string>vtStr;
	for (int i = 0; i < 1; i++)
	{
		getline(cin, str);
		//cout << str;
		vtStr.push_back(str);
	}
	solution(vtStr);

	return 0;
}
