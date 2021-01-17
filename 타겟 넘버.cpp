#include <string>
#include <vector>
#include<iostream>
using namespace std;

int dfs(vector<int> numbers, int target, int idx, int sum)
{
	if (idx == numbers.size() && sum == target)
		return 1;

	if (idx == numbers.size() && sum != target)
		return 0;
	//+�� ������ ���� -�� ������ ���� ������ target�� �����ϴ� ��츦 Ž���Ѵ�.
	return dfs(numbers, target, idx + 1, sum + numbers[idx]) + dfs(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
	int answer = dfs(numbers, target, 0, 0);
	return answer;
}

int main()
{
	vector<int> vt;
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		vt.push_back(num);
	}
	cout << solution(vt, 3) << endl;

	return 0;
}