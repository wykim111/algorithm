#include<iostream>
#include<string>
#include<algorithm>>
#include<map>
using namespace std;

map<string, int> mp;

int main()
{
	int cnt = 0;
	string str;

	while (cin >> str)
	{
		cnt++;

		mp[str]++;
	}

	printf("Re %d %.2f\n", mp["Re"],(double) mp["Re"] / cnt);
	printf("Pt %d %.2f\n", mp["Pt"], (double)mp["Pt"] / cnt);
	printf("Cc %d %.2f\n", mp["Cc"], (double)mp["Cc"] / cnt);
	printf("Ea %d %.2f\n", mp["Ea"], (double)mp["Ea"] / cnt);
	printf("Tb %d %.2f\n", mp["Tb"], (double)mp["Tb"] / cnt);
	printf("Cm %d %.2f\n", mp["Cm"], (double)mp["Cm"] / cnt);
	printf("Ex %d %.2f\n", mp["Ex"], (double)mp["Ex"] / cnt);
	
	printf("Total %d 1.00\n", cnt);
}