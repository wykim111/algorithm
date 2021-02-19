/*
 이전에 선수 스킬을 배워야 현재스킬을 배울 수 있음
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


/*
	순서를 유지하면서 이전에 배웠던 기술인지 확인하는방법
	- 해당문자와 순서번호 저장
	
*/


int solution(string skill, vector<string> skill_trees) {
	
	map<char, int> mp;
	int answer = 0;
	
	//skill의 문자들을  map에 순서대로 저장
	for (int i = 0; i < skill.length(); i++)
	{
		mp[skill[i]] = i + 1;
	}

	for (string str : skill_trees)
	{
		int rank = 1;
		bool flag = true;

		//스킬트리의 기술들이 위의 순서대로 되어 있는지 체크
		for (int i = 0; i < str.length(); i++)
		{
			//rank가 현재 탐색하는 스킬보다 높은 경우
			//flag = false로 두고 탈출
			//이러면 선행스킬에 관련없는 문자도 처리가능
			if (mp[str[i]] > rank)
			{
				flag = false;
				break;
			}

			if (mp[str[i]] == rank)
			{
				rank++;
			}

		}
		if (flag == true)
			answer++;

	}




	return answer;
}

int main()
{
	vector<string> skill_trees;

	for (int i = 0; i < 4; i++)
	{
		string str;

		cin >> str;

		skill_trees.push_back(str);
	}
	cout << solution("CBD",skill_trees) << endl;

	return 0;
}
