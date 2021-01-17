/*
	1. '(' ������ push
	2. ���ڿ� '(' ������ ')'�� �ƴϸ� Ǫ��
	3. ���ڿ� '(' ������ ')'�̸� ������ �����̹Ƿ� ���ÿ� �ִ� ������ ����
	4. '('�ٷ� ������ ')'�̸� Ž�� i�� i++�� �Ͽ� �ǳ� ��
	5. �踷��� ���� ������ answer + 1
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
		
		if (arrangement[i] == '(' && arrangement[i+1] == ')' && ((i+1) < arrangement.size()))//������ ����
		{
			i++;
			answer += st.size();
		}
		else if (arrangement[i] == '(' && arrangement[i + 1] != ')' && ((i + 1) < arrangement.size()))//�踷��� ����
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