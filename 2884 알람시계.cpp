/*
	�Է��� �п� -45�� �Ͽ� 0���� ���� ���
	hour�� -1 �ϸ�, 0���� ���� ����ŭ 60���� ���ش�.
*/

#include<stdio.h>

int H, M;

int main()
{
	scanf("%d %d", &H, &M);

	if (M - 45 < 0)
	{
		int temp = M - 45;//����
		M = 60 + temp;
		H -= 1;

		if (H < 0)
		{
			H = 23;
		}
	}
	else
	{
		M -= 45;

	}

	printf("%d %d\n", H, M);

	return 0;
}