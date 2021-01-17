/*
	�ǽ� 2-8 �����Ͽ� �� ���ʿ� �Ʒ��ڸ��� �ƴ϶� ���ڸ��� �����ϴ� card_conv�� �ۼ�

*/
#include<stdio.h>

int card_conv(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int digits = 0;

		if (x == 0)
		{
			d[digits++] = 0;
		}
		else
		{
			while (x != 0)
			{
				d[digits++] = dchar[x%n];
				x /= n;
			}
		}

	//�������� ����
	for (int i = 0; i < digits / 2; i++)
	{
		char temp = d[i];
		d[i] = d[digits - i - 1];
		d[digits - i - 1] = temp;
	}

	return digits;
}

int main()
{
	int n;//����
	int num;; //������ ��ȯ�� ����
	int size = 0;
	char ret[512];

	scanf("%d %d", &num, &n);

	size = card_conv(num, n, ret);

	for (int i = 0; i < size; i++)
		printf("%c", ret[i]);
	printf("\n");

	return 0;
}