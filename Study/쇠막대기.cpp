/*
	1. '(' 만나면 push
	2. 문자열 '(' 다음에 ')'이 아니면 푸쉬
	3. 문자열 '(' 다음이 ')'이면 레이저 시작이므로 스택에 있던 사이즈 더함
	4. '('바로 다음이 ')'이면 탐색 i를 i++로 하여 건너 뜀
	5. 쇠막대기 끝을 만나면 answer + 1
*/
#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

int solution(string arrangement) {
	int answer = 0;
	stack<char> st;

	for (int i = 0; i < arrangement.size(); i++)
	{
		
		if (arrangement[i] == '(' && arrangement[i+1] == ')' && ((i+1) < arrangement.size()))//레이저 시작
		{
			i++;
			answer += st.size();
		}
		else if (arrangement[i] == '(' && arrangement[i + 1] != ')' && ((i + 1) < arrangement.size()))//쇠막대기 시작
		{
			st.push('(');

		}
		else if (arrangement[i] == ')')
		{
			st.pop();
			answer++;
		}
	}


	return answer;
}

int main()
{	
	cout << solution("()(((()())(())()))(())");

	return 0;
}
