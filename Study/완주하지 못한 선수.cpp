#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;

map<string, int> mp;
vector<string>::iterator iter;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	//참가자들의 리스트를 맵에 저장
	for ( iter = participant.begin() ; iter != participant.end(); iter++)
	{
		mp[*iter]++;
	}

	//도착한 사람은 <키,값>에서 값이 0
	for (iter = completion.begin(); iter != completion.end(); iter++)
	{
		mp[*iter]--;
	}
	//완주하지 못한 사람
	//<키.값> 현재 상태 조회
	/*
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << i->first << " " << i->second << '\n';
	}
	*/
	//완주하지 못한 사람 명단 저장
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		if (i->second != 0)
		{
			answer = i->first;
		}
	}
	return answer;
}

int main()
{
	vector<string> p;
	vector<string> c;

	for (int i = 0; i < 3; i++)
	{
		string str;
		cin >> str;
		p.push_back(str);
	}
	for (int i = 0; i < 2; i++)
	{
		string str;
		cin >> str;
		c.push_back(str);
	}

	solution(p, c);
}
