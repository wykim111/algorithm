#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const int& p1, const int& p2)
{
	//��������
	return (p1 > p2);
}

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;

	//��������
	sort(A.begin(), A.end());
	//��������
	sort(B.begin(), B.end(), cmp);


	for (int i = 0; i < A.size(); i++)
	{
		answer += (A[i] * B[i]);
	}

	return answer;
}