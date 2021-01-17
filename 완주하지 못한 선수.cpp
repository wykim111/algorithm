#include <string>
#include <vector>
#include <map>
#include<iostream>

using namespace std;

map<string, int> mp;
vector<string>::iterator iter;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	//�����ڵ��� ����Ʈ�� �ʿ� ����
	for ( iter = participant.begin() ; iter != participant.end(); iter++)
	{
		mp[*iter]++;
	}

	//������ ����� <Ű,��>���� ���� 0
	for (iter = completion.begin(); iter != completion.end(); iter++)
	{
		mp[*iter]--;
	}
	//�������� ���� ���
	//<Ű.��> ���� ���� ��ȸ
	/*
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << i->first << " " << i->second << '\n';
	}
	*/
	//�������� ���� ��� ��� ����
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