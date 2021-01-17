#include <string>
#include <vector>

using namespace std;
int visit[200];

int dfs(int idx, vector<vector<int>>& computers,int n) 
{
	visit[idx] = 1;
	int answer = 0;


	for (int i = 0; i < n; i++)
	{
		if (!visit[i] && computers[idx][i])
		{
			dfs(i, computers, n);
		}
	}
	return answer;
}


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;


	for (int i = 0; i < n; i++)
	{
		
		if (!visit[i])
		{
			answer++;
			dfs(i, computers, n);
		}
		
	}
	return answer;
}


