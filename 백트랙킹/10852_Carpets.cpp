/*
   <백트래킹 - subset>

   1. carpet에 대한 자료구조 정의
   2. 탐색(카펫의 종류는 최대 7개)
	  go(dep, carpet_subset)
	  {
		 //base case
		 if(dep == carpet의 모든 종류)
		 {
			//카펫들의 넓이 합이 target의 넓이 합과 일치하는지 확인.
			//현재 선택한 carpet들로 면적을 덮을 수 있는지 확인

			return;
		 }

		 //dep번째 carpet 선택
		 go(dep+1, carpet_subset | (1 << dep))
		 //dep번째 carpet 미선택
		 go(dep+1, carpet)
	  }
   3. 현재 선택한 carpet들로 면적을 덮을 수 있는지 확인
	  3-1. base case : 방의 모든 면적을  다 채운 경우 ans = true.
	  3-2. 현재 카펫을 그대로 두는 경우
	  3-3. 현재 카펫을 회전 시키는 경우

*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

// Debug mode control
#define DEBUG_MODE 0  // Set to 0 to disable debug output
#define DEBUG_TABLE 0  // Set to 0 to disable table printing
#define DEBUG_RECURSION 0  // Set to 0 to disable recursion depth logging
#define DEBUG_PLACEMENT 0  // Set to 0 to disable carpet placement details

typedef struct Carpet
{
	int a; // 해당 종류의 개수(갯수)
	int w; // 가로 길이
	int h; // 세로 길이
} Carpet;

int W, H; // 격자 너비(W), 높이(H)
int c;    // 카펫 종류 수

int target_carpet_table[105][105];
vector<Carpet> carpets_vt;

bool ans = false;
int recursion_depth = 0;

void print_indent(int depth)
{
	for (int i = 0; i < depth; i++)
		cout << "  ";
}

void print_table()
{
#if DEBUG_TABLE
	cout << "Current table state:\n";
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << setw(2) << target_carpet_table[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "-------------------\n";
#endif
}

// 카펫을 둘 때마다 호출: 배치 직후 테이블 상태 출력
void print_table_compact()
{
#if DEBUG_PLACEMENT
	for (int i = 0; i < H; i++)
	{
		print_indent(recursion_depth);
		for (int j = 0; j < W; j++)
		{
			cout << target_carpet_table[i][j];
		}
		cout << '\n';
	}
	print_indent(recursion_depth);
	cout << "---\n";
#endif
}

void input()
{
	cin >> W >> H;
	cin >> c;

	for (int i = 0; i < c; i++)
	{
		Carpet carpet;

		cin >> carpet.a >> carpet.w >> carpet.h;

		// 각 카펫 종류별로 개수(a)만큼 확장하여 벡터에 저장
		for (int j = 0; j < carpet.a; j++)
		{
			carpets_vt.push_back(carpet);
		}

	}

}

// 카펫을 회전(가로/세로 교체)
void rotate_carpet(Carpet &carpet, int cur_y, int cur_x)
{
	int temp = carpet.w;
	carpet.w = carpet.h;
	carpet.h = temp;

}

// cur_y, cur_x 위치에서 해당 카펫을 놓을 수 있는지(범위 내 && 겹치지 않음) 검사
bool is_available(Carpet &carpet, int cur_y, int cur_x)
{
	// 영역 검사
	for (int i = cur_y; i < cur_y + carpet.h; i++)
	{
		for (int j = cur_x; j < cur_x + carpet.w; j++)
		{
			if (i >= H || j >= W)
			{
				return false;
			}
			if (target_carpet_table[i][j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}

// 현재 테이블이 모두 채워졌는지 확인
bool is_ok()
{
#if DEBUG_TABLE
	print_table();
#endif

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (target_carpet_table[i][j] == 0)
			{
#if DEBUG_MODE
				cout << "is_ok: Found empty cell at (" << i << ", " << j << ")\n";
#endif
				return false;
			}
		}
	}

#if DEBUG_MODE
	cout << "is_ok: All cells filled! SUCCESS!\n";
#endif
	return true;
}


bool can_replace_carpet(int carpet_subset)
{
	//base case : 방의 모든 면적을  다 채운 경우 ans = true.
	if (carpet_subset == 0)
	{

		return true;
	}

	//빈 칸 찾기
	int cur_y = -1;
	int cur_x = -1;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (target_carpet_table[i][j] == 0)
			{
				cur_y = i;
				cur_x = j;

				//빈 칸 발견 시 즉시 탈출
				goto FOUND;
			}
		}

	}

FOUND:

	if (cur_y == -1)
	{
		return false;
	}
		

	//현재 선택된 카펫 종류들 중에서 하나씩 시도
	for (int i = 0; i < carpets_vt.size(); i++)
	{
		if ((carpet_subset & (1 << i)) == 0)
		{
			continue;
		}
		Carpet carpet = carpets_vt[i];
		// 현재 카펫을 회전하지 않고 놓기 시도
		if (is_available(carpet, cur_y, cur_x))
		{
			// 카펫 놓기
			int y = 0;
			int x = 0;

			for (y = cur_y; y < cur_y + carpet.h; y++)
			{
				for (x = cur_x; x < cur_x + carpet.w; x++)
				{
					target_carpet_table[y][x] = 1;
				}
			}

			carpet_subset &= ~(1 << i); // 사용한 카펫 제거
			recursion_depth++;
			if (can_replace_carpet(carpet_subset) == true)
			{
				return true;
			}

			// 카펫 제거(백트래킹)
			for (y = cur_y; y < cur_y + carpet.h; y++)
			{
				for (x = cur_x; x < cur_x + carpet.w; x++)
				{
					target_carpet_table[y][x] = 0;
				}
			}
			recursion_depth--;
			carpet_subset |= (1 << i); // 카펫 복원


		}

		//현재 카펫을 회전시켜 놓기 시도
		rotate_carpet(carpet, cur_y, cur_x); // ***** 여기서 1시간 동안 헤멤 *****

		if (is_available(carpet, cur_y, cur_x) == true)
		{
			
			// 카펫 놓기
			int y = 0;
			int x = 0;
			for (y = cur_y; y < cur_y + carpet.h; y++)
			{
				for (x = cur_x; x < cur_x + carpet.w; x++)
				{
					target_carpet_table[y][x] = 1;
				}
			}


			carpet_subset &= ~(1 << i); // 사용한 카펫 제거
			recursion_depth++;

			if (can_replace_carpet(carpet_subset) == true)
			{
				return true;
			}

			// 카펫 제거(백트래킹)
			for (y = cur_y; y < cur_y + carpet.h; y++)
			{
				for (x = cur_x; x < cur_x + carpet.w; x++)
				{
					target_carpet_table[y][x] = 0;
				}
			}
			recursion_depth--;;
			carpet_subset |= (1 << i); // 카펫 복원

		}


	}

	return false;
}


void go(int dep, int carpet_subset)
{
	// 이미 만족하는 경우 조기 종료
	if (ans == true)
	{
		return;
	}

	// base case: 모든 종류에 대해 포함/비포함 결정 완료
	if (dep == carpets_vt.size())
	{
		//선택한 카펫들을 기준으로 면적의 합 비교
		int sum = 0;

		for (int i = 0; i < carpets_vt.size(); i++)
		{
			if ((carpet_subset & (1 << i)) != 0)
			{
				sum += carpets_vt[i].w * carpets_vt[i].h;
			}
		}

		if (sum != (W * H))
		{
			return;

		}

		// 방 초기화 후 배치 시도
		for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) 
		{
			target_carpet_table[i][j] = 0;
		}

		//선택한 카펫들로 방의 면적을 다 채울 수 있는지 확인
		if (can_replace_carpet(carpet_subset) == true)
		{
			ans = true;
		}


		return;
	}
	// 현재 dep번째 carpet 포함
	go(dep + 1, carpet_subset | (1 << dep));

	// 현재 dep번째 carpet 미포함
	go(dep + 1, carpet_subset);
}

void solution()
{
	// subset 탐색
	go(0, 0);

	if (ans == true)
	{
		cout << "yes\n";
	}
	else
	{
		cout << "no\n";
	}
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