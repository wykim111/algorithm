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

	for (int i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << endl;
	}

	return 0;
}
