/*
https://kyc0517.tistory.com/10

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int arr[1000];
int cache[1000];
int lis(int n) {
	int& ret = cache[n];
	if (n == 0) return ret = 1;
	if (ret != -1) return ret;

	ret = 0;
	int m = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[n] < arr[i])
			m = max(lis(i), m);
	}
	return ret = m + 1;

}
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
		cache[i] = -1;
	}
	int result = 1;
	for (int i = N - 1; i >= 0; i--) {
		result = max(lis(i), result);
	}

	printf("%d\n", result);

}