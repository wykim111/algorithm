/*
1.현재 자기 데이터보다 큰 데이터가 있으면 해당 데이터+1을 하여 자기 자신의 인덱스에 저장
1-1. 그리고 flag로 체크하고 break
2.가장 좌측은 무조건 0이 되어야 함
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
