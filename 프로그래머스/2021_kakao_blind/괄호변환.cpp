#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int pos = 0;

bool isCheck(string str)
{
	stack<char> st;
	int openCnt = 0, closeCnt = 0;//여는 괄호, 닫는 괄호 카운트
	int flag = true;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			openCnt++;
			st.push('(');
		}
		else
		{
			closeCnt++;

			if (st.empty() == 1)
			{
				flag = false;
			}
			else
			{
				st.pop();
			}
		
		}
		//여는괄호와 닫힌괄호가 탐색하면서  처음 균형잡힌  문자열을 찾고
		//그  다음  인덱스를 저장
		//왜냐하면 그 다음 인덱스는 균형잡힌 문자열 다음 문자열이기 떄문
		if (openCnt == closeCnt)
		{
			pos = i + 1;
			
			return flag;
		}
	}

	return flag;
}

string solution(string p) {

	/*
		v의 경우 1단계부터 다시 시행하므로 재귀 수행
	    v는 균형잡힌 문자열은 어디까지 균형잡힌 문자열인지 인덱스를 기준으로
		나타내므로 비워져있을 때까지 수행
	*/
	if (p.empty())
	{
		return p;
	}

	bool flag = 0;

	flag = isCheck(p);
	/*
	1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
	2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
	단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
	
	*/
	string u = p.substr(0, pos);
	string v = p.substr(pos, p.length() - pos);

	/*
	3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다. 
	3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
	*/
	if (flag == true)
	{
		return u + solution(v);
	}

	/*
	4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
	  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
	  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
	  4-3. ')'를 다시 붙입니다. 
	  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다. 
	  4-5. 생성된 문자열을 반환합니다.
	
	*/

	string answer = "(" + solution(v) +")";


	for (int i = 1; i < u.length()-1; i++)
	{
		if (u[i] == '(')
		{
			answer += ")";
		}
		else
		{
			answer += "(";
		}
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
