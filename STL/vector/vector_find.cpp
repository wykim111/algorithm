#include<iostream>
#include<vector>
#include<algorithm>//find 사용

using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	iter = find(v.begin(), v.end(), 20);
	cout << *iter << endl;

	iter = find(v.begin(), v.end(), 100);

	if (iter == v.end())// false인 경우 iter == v.end()
	{
		cout << "100이 없음" << endl;
	}

	return 0;
}
