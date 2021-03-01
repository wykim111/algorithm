#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vt;

	vt.push_back(10);
	vt.push_back(20);
	vt.push_back(30);
	vt.push_back(40);
	vt.push_back(50);

	vector<int>::iterator iter;

	for (iter = vt.begin(); iter != vt.end(); iter++)
	{
		cout << *iter << endl;
	}

	return 0;
}
