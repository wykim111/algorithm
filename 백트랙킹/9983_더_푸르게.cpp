/*

	< 백트래킹 - subset, bitmasking >

1. 체스 유닛의 정보(역할, 위치)를 vector에 저장.

2. 탐색

		go(dep, unit_subset_mask)
		{

			if(dep == 체스 유닛의 총 갯수)
			{
				//제거 유닛의 수 = 총 유닛 - 선택한 유닛(unit_subset_mask)

				return;

			}


		2-1. 현재 dep번째 유닛을 포함하는 경우
		if(현재 dep 유닛이 모두를 공격하지 않은 경우)
		{
			맵에 유닛 위치 추가
			go(dep+1, unit_subset_mask | (1 << dep));
			맵에 유닛 위치 제거
		}
		

		2-2. 현재 dep번쨰 유닛을 포함하지 않은 경우
		go(dep+1, unit_subset_mask);

	}

3. 각 유닛의 범위에 다른 유닛들이 있는지 체크
	



*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include <climits>
using namespace std;

typedef struct _unit_info 
{
	char type;
	int y;
	int x;
} unit_info;

string start_cmd, end_cmd;
int W, H;
vector<unit_info> unit_vt;
int min_remove_cnt;

char input_table[11][11];
char temp_table[11][11];

int total_unit_cnt = 0;

// 방향 배열
int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 }; // 0~3: 상하좌우, 4~7: 대각선
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int ndy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 }; // 나이트 8방향
int ndx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };



void init()
{
	unit_vt.clear();
	min_remove_cnt = INT_MAX;

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			temp_table[i][j] = 'E';
		}
	}
}

void input()
{
	cin >> W;
	cin >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> input_table[i][j];

			// 빈칸(E)이 아닌 유닛들만 백트래킹을 위해 vector에 저장
			if (input_table[i][j] != 'E')
			{
				unit_vt.push_back({ input_table[i][j], i, j });
			}
		}
	}

}


bool can_attack_King(int idx)
{
	int y = unit_vt[idx].y;
	int x = unit_vt[idx].x;

	// 8방향 1칸씩만 검사
	for (int d = 0; d < 8; d++) 
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		if (ny >= 0 && ny < H && nx >= 0 && nx < W) 
		{
			if (temp_table[ny][nx] != 'E')
			{
				return true;
			}
		}
	}
	return false;
}

bool can_attack_Queen(int idx)
{
	int y = unit_vt[idx].y;
	int x = unit_vt[idx].x;

	// 8방향 끝까지 전진
	for (int d = 0; d < 8; d++) 
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		while (ny >= 0 && ny < H && nx >= 0 && nx < W) 
		{
			if (temp_table[ny][nx] != 'E')
			{
				return true;
			}
			ny += dy[d];
			nx += dx[d];
		}
	}

	return false;
}

bool can_attack_Bishop(int idx)
{
	int y = unit_vt[idx].y;
	int x = unit_vt[idx].x;

	// 4~7(대각선) 방향 끝까지 전진
	for (int d = 4; d < 8; d++) 
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		while (ny >= 0 && ny < H && nx >= 0 && nx < W) 
		{
			if (temp_table[ny][nx] != 'E')
			{
				return true;
			}
			ny += dy[d];
			nx += dx[d];
		}
	}
	return false;
}

bool can_attack_Rock(int idx) // Rook
{
	int y = unit_vt[idx].y;
	int x = unit_vt[idx].x;

	// 0~3(상하좌우) 방향 끝까지 전진
	for (int d = 0; d < 4; d++) 
	{
		int ny = y + dy[d];
		int nx = x + dx[d];
		while (ny >= 0 && ny < H && nx >= 0 && nx < W) 
		{
			if (temp_table[ny][nx] != 'E')
			{
				return true;
			}
			ny += dy[d];
			nx += dx[d];
		}
	}
	return false;
}

bool can_attack_Knight(int idx)
{
	int y = unit_vt[idx].y;
	int x = unit_vt[idx].x;

	// 나이트 특수 8방향 1칸 검사
	for (int d = 0; d < 8; d++) 
	{
		int ny = y + ndy[d];
		int nx = x + ndx[d];
		if (ny >= 0 && ny < H && nx >= 0 && nx < W) 
		{
			if (temp_table[ny][nx] != 'E')
			{
				return true;
			}
		}
	}
	return false;
}

bool can_attack(int idx)
{
	unit_info target_unit = unit_vt[idx];
	bool attack_flag = false;
	temp_table[target_unit.y][target_unit.x] = target_unit.type;

	//현재 target unit이 공격 가능한 범위 내에 다른 유닛이 존재하는지 확인
	if (target_unit.type == 'K')
	{
		attack_flag = can_attack_King(idx);
	}
	else if (target_unit.type == 'Q')
	{
		attack_flag = can_attack_Queen(idx);
	}
	else if (target_unit.type == 'R')
	{
		attack_flag = can_attack_Rock(idx);
	}
	else if (target_unit.type == 'B')
	{
		attack_flag = can_attack_Bishop(idx);
	}
	else if (target_unit.type == 'N')
	{
		attack_flag = can_attack_Knight(idx);
	}


	//다른 유닛이 현재 target unit을 공격할 수 있는지 확인
	if (attack_flag == false)
	{
		for (int i = 0; i < idx; i++)
		{
			unit_info other_unit = unit_vt[i];

			if (temp_table[other_unit.y][other_unit.x] != 'E')
			{
				if (other_unit.type == 'K')
				{
					attack_flag = can_attack_King(i);
				}
				else if (other_unit.type == 'Q')
				{
					attack_flag = can_attack_Queen(i);
				}
				else if (other_unit.type == 'R')
				{
					attack_flag = can_attack_Rock(i);
				}
				else if (other_unit.type == 'B')
				{
					attack_flag = can_attack_Bishop(i);
				}
				else if (other_unit.type == 'N')
				{
					attack_flag = can_attack_Knight(i);
				}
			}

		}
	}

	temp_table[target_unit.y][target_unit.x] = 'E';

	return attack_flag;
}


void go(int dep, unsigned int unit_subset_mask)
{
	if (dep == total_unit_cnt)
	{
		int pick_unit_cnt = 0;

		for (int i = 0; i < total_unit_cnt; i++)
		{
			if (unit_subset_mask & (1 << i))
			{
				++pick_unit_cnt;
			}
		}

		min_remove_cnt = min(min_remove_cnt, total_unit_cnt - pick_unit_cnt);

		return;
	}


	//현재 dep번째 유닛을 포함하는 경우
	if (can_attack(dep) == false)
	{
		unit_info pick_unit = unit_vt[dep];

		temp_table[pick_unit.y][pick_unit.x] = pick_unit.type;
		go(dep + 1, unit_subset_mask | (1 << dep));
		temp_table[pick_unit.y][pick_unit.x] = 'E';
	}
	//현재 dep번쨰 유닛을 포함하지 않은 경우
	go(dep + 1, unit_subset_mask);
}


void solution()
{
	total_unit_cnt = unit_vt.size();

	//cout << "[solution] total_unit_cnt = " << total_unit_cnt << '\n';

	go(0, 0);
}

int main()
{
	ios::sync_with_stdio(NULL);
	cout.tie(NULL);
	cin.tie(NULL);

	while (cin >> start_cmd)
	{
		if (start_cmd == "START")
		{
			init();
			input();

			cin >> end_cmd;

			//cout << "1" << '\n';

			if (end_cmd == "END")
			{
				//cout << "2" << '\n';

				solution();
		
				cout << "Minimum Number of Pieces to be removed: " << min_remove_cnt << '\n';
			}
		}
	}
		

	

	return 0;
}