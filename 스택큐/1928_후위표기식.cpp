/*
	- 곱하기와 나누기가 우선순위 높음
	-  더하기, 뺼셈은 곱하기 나누기 보다는 우선순위가 낮음
	- 스택에 현재 데이터보다 우선순위가 높거나 같은게 있는 경우 pop하여 연산하고
	  데이터  push
	- 스택에 현재 데이터보다 우선순위가 낮은 연산자가 있는 경우 현재 데이터  push


	1. 피연산자이면 스택에 push
	2. 피연산자이면 연산자 스택에 2번 수행하여 연산한다.
	3. '(' 괄호의 경우 push
	4. ')'의 경우 '(' 나올 때가지 pop
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

stack <char> st;

int main()
{
	string str;
	string answer = "";

	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			st.push('(');
		}
		else if (str[i] == ')')
		{
			while (st.top() != '(' )
			{
				answer += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (str[i] == '*' || str[i] == '/')
		{
			//현재 스택 포인터가 가르키는 원소가 같은 우선순위에 있는 경우
			while (!st.empty()&& (st.top() == '*' || st.top() == '/'))
			{
				answer += st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			//'('를 만날 때까지 pop
			while (!st.empty() && (st.top() != '('))
			{
				answer += st.top();
				st.pop();
			}

			st.push(str[i]);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			answer += str[i];
		}
	}
	//스택에 남아있는 경우 모두 pop
	while (!st.empty())
	{
		answer += st.top();
		st.pop();
	}

	cout << answer;

	return 0;
}
