/*
   플러드 필 알고리즘
   -> 영역 안의 양의 수가 늑대의 수보다 많다면 이기고, 늑대를 우리에서 쫓아낸다. 그렇지 않다면 늑대가 그 지역 안의 모든 양을 먹는다.

   - 글자 '.' (점)은 빈 필드를 의미하며, 글자 '#'는 울타리를, 'o'는 양, 'v'는 늑대를 의미
   - .을 기준으로 동서남북 탐색하여 방문체크를 하고, '#'을 만나는 경우, 되돌아감
   - 늑대나 양을 만나는 경우 카운트를 하며, 방문체크도 함
   - 해당 구역내에 양과 늑대 카운트 하고 초기화 
*/

#include<stdio.h>
#include<string.h>

char map[255][255];
int visit[255][255];
int R, C;

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

int wolf = 0;
int sheep = 0;

int temp_wolf = 0, temp_sheep = 0;

void floodfill(int y, int x)
{

   for (int i = 0; i < 4; i++)
   {
      int ny = y + dy[i];
      int nx = x + dx[i];

      //맵의 범위를 벗어나는 경우
      if (ny < 0 || ny >= R || nx < 0 || nx >= C)
         continue;
      //장애물을 만나거나 이미 방문한 경우
      if (map[ny][nx] == '#' || visit[ny][nx] == 1)
         continue;

      if (map[ny][nx] == 'o' && visit[ny][nx] == 0)
      {
         temp_sheep++;
         visit[ny][nx] = 1;
         
      }
      else if (map[ny][nx] == 'v' && visit[ny][nx] == 0)
      {
         temp_wolf++;
         visit[ny][nx] = 1;
         
         
      }
      else if(map[ny][nx] == '.' && visit[ny][nx] == 0)
      {
         visit[ny][nx] = 1;
         
      }
      floodfill(ny,nx);
   }
}
int main()
{
   scanf("%d %d", &R, &C);

   for (int i = 0; i < R; i++)
   {
      scanf("%s", map[i]);
   }

   for (int i = 0; i < R; i++)
   {
      for (int j = 0; j < C; j++)
      {
         if (map[i][j] == '.' && visit[i][j] == 0)
         {
            visit[i][j] = 1;
            floodfill(i, j);

            if (temp_sheep > temp_wolf)
            {
               sheep += temp_sheep;
            }
            else
            {
               wolf += temp_wolf;
            }

            //영역 내부 늑대,양 카운트 변수 초기화
            temp_wolf = 0;
            temp_sheep = 0;
         }
         else if (map[i][j] == 'o' && visit[i][j] == 0)//양을 시작으로 탐색
         {
            visit[i][j] = 1;
            temp_sheep++;
            floodfill(i, j);

            if (temp_sheep > temp_wolf)
            {
               sheep += temp_sheep;
            }
            else
            {
               wolf += temp_wolf;
            }

            //영역 내부 늑대,양 카운트 변수 초기화
            temp_wolf = 0;
            temp_sheep = 0;
         }
         else if (map[i][j] == 'v' && visit[i][j] == 0)//늑대를 시작으로 탐색
         {
            visit[i][j] = 1;
            temp_wolf++;
            floodfill(i, j);

            if (temp_sheep > temp_wolf)
            {
               sheep += temp_sheep;
            }
            else
            {
               wolf += temp_wolf;
            }

            //영역 내부 늑대,양 카운트 변수 초기화
            temp_wolf = 0;
            temp_sheep = 0;
         }
      }
   }

   printf("%d %d\n", sheep, wolf);

   return 0;
}
