/*
	순열, 백트래킹

	+ 입력한 임의의 좌표(y,x) 선택
	+ 
	+ 문자열의 길이만큼 탐색

		go(dep)
		{
			if(dep == 길이 끝까지 간 경우)
			{
				if(sum == N)
					cnt++;

				return;
			}

			for(int i= 0; i < N;i++)
			{
				for(int j=0;j<M;j++)
				{
					if(visit[i][j] == 1)
					{
						continue;

					}

					if(인접한 부분에 순열로 뽑은 좌표가 존재한다면)
						continue

					visit[i][j] = 1;
					perm.push_back(make_pair(i,j));

					go(dep+1);

					visit[i][j] = 0;
					perm.pop_back();
				}
			}
		}


*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

#define xDEBUG_MODE 

using namespace std;

int N, M, K;
int str_len = 0;
int visit[10][10];

#ifdef DEBUG_MODE
int answer = 0;
#else
int answer = -987654321;
#endif

int map[10][10];
vector<pair<int,int>> perm;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

void input()
{
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

bool is_adjcent(int curY,int curX)
{
	//printf("is_adjcent :: curY = %d, curX = %d\n", curY, curX);

	for (int i = 0; i < 4; i++)
	{
		int nextY = curY + dy[i];
		int nextX = curX + dx[i];

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M)
		{
			continue;
		}
		
		if (visit[nextY][nextX] == 1)
		{
			return true;
		}


	}
	
	return false;
}

int cal()
{
	int sum = 0;

	for (int i = 0; i < perm.size(); i++)
	{
		int pos_y = perm[i].first;
		int pos_x = perm[i].second;

		sum += map[pos_y][pos_x];
	}

	return sum;
}

void go(int dep)
{
	if (dep == K)
	{
		bool flag = false;

#if 0
		cout << "<perm>" << '\n';
		for (int i = 0; i < perm.size(); i++)
		{
			cout << perm[i].first << "  " << perm[i].second << '\n';
		}
#endif
#ifdef DEBUG_MODE
		answer++; //모든 순열 경우의 수

		for (int i = 0; i < perm.size(); i++)
		{
			if (is_adjcent(perm[i].first, perm[i].second) == false)
			{
				for (int j = 0; j < perm.size(); j++)
				{
					cout << "no adjcent   " << "y = " << perm[j].first << "x = " << perm[j].second << '\n';
				}
				cout << '\n'; cout << '\n';
			}
		}

#else

		answer = max(answer, cal());

#endif



		return;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 1)
			{
				continue;
			}

			if (is_adjcent(i, j) == true)
				continue;


			visit[i][j] = 1;
			perm.push_back(make_pair(i, j));


			go(dep + 1);

			visit[i][j] = 0;
			perm.pop_back();
		}
	}
}


int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();

	go(0);

	cout << answer << '\n';


	return 0;
}
