#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int tc, n;

class Trie
{
private:
	bool endFlag;
	Trie* alphabet[10];
public:
	Trie() : endFlag(false)
	{
		memset(alphabet, 0, sizeof(alphabet));
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
		{
			if (alphabet[i])
				delete alphabet[i];
		}
	}

	void insert(const char* str)
	{
		if (*str == '\0')
		{
			endFlag = true;
		}
		else
		{
			int index = *str - '0';

			if (alphabet[index] == NULL)
			{
				alphabet[index] = new Trie();
			}
			alphabet[index]->insert(str + 1);
		}

	}

	bool find(const char* str)
	{
		if (*str == '\0')
		{
			return true;
		}

		int index = *str - '0';
		//endflag는 "911", "9112"와 같이  공통적인 문자열인 경우
		//"9112"의 "911"에서 endFlag가 이전에 true가 되었으니
		//중복됨을 의미한다.
		if (endFlag == true)
			return false;

		return alphabet[index]->find(str + 1);

	}
};


int main()
{
	cin >> tc;
	cin.ignore();

	while (tc--)
	{
		Trie* root = new Trie();
		
		cin >> n;
		cin.ignore();

		string str[10000];
		for(int i=0;i<n;i++)
		{
			getline(cin, str[i]);
			
			root->insert(str[i].c_str());

			
		
		}
		bool flag = true;
		//입력한 문자열중 공통적으로 겹치는 번호가 있는지 탐색
		for (int i = 0; i < n; i++)
		{
			if (root->find(str[i].c_str()) == false)
			{
				flag = false;
				break;
			}

		}

		if (flag == true)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}

		delete root;

	}
	return 0;
}
