/*
    수를 부른 뒤 가로, 세로, 대각선을 체크한다.
    선이 3개 이상 그어지는 순간 "빙고"라 외친 뒤
    해당 수가 몇번쨰 수인지 출력

*/
#include<stdio.h>

int map[5][5];
int visit[5][5]={0,};
int mention[5][5];

//가로
int checkRow(int cnt,int y,int x)
{
    //끝까지 탐색 완료
   if(cnt == 5)
   {
       return 1;
   }
    
  int nextX = x+1;
    
  if(visit[y][x] == 0)
  {
     return 0;
  }
  
//  printf("Row y=%d,x=%d \n",y,x);
  

  return checkRow(cnt+1,y,nextX);
}
//세로
int checkCol(int cnt,int y,int x)
{
    //끝까지 탐색 완료
    if(cnt == 5)
    {
        return 1;
    }

    if(visit[y][x] == 0)
    {
        return 0;
    }

  //  printf("Col y=%d,x=%d\n",y,x);

    return checkCol(cnt+1,y+1,x);

}
//좌측 대각선
int checkLeftDig(int cnt,int y,int x)
{
    if(cnt == 5)
    {
        return 1;
    }

    if(visit[y][x] == 0)
        return 0;

//  printf("Left Dig y=%d,x=%d\n",y,x);

  return checkLeftDig(cnt+1,y+1,x+1);
}
//우측 대각선
int checkRightDig(int cnt,int y,int x)
{
    if(cnt == 5)
    {
        return 1;
    }

    if(visit[y][x] == 0)
        return 0;
    
//    printf("Right Dig y=%d,x=%d\n",y,x);

    return checkRightDig(cnt+1,y+1,x-1);
}
int main()
{
    int i,j,k,l;
    int match=0, count = 0;

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&map[i][j]);
        }
    }
   for(i =0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&mention[i][j]);
        }
    }
/*
    visit[0][0] = 1;
    visit[0][1] = 1;
    visit[0][2] = 1;
    visit[1][4] = 1;
    visit[1][2] = 1;

    visit[1][0] = 1;
    visit[2][0] = 1;
    visit[3][0] = 1;
    visit[4][0] = 1;


    visit[1][1] = 1;
    visit[2][2] = 1;
    visit[3][3] = 1;
    visit[4][4] = 1;

    visit[0][4] = 1;
    visit[1][3] = 1;
    visit[3][1]= 1;
    visit[4][0] = 1;

for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {
        printf("visit[%d %d] = %d\n",i,j,visit[i][j]);
    }
    printf("\n");
}
    
    checkRow(0,1,0);
    checkRightDig(0,0,4);

*/

   for(i=0;i<5;i++)
   {
       for(j=0;j<5;j++)
       {

           for(k=0;k<5;k++)
           {
               for(l=0;l<5;l++)
               {
                   int r,c;

                   if(map[k][l] == mention[i][j])
                   {
  //                     printf("k=%d l=%d %d\n",k,l,map[k][l]);

                       visit[k][l] = 1;
                       count++;
                        

//                       printf("========== visit배열 ==========\n");
                       int r,c;
            
                       for(r=0;r<5;r++)
                       {
                           if(checkRow(0,r,0) == 1) //가로
                           {
                               match++;             
                           }
                       }

                       for(c=0;c<5;c++)
                       {
                           if(checkCol(0,0,c) == 1) // 세로
                           {
                               match++;
                           }
                       }
                       if(checkLeftDig(0,0,0) == 1) //좌측 대각선
                       {
                           match++;
                       }

                       if(checkRightDig(0,0,4) == 1)//우측 대각선
                       {
                           match++;
                       }

                       if(match >=3)
                       {
                           int r,c;

                           printf("%d\n",count);


                           return 0;
                       }

                       match=0;
                   }
               }//l
           }//l
       }//j
   }//i


   return 0;
}
