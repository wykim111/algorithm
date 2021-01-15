/*	
	높이 : V
	올라가는 높이 : A
	미끄러지는 높이 : B

	단 정상에 올라가면 미끄러지지 않음


	height = height + A;

	while(정상으로 아직 올라가지 않은 경우)
	{
		if(height >= V)
			break

		height = height - B;
		day++
	}
=========================================================

 하루동안 올라가는 거리 : A-B
 목표지점에 올라가면 미끄러지지 않음 : V-B

	day = ((V - B) / (A - B))
*/
#include<stdio.h>

int main()
{
	int A, B, V;
	int height = 0, day = 1;
	
	scanf("%d %d %d",&A,&B,&V);

	/* 시간 초과
	while (height < V)
	{
		height += A;

		if (height >= V)
		{
			break;
		}

		height -= B;
		day++;
	}
	*/

	if (((V - B) % (A - B)) == 0)
	{
		day = ((V - B) / (A - B));
	}
	else
	{
		day = ((V - B) / (A - B))+1;

	}
	

	printf("%d\n",day);

	return 0;
}
