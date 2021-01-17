#include <stdio.h>

int weight[] = { 2, 3, 4, 5 };
int value[] = { 3, 4, 5, 6 };

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;

	return n2;
}
/*
int knapSack(int C,int sum, int*w, int* v, int dep)
{

	//���԰� �������ų�  ���� Ž���� ���
	if (C < 0 || dep < 0)
	{
		return 0;
	}
	if (C == 0)
	{
		return sum;
	}
	//������ ���԰� ū ��� ���� �� ����
	if (w[dep - 1] > C)
	{
		knapSack(C, sum, w, v, dep - 1);
	}
	//�ش� �������� �����ϴ� ���� �������� ���� ���
	return max(knapSack(C - w[dep - 1], sum + v[dep - 1], w, v, dep - 1), knapSack(C, sum, w, v, dep - 1));
}
*/
int knapSack(int dep, int v,int w)
{
	//���� �ʰ� �Ǵ� ���
	if (w > 5)
	{
		return -weight[dep-1];
	}
	//��� Ž���� ���
	if (dep == 4)
	{
		return v;
	}
	return max(knapSack(dep + 1, v + value[dep], w + weight[dep]), knapSack(dep + 1, v, w));
}
int main()
{

	printf("������ ������ �� �� �ִ� ��ġ�� �ִ��� %d�Դϴ�.\n",knapSack(0,0,0));
	return 0;
}