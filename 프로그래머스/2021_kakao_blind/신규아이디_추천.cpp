/*
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
	 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/

#include<iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isCheck(char c)
{
	//알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_' || c == '.')
		return true;

	return false;
}

string solution(string new_id) {
	string answer = "";
	bool seqPoint = false; //마침표 연속/불연속 플래그

	for (int i = 0; i < new_id.length(); i++)
	{
		char ch = new_id.at(i);

		if (ch >= 'A' && ch <= 'Z')
		{
			ch = new_id.at(i) + 32;
		}

		if (isCheck(ch) == false)
		{
			continue;
		}
		//현재 인덱스가 마침표 데이터가 있는 경우 마침표 연속 플래그 true 설정
		//3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
		//4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다
		if (ch == '.')
		{
			if (answer.length() == 0 || seqPoint == true)
			{
				continue;
			}
			seqPoint = true;
		}
		else
		{
			seqPoint = false;;
		}

		answer.push_back(ch);
		

	}

	if (answer.length() == 0)
	{
		answer.push_back('a');
	}
	/*
	6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
	
	*/
	if (answer.length() >= 16)
	{
		for (int i = answer.length(); i > 15; i--)
		{
			answer.pop_back();
		}
	}
	if (answer.back() == '.')
	{
		answer.pop_back();
	}
	//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
	char lastCh = answer.back();

	while (answer.length() <= 2)
	{
		answer.push_back(lastCh);
	}


	return answer;
}


int main()
{
	string  str;

	cin >> str;

	cout << solution(str) << endl;

	return 0;
}
