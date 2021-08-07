/*
	Trie알고리즘을 활용하여 tree 형태로 만들고, dfs 탐색
	- 같은 문자열인 경우 map을 활용하여 해당되는 키의 depth+1로 업데이트
*/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;

struct Tree
{
	map<string, Tree*> child;
	map<string, Tree*>::iterator iter;
	

	void insert(int dep, vector<string>& v)
	{
		if (dep == v.size())
		{
			return;
		}
		string temp_str = v[dep];

		iter = child.find(temp_str);
		//이미 단어가 존재하는 경우
		if (child.count(temp_str) != 0)
		{
			iter->second->insert(dep + 1, v);
		}
		else
		{
			Tree* newNode = new Tree();
			child.insert({temp_str,newNode});
			newNode->insert(dep + 1,v);

		}
	}
	void Print(int dep)
	{
		if (child.empty())
		{
			return;
		}
		for (auto it = child.begin(); it != child.end(); it++)
		{
			for (int i = 0; i < dep; i++)
			{
				cout << "--";
			}
			cout << it->first << '\n';
			it->second->Print(dep + 1);
		}
	}

};


int main()
{
	cin >> n;

	//root 생성
	Tree* root = new Tree();

	for (int i = 0; i < n; i++)
	{
		cin >> k;

		vector<string> vt;

		for (int j = 0; j < k; j++)
		{
			string str;

			cin >> str;
			vt.push_back(str);
		}

		//insert
		root->insert(0, vt);
	}

	root->Print(0);

	return 0;
}
