/*
	에라스토테네스의 체, 조합 활용
*/
#include<iostream>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int primeCnt = 0;
int primeTable[3001] = { 1,1,0 };
int pick[3];

void prime()
{
	for (int i = 2; i <= sqrt(3000); i++)
	{
		for (int j = 2; i*j <= 3000; j++)
		{
			primeTable[i*j] = 1;//1 이면 소수가 아님
		}
	}
}




void comb(vector<int>nums, int dep, int idx)
{
	if (dep == 3)
	{
		int sum = 0;
		for (int i = 0; i < 3; i++)
		{
			//cout << pick[i] << " ";
			sum += pick[i];
		}
		//cout << endl;

		if (primeTable[sum] == 0)
		{
			primeCnt++;
		}

		return;
	}


	for (int i = idx; i < nums.size(); i++)
	{
		pick[dep] = nums[i];
		comb(nums, dep + 1, i + 1);

	}

}


int solution(vector<int> nums) {
	int answer = -1;

	prime();
	comb(nums, 0, 0);

	answer = primeCnt;

	return answer;
}

int main()
{
	vector<int> nums;
	vector<int> ret;

	for (int i = 0; i < 5; i++)
	{
		int n;
		cin >> n;

		nums.push_back(n);
	}

	printf("%d\n",solution(nums));

	

	return 0;
}
