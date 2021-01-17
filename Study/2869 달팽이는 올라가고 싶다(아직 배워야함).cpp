/*
	https://jaimemin.tistory.com/548 에서 가져옴
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

		//하루 움직이는 거리: (올라가는 길이 - 미끄러지는 길이)

		//마지막 날에는 올라가기만 한다

		if (V <= totalDay * (A - B) + A)

		{

			//마지막 날까지 고려하므로 totalDay + 1

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