/*
    <백트래킹 >


    ==============================
    1. 맵에서 현재 체력과 초기 체력을 동시에 관라하기 위해 구조체 구성.
        typedef struct _target
        {
            int cur_hp; //현재 체력
            int init_hp; //초기 체력
        }target;

        target map_table[8][8]; //맵 테이블


    2. 보드판의 위치를 중복 순열로 탐색.
        go(dep)
        {
            if(dep == 사격 횟수)
            {
                //사격 횟수만큼 선택한 경우, 점수 계산
                //최대 점수 갱신

                return;
            }
            
            for(i = 0 ~ N)
            {
                perm_vt에 i 저장
                go(dep+1);
                perm_vt에서 i 제거
            }

        
        }

   3. 중복순열로 선택한 위치를 기반으로 점수 계산 (K발의 총알 발사)
        3-1. 원본 맵을 임시 맵으로 복사 (맵은 [현재 체력, 초기 체력] 2개 정보를 가짐)
        
        3-2. 총알 발사 (perm_vt에 담긴 행(Row)에서 열(Col)을 차례대로 탐색)
             -> 0이 아닌 표적을 가장 먼저 만나면 타격 시작!
        
        3-3. 타격 로직
            3-3-1. 보너스 표적(초기 체력이 10 이상)인 경우
                   - 점수 += 해당 표적에 적혀있는 값 (예: 20이면 20점 추가)
                   - 표적을 즉시 0으로 변경 (제거)
            
            3-3-2. 일반 표적(1~9)인 경우
                   - 현재 체력 -= 총알의 공격력
                   - 만약 현재 체력 <= 0 이라면 (표적 파괴됨)
                     - 점수 += 해당 표적의 '초기 체력'
                     - 표적을 즉시 0으로 변경 (제거)
                     - 4(파편화) 단계로 이동
                     
        4. 파편화 로직 (일반 표적이 파괴되었을 때만 실행)
            4-1. 분할된 체력 = (파괴된 표적의 '초기 체력' / 4)
            4-2. 분할된 체력이 0보다 크다면, 동서남북 탐색
            4-3. 탐색한 곳이 맵을 벗어나지 않고, '빈칸(0)'인 경우에만!
                   -> 그 자리에 [현재 체력 = 분할된 체력, 초기 체력 = 분할된 체력]인 새 표적 생성
    */

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>

using namespace std;

typedef struct _pos_info
{
    int cur_point;
    int origin_point;
}pos_info;

int N; // 보드판의 크기
int K; // 사격 횟수

pos_info board[9][9];
vector<int> bullet_vt;
vector<int> perm_vt;

//동서남북
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int max_score = INT_MIN;

void input()
{
    cin >> N;
    cin >> K;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int temp_point;

            cin >> temp_point;

            board[i][j].cur_point = temp_point;
            board[i][j].origin_point = temp_point;
        }
    }

    for(int i = 0; i < K;i++)
    {
        int temp_bullet_point;

        cin >> temp_bullet_point;

        bullet_vt.push_back(temp_bullet_point);
    }
}

void simulate()
{
    pos_info temp_board[9][9];
    int total_score = 0;

    //원본 맵을 임시 맵으로 복사
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            temp_board[i][j].cur_point = board[i][j].cur_point;
            temp_board[i][j].origin_point = board[i][j].origin_point;
        }
    }

    for(int i=0; i < perm_vt.size(); i++)
    {
        int row = perm_vt[i];
        int point = bullet_vt[i];

        for(int j=0; j < N; j++)
        {
            if(temp_board[row][j].cur_point == 0) continue;
            
            if(temp_board[row][j].cur_point >= 10)
            {
                total_score += temp_board[row][j].cur_point;
                temp_board[row][j].cur_point = 0;
            }
            else // 10점 미만이면 차감 및 0이하이면, 표적 파괴 및 점수 추가
            {
                temp_board[row][j].cur_point -= point;

                if(temp_board[row][j].cur_point <= 0)
                {
                    total_score += temp_board[row][j].origin_point;
                    temp_board[row][j].cur_point = 0;
                
                    // 파편의 체력을 먼저 계산하고 0보다 클 때만 분열
                    int split_point = temp_board[row][j].origin_point / 4;
                    if(split_point > 0) 
                    {
                        for(int k = 0; k < 4; k++)
                        {
                            int ny = row + dy[k];
                            int nx = j + dx[k];

                            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                            if(temp_board[ny][nx].cur_point != 0) continue;

                            temp_board[ny][nx].cur_point = split_point;
                            temp_board[ny][nx].origin_point = split_point;
                        }
                    }
                }
            }
            
            // 표적을 하나라도 맞혔다면 총알은 즉시 소멸해야 하므로 루프 탈출!
            break; 
        }
    }

    max_score = max(max_score, total_score);
}


void go(int dep)
{
    if(dep == K)
    {
        //simulate
#if 0
        for(int i=0;i<perm_vt.size();i++)
        {
            cout << perm_vt[i] << ' ';
        }
        cout << '\n';
#endif

        simulate();    


        return;
    }

    for(int i=0;i < N; i++)
    {
        perm_vt.push_back(i);
        go(dep+1);
        perm_vt.pop_back();
    }
}

void solution()
{

    //중복 순열
    go(0);

    cout << max_score << '\n';
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