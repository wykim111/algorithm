/*
	- 곱하기와 나누기가 우선순위 높음
	-  더하기, 뺼셈은 곱하기 나누기 보다는 우선순위가 낮음
	- 스택에 현재 데이터보다 우선순위가 높은게 있는 경우 pop하여 연산하고
	  데이터  push
	- 스택에 현재 데이터보다 우선순위가 낮은 연산자가 있는 경우 현재 데이터  push


	1. 피연산자이면 스택에 push
	2. 연산자이면 피연산자 스택이면 2번 수행하여 연산한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;
stack<char> opStack;
stack<double> valStack;
double ret = 0;
double arr[26];

int main()
{
	int N;
	string postOp;
	
	cin >> N;
	
	cin >> postOp;

	//알파벳에 해당하는 정수 매칭
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}




	//후위표기를 중위표기로 바꿈
	for (int i = 0; i < postOp.size(); i++)
	{
		if (postOp[i] == '*' )
		{
			double num1 = valStack.top();
			valStack.pop();
			double num2 = valStack.top();
			valStack.pop();
			//주의!!! : 스택으로 뒤에 있는 원소가 LIFO가 되므로
			//num2가 먼저 위치
			double total = num2 * num1;

			

			valStack.push(total);

		}
		else if (postOp[i] == '/')
		{
			double num1 = valStack.top();
			valStack.pop();
			double num2 = valStack.top();
			valStack.pop();

			double total = num2 / num1;

		

			valStack.push(total);

		}
		else if (postOp[i] == '+')
		{
			double num1 = valStack.top();
			valStack.pop();
			double num2 = valStack.top();
			valStack.pop();
	
			double total = num2 + num1;

		

			valStack.push(total);

			
		}
		else if (postOp[i] == '-')
		{
			double num1 = valStack.top();
			valStack.pop();
			double num2 = valStack.top();
			valStack.pop();

			double total = num2 - num1;

			

			valStack.push(total);

		}
		else // 숫자
		{
			int index = postOp[i] - 'A';
			valStack.push(arr[index]);

		}

	}

	printf("%.2lf\n", valStack.top());

	return 0;
}
