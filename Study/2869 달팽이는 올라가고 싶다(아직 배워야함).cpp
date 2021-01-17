/*
	https://jaimemin.tistory.com/548 ���� ������
*/
#include <iostream>

#include <algorithm>

using namespace std;



const int INF = 1000000000 + 1;



int A, B, V;



long long binarySearch(void)

{

	long long left = 0, right = V / (A - B) + 1;

	long long totalDay;

	long long result = INF;



	while (left <= right)

	{

		totalDay = (left + right) / 2;

		//�Ϸ� �����̴� �Ÿ�: (�ö󰡴� ���� - �̲������� ����)

		//������ ������ �ö󰡱⸸ �Ѵ�

		if (V <= totalDay * (A - B) + A)

		{

			//������ ������ ����ϹǷ� totalDay + 1

			result = min(result, totalDay + 1);

			right = totalDay - 1;

		}

		else

			left = totalDay + 1;

	}



	return result;

}



int main(void)

{

	cin >> A >> B >> V;



	cout << binarySearch() << endl;

	return 0;

}