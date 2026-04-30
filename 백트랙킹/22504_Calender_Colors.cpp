/*
    < 백트래킹 - subset>
    1. 프리컴퓨팅 연산 : 모든 쌍에 대한 거리를 구함.
        1-1. 캘린더 컬러의 갯수는 최대 20개이므로, 20C10 으로 충분히 모든 쌍에 대한 거리를 구할 수 있음.
        1-2. dist[i][j] = i번쨰 캘린더 컬러와 j번쨰 캘린더 컬러 사이의 거리
        1-3. 거리 계산 방법
            1-3-1. (L2 - L1)^2 + (A2 - A1)^2 + (B2 - B1)^2
    2. 백트래킹 탐색
        go(dep, calender_color_subset)
        {
            if(dep == 모든 캘린더 컬러 탐색)
            {
                if(calender_color_subset에 구성된 캘린더 컬러들의 갯수가 M개인 경우)
                {
                    // calender_color_subset에 구성된 캘린더 컬러들의 쌍에 대한 거리의 합을 구함.
                    ans = min(ans, 구한 거리의 합);
                }

                return;
            }
            // dep번쨰 캘린더 컬러 포함
            go(dep + 1, calender_color_subset);
            
            // dep번쨰 캘린더 컬러를 미포함
            go(dep + 1, calender_color_subset);      
        
        }
    3. 현재 subset에 포함된 캘린더 컬러들의 쌍에 대한 거리의 합을 구함
        3-1. subset에 포함된 캘린더 컬러들의 인덱스에 있는 컬러들과 연결된 컬러들의 인덱스들을 벡터에 저장함.
        3-2. 벡터에 저장된 인덱스들을 이용해서 dist 배열에서 거리를 구함.
    4. 결과 출력
*/

#include <iostream>
#include <algorithm>
#include <vector>

#include <climits>
using namespace std;

typedef struct _calender_Color
{
    double L;
    double A;
    double B;
} calender_Color;

int N, M;
double dist[20][20];

vector<calender_Color> calender_colors;
vector<int> calender_color_subset;

double max_ans = double(INT_MIN);

void input()
{
    cin >> N >> M;

    for(int i=0;i<N;i++)
    {
        calender_Color stCalender_color;

        cin >> stCalender_color.L >> stCalender_color.A >> stCalender_color.B;
        calender_colors.push_back(stCalender_color);
        
    }

    // 모든 쌍에 대한 거리를 구함.
    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            dist[i][j]  = (calender_colors[i].L - calender_colors[j].L) * (calender_colors[i].L - calender_colors[j].L) + 
                          (calender_colors[i].A - calender_colors[j].A) * (calender_colors[i].A - calender_colors[j].A) + 
                          (calender_colors[i].B - calender_colors[j].B) * (calender_colors[i].B - calender_colors[j].B);
        
            dist[j][i] = dist[i][j];

        }

    }
}

void go(int dep)
{
    if(dep == N)
    {
        if(calender_color_subset.size() == M)
        {
            double sum = 0;

            for(int i=0;i<calender_color_subset.size();i++)
            {
                for(int j=i+1;j<calender_color_subset.size();j++)
                {
                    sum += dist[calender_color_subset[i]][calender_color_subset[j]];
                }
            }
#if 0
            cout << "[go] max_ans : " << max_ans << '\n';
#endif
            max_ans = max(max_ans, sum);
        }

        return;
    }

    // dep번쨰 캘린더 컬러 포함
    calender_color_subset.push_back(dep);
    go(dep + 1);
    calender_color_subset.pop_back();

    // dep번쨰 캘린더 컬러를 미포함
    go(dep + 1);
}

void solution()
{
    go(0);

    cout << fixed;
    cout.precision(10);
    cout << max_ans << '\n';
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