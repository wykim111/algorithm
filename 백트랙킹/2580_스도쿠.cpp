/*
	< 백트래킹 >

1. 초기화
	   - 빈칸(0) 좌표를 vector에 저장
	   - 기존 숫자는 row, col, section 테이블에 true 등록
	   - row : 2차원 배열의 행에서 숫자 존재 여부를 확인
	   - col : 2차원 배열의 열에서 숫자 존재 여부를 확인
	   - section : 3 by 3 구역에서 숫자 존재 여부를 확인

2. 탐색
	go(dep)
	{
	   if (dep == 빈칸 수) 
	   {
			//출력
			exit(0); 
		}

	   (y, x) 추출 및 section = (y / 3) * 3 + (x / 3)
	   - for (num = 1 ~ 9)
		   if (!row[y][num] && !col[x][num] && !section[sec][num])
			   방문 처리 (board, row, col, section)
			   go(dep + 1)
			   원복 (board = 0, row, col, section 해제)
	}
*/


#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdlib>
using namespace std;

typedef struct _pos
{
	int y;
	int x;
}pos;

int input_table[9][9];
int section_table[9][10];
int row_table[9][10];
int col_table[9][10];


vector<pos> pos_vt;

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> input_table[i][j];

			if (input_table[i][j] == 0)
			{
				pos stPos;

				stPos.y = i;
				stPos.x = j;

				pos_vt.push_back(stPos);
			}
			else
			{
				int section_idx = ((i / 3) * 3) + (j / 3);
				section_table[section_idx][input_table[i][j]] = true;
				row_table[i][input_table[i][j]] = true;
				col_table[j][input_table[i][j]] = true;
			}

		}
	}
}

void print_sudoku()
{
	//cout << "\n";
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input_table[i][j] << (j == 8 ? "" : " ");
		}
		cout << '\n';
	}
}


bool check_pos(int y, int x, int section_idx, int val)
{
	if (row_table[y][val] == true)
	{
		return false;
	}

	if (col_table[x][val] == true)
	{
		return false;
	}

	// 3 by 3
	if (section_table[section_idx][val] == true)
	{
			return false;
	}
	

	return true;
}

void go(int dep)
{
	if (dep == pos_vt.size())
	{
		print_sudoku();

		exit(0);
	}

	int cur_y = pos_vt[dep].y;
	int cur_x = pos_vt[dep].x;

	int section_idx = ((cur_y / 3) * 3) + (cur_x / 3);

	//cout << "cur_y = " << cur_y << " cur_x = " << cur_x << " section_idx = " << section_idx << '\n';

	for (int i = 1; i < 10; i++)
	{
		if (check_pos(cur_y, cur_x, section_idx, i) == true)
		{
			input_table[cur_y][cur_x] = i;
			section_table[section_idx][i] = true;
			row_table[cur_y][i] = true;
			col_table[cur_x][i] = true;

			go(dep + 1);

			input_table[cur_y][cur_x] = 0;
			section_table[section_idx][i] = false;
			row_table[cur_y][i] = false;
			col_table[cur_x][i] = false;

		}
	}

}


void solution()
{
	//cout << "zero_vt.size() = " << pos_vt.size() << '\n';
	go(0);
}

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();


	return 0;
}



////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

#if 0
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct _pos
{
	int y;
	int x;
} pos;

int input_table[9][9];
int section_table[9][10];
vector<pos> pos_vt;

void input()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> input_table[i][j];

			if (input_table[i][j] == 0)
			{
				pos stPos;
				stPos.y = i;
				stPos.x = j;
				pos_vt.push_back(stPos);
			}
			else
			{
				int section_idx = ((i / 3) * 3) + (j / 3);
				section_table[section_idx][input_table[i][j]] = true;
			}
		}
	}
}

void print_sudoku()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << input_table[i][j] << (j == 8 ? "" : " ");
		}
		cout << '\n';
	}
}

bool check_pos(int y, int x, int section_idx, int val)
{
	for (int i = 0; i < 9; i++)
	{
		// 가로
		if (input_table[y][i] == val)
		{
			return false;
		}
		// 세로
		if (input_table[i][x] == val)
		{
			return false;
		}
	}

	// 3 by 3 구역 O(1) 확인
	if (section_table[section_idx][val])
	{
		return false;
	}

	return true;
}

void go(int dep)
{
	if (dep == pos_vt.size())
	{
		print_sudoku();
		exit(0);
	}

	int cur_y = pos_vt[dep].y;
	int cur_x = pos_vt[dep].x;

	int section_idx = ((cur_y / 3) * 3) + (cur_x / 3);

	for (int i = 1; i <= 9; i++)
	{
		if (check_pos(cur_y, cur_x, section_idx, i))
		{
			input_table[cur_y][cur_x] = i;
			section_table[section_idx][i] = true;

			go(dep + 1);

			input_table[cur_y][cur_x] = 0;
			section_table[section_idx][i] = false;
		}
	}
}

void solution()
{
	go(0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}

#endif
