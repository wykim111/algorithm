#include<iostream>
#include<string>
#include<vector>
#include<cstring>

using namespace std;

vector<string> vt;
char cStr1[100];
char cStr2[100];

int GCM(int n1, int n2)
{
	if (n2 == 0)
	{
		return n1;
	}

	return GCM(n2, n1%n2);
}

int main()
{
	string str;
	char* token;
	int num1, num2;
	int divisored = 0;

	cin >> str;

	strcpy(cStr1, str.c_str());

	token = strtok(cStr1, ":");

	while ((token = strtok(NULL, ":")) != NULL)
	{
		strcpy(cStr2, token);
	}
//	printf("%s %s", cStr1, cStr2);

	num1 = atoi(cStr1);
	num2 = atoi(cStr2);


	divisored = GCM(num1, num2);

	//printf("%d\n", divisored);

	num1 = num1 / divisored;
	num2 = num2 / divisored;

	printf("%d:%d\n", num1, num2);

	return 0;
}
