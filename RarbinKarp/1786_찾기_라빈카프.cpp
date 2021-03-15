#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

ll powa[1000001];

ll a = 101;
ll p = 123456789;

string T, P;

vector<int> ret;

int main() {

	getline(cin, T);
	getline(cin, P);

	int len1 = T.size();
	int len2 = P.size();

	if (len1 < len2) {
		cout << 0 << '\n';
		return 0;
	}


	// a의 제곱값을 미리 구해놓음
	powa[0] = 1;
	for (int i = 1; i < P.size(); i++) {
		powa[i] = powa[i - 1] * a %p;
	}

	//각 문자열 자리에 대해 키를 연산
	//((str[i] + hash_Key) * 2^(문자열길이-1-i)) % p
	// 0번쨰 자리수에는 2의 제곱이 큰 수부터 작은수까지 

	ll T_Key = 0;
	ll P_Key = 0;



	for (int i = 0; i < P.size(); i++) {
		T_Key = (T_Key + T[i] * powa[P.size() - 1 - i]) % p;
		P_Key = (P_Key + P[i] * powa[P.size() - 1 - i]) % p;
	}

	if (T_Key == P_Key) ret.push_back(1);

	////T의 맨 앞 탐색이 끝나면 그 다음 2번째,3번째,T-P번째를 기준으로 탐색

	for (int i = 1; i <= (T.size() - P.size()); i++) {
		// //앞 글자 제외하고 뒤에  새로운 글자 1개 추가
		T_Key = (T_Key - T[i - 1] * powa[P.size() - 1]) % p;
		// 음수인경우 확인
		if (T_Key < 0) T_Key += p;
		T_Key = T_Key * a % p;
		T_Key = (T_Key + T[i + P.size() - 1]) % p;
		if (T_Key == P_Key) ret.push_back(i + 1);

	}

	printf("%d\n", ret.size());
	for (int i = 0; i < ret.size(); i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");

	return 0;
}
