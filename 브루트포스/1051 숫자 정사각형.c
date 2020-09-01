/*
    하나씩 데이터를 탐색하여 행과 열 1씩 증가시킨다.
    (증가 시킬 때, 범위를 넘어서면 스킵)
    각 꼭지점 출력

    map[0][1]인 경우 3x3 정사각형 꼭지점 확인시, 행과 열 +2씩 더하여 비교
    (map[0][1],map[2][1],map[2][3],map[0][3])이 같은 값인지 비교)

    https://www.includehelp.com/c/how-expression-with-multiple-comparison-evaluates-in-c-programming.aspx

    -> if(a==b==c==d) 이 경우 (a==b) == c
    -> (a==b)는 1이므로 1==c로 비교가 되므로 위와 같이 표현하면 안됨

*/   
#include<stdio.h>

int N,M;
char map[51][51];
int maxRet=0;

int min(int n1,int n2)
{
    if(n1 > n2)
        return n2;

    return n1;
}

int squeare(int y,int x,int len)
{
//    printf("%d %d %d\n",y,x,len);
    //범위를 벗어난 경우
    if(y + len >= N || x + len >=M )
    {
        return 0;
    }
    //꼭지점이 모두 같은 경우
    if((map[y][x] == map[y][x+len]) && (map[y][x] == map[y+len][x]) && (map[y][x] == map[y+len][x+len])  )
    {
//       printf("진입 %d %d\n",y,x);
       return (len+1) * (len+1);
    }


    return 0;
}


int main()
{
    int i,j,k;
    int len = 0, size = 0;

    scanf("%d %d",&N,&M);

    for(i=0;i<N;i++)
    {
        scanf("%s",map[i]);
    }

   len = min(N,M);


   for(i=0;i<N;i++)
   {
       for(j=0;j<M;j++)
       {
           for(k=0;k<len;k++)
           {
               size = squeare(i,j,k);

               if(maxRet < size)
               {
                   maxRet = size;
               }

           }

       }
   }

    printf("%d\n",maxRet);


    return 0;   
}
