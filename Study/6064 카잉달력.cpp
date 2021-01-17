/*
https://jaimemin.tistory.com/808
�ּҰ������ �̿��Ͽ� Ǫ�� ���������ϴ�.

�˰����� �Ʒ��� �����ϴ�.

1. ���ѽð��� 1���̸�, M�� N�� 40,000���� �־��� �� �ֱ� ������ ���Ʈ ���� �������δ� Ǯ �� ���� ���������ϴ�.

2. M, N�� �ּҰ������ ����⵵�Դϴ�.

3. ���ʿ� �־����⵵�� M���� �������� �� x�̿����ϱ� ������ �ݺ��� ������ x�� M�� ��� ���մϴ�.

4. 3���� �ݺ��ϴµ� �־��� y�� �����ϴ� �⵵�� ã�ų� x�� ����⵵�� �ʰ��ϸ� �ݺ������� Ż���մϴ�.

5. ����⵵�� �ʰ��ϸ� -1�� ����ϰ� x, y�� �����ϴ� �⵵�� ã�Ҵٸ� �ش� �⵵�� ����մϴ�.
*/
#include<stdio.h>

int tc;
int M, N, x, y;

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a%b);
}

int LCM(int a, int b)
{
	return (a*b) / GCD(a, b);
}

int main()
{
	scanf("%d", &tc);
	
	while (tc--)
	{
		int tempM, tempN;
		int maxYear;
	
		scanf("%d %d %d %d", &M, &N, &x, &y);

		maxYear = LCM(M, N);
		while (1)
		{
			if (x > maxYear || (x-1) % N+1 == y)
			{
				break;
			}
			x += M;
		}
		if (x > maxYear)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", x);
		}
	}
	
	return 0;
}