/* 
r�� ���� ���� �ʾ��� �� ����, e�� ���� ���� ���� ����, c�� ���� ����̴�. (-106 �� r,e �� 106, 0 �� c �� 106)

 1) r > e - c : ���� ���� �ʾ����� ������ ū ��� "do not advertise" ���
 2) r = e - c : ������ ���̰� ���ٸ� "does not matter"�� ���
 3) r < e - c " ���� �ؾ� �ϸ� "advertise" ���

*/

#include<stdio.h>

int main()
{
	int N;

	scanf("%d", &N);

	while (N--)
	{
		int r, e, c;

		scanf("%d %d %d", &r, &e, &c);

		if (r < e - c)
		{
			printf("advertise\n");

		}
		else if (r > e - c)
		{
			printf("do not advertise\n");
		}
		else
		{
			printf("does not matter\n");
		}
	}

	return 0;
}