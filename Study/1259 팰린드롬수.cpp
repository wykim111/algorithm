/*
	�縰����� Ȧ���� ��� ¦���� ���� ������ ����

*/
#include<stdio.h>
#include<string.h>

char str[10];

int main()
{
	
	while (1)
	{
		int len;

		memset(str, sizeof(str), 0x00);
		fgets(str, sizeof(str), stdin);

		if (str[0] == '0')
			break;

		len = strlen(str);
		str[len - 1] = '\0';
		len = strlen(str);
		//printf("len = %d\n", len);
		int flag = 1;
		//Ȧ���� ���
		if (len % 2 == 1)
		{
			int mid = len / 2;

			for (int i = 0; i < mid; i++)
			{
				if (str[i] == str[len - i - 1] && flag == 1)
				{
					continue;
				}
				else //���� ������ ��Ī���� ��ġ���� ���� ��� Ż��
				{
					//printf("i=%d\n", i);
					flag = 0;
					break;
				}
			}

			if (flag == 0)
				printf("no\n");
			else
				printf("yes\n");
		}
		else // ¦���� ��� 123321�� ��� mid-1������ �������� Ž��
		{
			int mid = len / 2;

			for (int i = 0; i <= mid - 1; i++)
			{
				if (str[i] == str[len - i - 1] && flag == 1)
				{
					continue;
				}
				else //���� ������ ��Ī���� ��ġ���� ���� ��� Ż��
				{
					flag = 0;
					break;
				}



			}//i
			if (flag == 0)
				printf("no\n");
			else
				printf("yes\n");
		}
	}
	return 0;
}