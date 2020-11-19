#include<stdio.h>

int map[101][101];
int N;


int main()
{
    int row,col;

    scanf("%d",&N);

    row = N-1;
    col = N/2;

    map[row][col] = 1;

    for(int num=2;num<=N*N;num++)
    {
       int nextRow = row+1;
       int nextCol = col+1;

       if(nextRow >=N)
       {
            nextRow = 0; 
       }
       if(nextCol >= N)
       {
            nextCol = 0;
       }
        ///이동했는데 데이터가 존재하는 경우
       if(map[nextRow][nextCol] != 0)
       {
            row-- ;//행 1만큼 감소

            map[row][col] = num;
       }
       else
       {
            //다음 위치에 데이터를 저장하고 위치 업데이트
            map[nextRow][nextCol]=num;
            row = nextRow;
            col = nextCol;
       }
       

    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%1d ",map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
