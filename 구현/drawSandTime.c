/*
7
1234567
 23456
  345
   4
  345
 34567
3456789

*/
#include<stdio.h>

void up(int size)
{
    int i,j,blank=0;
    int num = 0;
    for(i=1;i<=size;i++)
    {
        for(blank = 1;blank<i;blank++)
        {
            printf(" ");
        }

        for(j=1,num=i;j<=-2*i + (2*size+1);j++,num++)//7 5 3  7 + (n-1)-2 = -2n + 9
        {

            printf("%d",num);
        }
        printf("\n");
    }
    


}


void down(int size)
{
    int i,j;
    int num = 0;

    for(i=1;i<=size-1;i++)
    {
         for(int blank = 1;blank < size-i;blank++)
         {
            printf(" ");
         }
         for(j=1,num=size-1;j<=(2*i)+1;j++,num++)
         {
            printf("%d",num);
         }
         printf("\n");
    }


}


int main()
{
    int N;
    int mid = 0;

    scanf("%d",&N);


    mid = N/2+1;
    up(mid);
    down(mid);

    return 0;
}
