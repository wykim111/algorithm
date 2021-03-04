/*
	스택이 모두 비어 있으면 좋은단어
	- 같은 단어를 만나면 pop
	- 다른 단어를 만나면 .push
	- 사이즈를 검사하여 비어 있으면 추가


*/

#include<iostream>
#include<stack>
#include <string>
using namespace std;

int main()
{
	int N;
	int ret = 0;

	cin >> N;

	while (N--)
	{
		string str;
		stack<char> st;

		cin >> str;

		for (int i = 0; i < str.size(); i++)
		{
			//스택이 비워있으면 푸쉬
			if (st.empty() == true)
			{
				st.push(str[i]);
			}
			else
			{
				if (st.top() == str[i])
				{
					st.pop();
				}
				else
				{
					st.push(str[i]);
				}
			}
		}//for i

		if (st.empty() == true)
		{
			ret++;
		}


	}//while N

	cout << ret<<'\n';

	return 0;
}
