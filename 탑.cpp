/*
1.���� �ڱ� �����ͺ��� ū �����Ͱ� ������ �ش� ������+1�� �Ͽ� �ڱ� �ڽ��� �ε����� ����
1-1. �׸��� flag�� üũ�ϰ� break
2.���� ������ ������ 0�� �Ǿ�� ��
*/
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> solution(vector<int> heights) {
	vector<int> answer;
	bool flag;

	for (int i = heights.size() - 1; i >= 0; i--)
	{
		flag = false;
		for (int j = i - 1; j >= 0; j--)
		{
			if (heights[i] < heights[j])
			{
				answer.push_back(j+1);
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			answer.push_back(0);
		}
	}
	reverse(answer.begin(), answer.end());

	return answer;
}