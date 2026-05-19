/*
	<이분 탐색>
	
	1. 1부터 50까지 차례대로 번호가 매겨진 50개의 봉투가 있음. 
	2. 토끼가 들어있는 봉투보다 작은 번호의 봉투를 고르면, 카드에 "더 높은 번호를 시도해보세요 (Try a higher number)"라고 적혀 있습니다.
	3. 토끼가 들어있는 봉투보다 큰 번호의 봉투를 고르면, 카드에 "더 낮은 번호를 시도해보세요 (Try a lower number)"라고 적혀 있습니다.
================================================================================================

	1. 1부터 50을 이분탐색 한다.
	2. target이 mid보다 작으면, end = mid - 1
	3. target이 mid보다 크면, start = mid + 1

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int target = 0;

void input()
{
	cin >> target;
}

void solution()
{
	vector<int> card_vt;

	int start = 1;
	int end = 50;

	while (start <= end)
	{
		int mid = ((start + end) / 2);

		if (target < mid)
		{
			card_vt.push_back(mid);
			end = mid - 1;

		}
		else if (target > mid)
		{
			card_vt.push_back(mid);
			start = mid + 1;
			
		}
		else // target == mid
		{
			card_vt.push_back(mid);
			break;
		}


	}

	for (int i = 0; i < card_vt.size(); i++)
	{
		cout << card_vt[i] << ' ';
	}
	cout << '\n';


}

int main()
{
	while (true)
	{
		input();

		if (target == 0)
		{
			break;
		}

		solution();
	}



	return 0;
}

