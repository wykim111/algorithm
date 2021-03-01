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


	vector<int>::iterator iter1;
	vector<int>::iterator iter2;

	for (iter1 = vt.begin(); iter1 != vt.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;

	iter1 = vt.begin() + 2;//vt 시작지점에서 +2 지점을 iter1이 가르킴
	iter2 = vt.erase(iter1);//iter1이 가르키는 pos 제거

	for (iter1 = vt.begin(); iter1 != vt.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;

	iter2 = vt.erase(vt.begin() + 1, vt.end());//현재 pos의 +1 부분부터 끝까지 제거

	for (iter1 = vt.begin(); iter1 != vt.end(); iter1++)
	{
		cout << *iter1 << " ";
	}
	cout << endl;


	return 0;
}
