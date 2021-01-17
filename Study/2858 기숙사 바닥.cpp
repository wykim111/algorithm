
/*
	������ 0�� ���� ���� ���� �����ϳ��� 2�����̴�
	������ ������ �ּ� 3x3 �׸� �����̹Ƿ� ���� ��� ���� ����

	1)R+B�� ���Ѵ�.
	2)���� ���� �ּ� 3���� ������
	3)������ �������� ���, ����*���θ� �Ͽ� R+B�� ������ Ȯ��
	4) ���� ��� R�� B �Է� ���� ���� ������ ���� Red�� Brown��
	   Brown�� ��� ����-2�� �ϸ� ������ ����
	  ����, �� ���� �ٸ��ٸ�, ū ���� L�� �ǰ� ���� ���� W�� �ȴ�. �׻� ������ ������ ��츸 �Է����� �־�����.
*/
#include<stdio.h>

int R, B;
int sum = 0;
int L, W;


int isCheck(int a, int b)
{
	int brown = b - 2;
	int red = a * b;

	brown = (a - 2) * brown;
	red -= brown;

	if (red == R && brown == B)
	{
		return 1;
	}
	return 0;
}

int main()
{
	
	scanf("%d %d", &R, &B);

	sum = R + B;

	for (int i = 3;i<=sum; i++)
	{
		int j = sum / i;

		if (j <= 2)
			continue;

		if (i*j == sum)
		{
			if (isCheck(i, j) == 1)
			{
				if (i < j)
				{
					L = j;
					W = i;

				}
				else
				{
					L = i;
					W = j;
				}
				break;
			}
		}
	}

	printf("%d %d\n", L, W);

	return 0;
}