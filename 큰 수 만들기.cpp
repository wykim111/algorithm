#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = number;
	string buffer = "";
	int i;
	while (k > 0)
	{
		if (buffer.size() == number.size() - k)
			return buffer;

		for (i = 1; i <= k; i++)
		{
			if (answer[0] < answer[i])
				break;
		}
		if (i == k + 1)
		{
			buffer += answer[0];
			answer.erase(0, 1);
		}
		else
		{
			answer = answer.substr(i);
			k -= i;
		}

	}

	return buffer + answer;
}