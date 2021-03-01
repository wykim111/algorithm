#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int> vt1(5); //0으로 초기화, size가 5인 컨테이너

	vt1.push_back(10);
	vt1.push_back(20);
	vt1.push_back(30);
	vt1.push_back(40);
	vt1.push_back(50);

	for (vector<int>::size_type i = 0; i < vt1.size(); i++)
	{
		cout << vt1[i] << " ";
	}
	cout << endl;

	vector<int> vt2(5); //0으로 초기화, size가 5인 컨테이너
	vt2[0] = 10;//0에서 10으로 수정
	vt2[1] = 20;//0에서 20으로 수정
	vt2[2] = 30;//0에서 30으로 수정
	vt2[3] = 40;//0에서 40으로 수정
	vt2[4] = 50;//0에서 50으로 수정

	for (vector<int>::size_type i = 0; i < vt2.size(); i++)
	{
		cout << vt2[i] << " ";
	}
	cout << endl;


	return 0;
}
