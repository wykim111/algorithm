#include<iostream>
#include<string>

using namespace std;

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		string str;
		int size = 0;
		int last_idx = 0;
		int num;
		cin >> str;

		size = str.length();

		num = str[size - 1] - '0';
		if (num % 2 == 0)
			printf("even\n");
		else
			printf("odd\n");

	}
	return 0;
}
