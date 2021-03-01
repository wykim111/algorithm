#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>vt;

	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	vt.push_back(40);
	vt.push_back(50);


	for (vector<int>::size_type i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << " ";
	}
	cout << endl;

	vt.front() = 100;//첫번째 원소 100으로 저장
	vt.back() = 500;//마지막 원소 500으로 저장

	for (vector<int>::size_type i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << " ";
	}
	cout << endl;


	return 0;
}
