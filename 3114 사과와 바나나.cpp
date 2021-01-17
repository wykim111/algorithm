/*
https://dbdudrms95.blog.me/220979640431

*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAX 1500

using namespace std;

vector< vector<pair<char, int>>> map(MAX,vector<pair<char,int>>(MAX));
int R, C;



int main()
{
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			char ch;
			int num;
			
			scanf("%c %d", &ch, &num);
			
			map[i][j].first = ch;
			map[i][j].second = num;
		}
	}
}