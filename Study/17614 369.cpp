/*
	10���� ����� �������� 3,6,9�� ������ ī��Ʈ
	33 36 �� ���� ��Ģ���� �޾ƾ� �� ���� �ټ� ���ԵǸ� ���Ե� ����ŭ �ڼ�
*/

#include<stdio.h>

int main()
{
	int N;
	int cnt = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int temp = i;

		while (temp)
		{
			int num = i;
			int remainder = temp % 10;
			temp = temp / 10;

			if ((remainder  == 3) || (remainder  == 6) || (remainder  == 9))
			{
				//printf("num = %d\n", num);
				cnt++;
				
			}
		}
	}

	printf("%d\n", cnt);

	return 0;
}