#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter = dq.begin();

	cout << dq[0] << endl;
	cout << dq[1] << endl;
	cout << dq[2] << endl;
	cout << dq[3] << endl;
	cout << dq[4] << endl;

	iter += 2;
	cout << *iter << endl;
	cout << endl;

	deque<int>::iterator iter2 = iter+2;
	cout << *iter2 << endl;


	return 0;
}