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


	vector<int>::iterator iter = vt.begin(); //시작원소를 가르킴
	cout << *iter << endl;

	iter += 2;//현재 위치에서 2칸 이동
	cout << *iter << endl;

	iter -= 1;//현재 위치에서 1칸  반대로 이동
	cout << *iter << endl;


	return 0;
}
