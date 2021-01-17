#include<iostream>
using namespace std;
int main()
{
	int t;
	long long a, b;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", a / b * a / b);
	}
}