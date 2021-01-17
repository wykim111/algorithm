/*
	원의 둘레 = 2*PI*R
	직사각형 둘레 = 가로*2 + 세로 * 2
	
*/

#include<stdio.h>

#define PI 3.141592

double d1, d2;

int main()
{
	double diameter = 0.0;
	double squareWidth = 0.0;

	scanf("%lf", &d1);//직사각형 가로
	scanf("%lf", &d2);//원의 반지름, 직사각형 세로

	diameter = 2 * PI * d2;
	squareWidth = 2*d1;

	printf("%.6lf", diameter + squareWidth);

	return 0;
}

