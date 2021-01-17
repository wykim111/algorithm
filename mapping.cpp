#include<iostream>
#include<map>
#include<string>

using namespace std;

map<string, int> mp;
map<string, int> ::iterator iter;
int main()
{
	string str;

	cin >> str;

	mp.insert({ str, 0 });
	mp[str]++;

	iter = mp.begin();

	cout << iter->first << " " << iter->second << endl;

	return 0;
}