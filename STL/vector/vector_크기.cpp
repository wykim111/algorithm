#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vt;

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

	cout << vt.size() << endl;
	cout << vt.capacity() << endl;
	cout << vt.max_size() << endl; //최대 저장 가능한 원소

	return 0;
}
