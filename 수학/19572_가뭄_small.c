/*
	1. 1번쨰 칸 = x, 2번째 칸 = y, 3번쨰 칸 = z
		1-1) x + y = a
		1-2) x + z = b
		1-3) y + z = c 
	2. 2(x+y+z) = (a+b+c)
		2-1) (x+y+z) = ((a+b+c)/2)
	3. 여기서 1-1), 1-2), 1-3)에 대해  대입하여 처리
		3-1) 1-1)을 예시로 한 경우, x+y = a 이므로 z = (((a+b+c)/2) - a)
		3-2) 1-2), 1-3)도 같은 원리로 시행.

*/

#include <stdio.h>

int d1, d2, d3;
double a, b, c;

void input()
{
	/*
		d1 = x + y
		d2 = x + z
		d3 + y + z
	*/
	scanf("%d %d %d", &d1, &d2, &d3);
}

void solution()
{
	double sum = (double)(d1 + d2 + d3) / 2.0; // (x + y + c)의 값

	a = sum - (double)d3;
	b = sum - (double)d2;
	c = sum - (double) d1;




	if (a <= 0 || b <= 0 || c <= 0)//만족하지 않은 케이스
	{
		printf("-1\n");
	}
	else //만족한 케이스
	{
		printf("1\n");
		printf("%.1lf %.1lf %.1lf\n", a, b, c);
	}

	


}

int main()
{
	input();
	solution();

	return 0;
}
