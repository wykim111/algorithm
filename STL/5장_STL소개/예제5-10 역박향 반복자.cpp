#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;
	
	/*
	//������ �ݺ��� ȣ�� 1
	reverse_iterator<vector<int>::iterator> riter(v.end());
	reverse_iterator<vector<int>::iterator> end_riter(v.begin());
	*/
	//������ �ݺ��� ȣ�� 2
	vector<int>::reverse_iterator riter(v.rbegin());
	for (; riter != v.rend(); riter++)
	{
		cout << *riter << " ";
	}
	cout << endl;

	/*
	for (; riter != end_riter; riter++)
	{
		cout << *riter << " ";
	}
	cout << endl;
	*/

	return 0;
}