/*
	���� �ѷ� = 2*PI*R
	���簢�� �ѷ� = ����*2 + ���� * 2
	
*/

#include<stdio.h>

#define PI 3.141592

double d1, d2;

int main()
{
	double diameter = 0.0;
	double squareWidth = 0.0;

	scanf("%lf", &d1);//���簢�� ����
	scanf("%lf", &d2);//���� ������, ���簢�� ����

	diameter = 2 * PI * d2;
	squareWidth = 2*d1;

	printf("%.6lf", diameter + squareWidth);

	return 0;
}

