#include<stdio.h>
#include<string.h>

char str[1001];
char alphabet[26];
char cipher[26];
char ret[1001];

void setPassword()
{
	int i, j;

	//���ĺ� ����
	for (i = 0; i < 26; i++)
	{
		alphabet[i] = i + 'A';
		cipher[i] = i + 'A';
	}

	//ī�̻縣 ����
	for (i = 0; i < 3; i++)
	{
		int temp = cipher[0];

		for (j = 0; j < 25; j++)
		{
			cipher[j] = cipher[j + 1];
		}
		cipher[j] = temp;
	}
}

int main()
{
	int len = 0;
	int idx = 0;
	scanf("%s", str);//��ȯ�� ��ȣ

	len = strlen(str);

	setPassword();
	/*
	for (int i = 0; i < 26; i++)
	{
		printf("%c ", cipher[i]);
	}
	*/

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			//�ش�Ǵ� ��ȣ���� ��ġ�ϴ� ��ȣ���̺� �ε����� ã�� ���
			if (str[i] == cipher[j])
			{
				ret[idx++] = alphabet[j];
			}
		}
	}
	printf("%s", ret);

	return 0;

}