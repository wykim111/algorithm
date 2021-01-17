#include<iostream>


using namespace std;

int main()
{
	string str;
	int T;
	int Case = 1;
	scanf("%d", &T);

	while (T--)
	{
		int num1,num2;
		char op,equal;
		int res;

		scanf("%d %c %d %c %d", &num1, &op, &num2, &equal, &res);

		if ((op == '+' && (res == (num1 + num2))) || (op == '-' && (res == (num1 - num2))))
		{
			printf("Case %d: YES\n",Case);
		}
		else
		{
			printf("Case %d: NO\n",Case);
		}
		Case++;
	}
	return 0;

}
