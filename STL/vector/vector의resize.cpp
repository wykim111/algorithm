#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vt(5); //기본값 0으로 초기화 된 size가 5인 컨테이너

	vt[0] = 10;
	vt[1] = 20;
	vt[2] = 30;
	vt[3] = 40;
	vt[4] = 50;

	for (vector<int>::size_type i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << " ";
	}
	cout << endl;

	cout << "size : " << vt.size() << " capacity: " << vt.capacity() << endl;
	
	////////////////////////////////////////////////////////////////////////
	vt.resize(10);//기본값 0으로 초기화 된 size가 10인 컨테이너
	
	for (vector<int>::size_type i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << " ";
	}
	cout << endl;

	cout << "size : " << vt.size() << " capacity: " << vt.capacity() << endl;

	////////////////////////////////////////////////////////////////////////
	
	vt.resize(5);//기본값 0으로 초기화 된 size가 10인 컨테이너

	for (vector<int>::size_type i = 0; i < vt.size(); i++)
	{
		cout << vt[i] << " ";
	}
	cout << endl;

	cout << "size : " << vt.size() << " capacity: " << vt.capacity() << endl;



	return 0;
}
