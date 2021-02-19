#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;


vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	int person = 0;
	int turn = 0;
	bool flag = false;
	map<string, int> mp;

	//제일 먼저 부른 단어 체크
	mp[words[0]] = 1;
	answer.push_back(0);
	answer.push_back(0);

	for (int i = 1; i < words.size(); i++)
	{
		//처음 나온 단어인 경우
		if (mp[words[i]] == 0)
		{
			char lastChar = words[i - 1][words[i - 1].length() - 1];

			//현재 나온 단어와 마지막 단어가 일치하지 않은 경우
			if (lastChar != words[i][0])
			{
				person = (i % n)+1;
				turn = (i / n) +1;
				flag = true;
				break;
			}
			else
			{
				mp[words[i]] = 1;

			}
		}
		else//이전에 나온 단어인 경우
		{
			person = (i % n) + 1;
			turn = (i / n) + 1;
			flag = true;
			break;
		}
	}

	if (flag == true)
	{
		answer[0] = person;
		answer[1] = turn;
	}

	return answer;
}

int main()
{
	vector<string>words;

	for (int i = 0; i < 9; i++)
	{
		string str;

		cin >> str;

		words.push_back(str);
	}

	solution(3, words);


	return 0;
}
