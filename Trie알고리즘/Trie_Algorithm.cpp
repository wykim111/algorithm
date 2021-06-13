#include<iostream>
#include<string>

using namespace std;

class Trie
{
private:
	bool endFlag;
	Trie* alphabet[26];
public:
	Trie() : endFlag(false)
	{
		memset(alphabet, 0, sizeof(alphabet));
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
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
			int index = *str - 'a';

			if (alphabet[index]== NULL)
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
			return 1;
		}
	
		int index = *str - 'a';

		if (alphabet[index] == NULL)
			return 0;

		return alphabet[index]->find(str + 1);

	}
};


int main()
{
	Trie* root = new Trie;

	root->insert("apple");
;

	
		if ((root->find("apple")) == 1)
		{
			cout <<"ok"<< endl;
		}
		else
		{
			cout << "no" << endl;
		}

		if ((root->find("ap")) == 1)
		{
			cout << "ok" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

		return 0;
}
