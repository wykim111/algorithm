/*
��й�ȣ�� ���ĺ� �ҹ���, �빮��, ����, Ư�����ڷθ� �̷���� �ִ�.
��й�ȣ�� 6���� �̻��̾�� �Ѵ�.
���ڴ� �ϳ� �̻� ���ԵǾ�� �Ѵ�.
���ĺ� �ҹ��ڴ� �ϳ� �̻� ���ԵǾ�� �Ѵ�.
���ĺ� �빮�ڴ� �ϳ� �̻� ���ԵǾ�� �Ѵ�.
Ư�� ���ڴ� �ϳ� �̻� ���ԵǾ�� �Ѵ�. ����� �� �ִ� Ư�� ���ڴ� !@#$%^&*()-+�̴�.

1. ����, �ҹ���, �빮��,Ư������ ī��Ʈ �÷���
2. Ư�����ڴ� �迭�� ����
3. �ش� ī��Ʈ �÷��� ������ 0�� ��� ��й�ȣ�� �� ���� ���Ƿ� ī��Ʈ
*/

#include<stdio.h>
#include<string.h>

int N;
int upperFlag = 0, lowerFlag = 0, digitFlag = 0, specialFlag = 0;
char str[101] = { 0, };
char special[12] = { '!','@','#','$','%','^','&','*','(',')','-','+' };

int password[4] = { 0, };

int main()
{
	int len = 0;
	int ret = 0;


	scanf("%d", &N);
	scanf("%s", str);

	len = strlen(str);

	for (int i = 0; i < len; i++)
	{
		//�������� �˻�
		if (str[i] >= '0' && str[i] <= '9')
		{
			digitFlag=0;
			password[digitFlag]++;
		}//���ĺ� ��ҹ��� �˻�
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			lowerFlag = 1;
			password[lowerFlag]++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			upperFlag=2;
			password[upperFlag]++;
		}
		else
		{//Ư������
			for (int j = 0; j < sizeof(special) / sizeof(char); j++)
			{
				if (special[j] == str[i])
				{
					specialFlag = 3;
					password[specialFlag]++;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
	//	printf("password[%d] = %d\n", i, password[i]);
		if (password[i] == 0)
		{
			ret++;
		}
	}
	//���̰� 6�̻��̰� ������ ���ڸ� ä���� �ϴ� ���
	if (len + ret >= 6)
	{
		printf("%d\n", ret);
	}
	else
	{
		printf("%d\n", 6-len);
	}
	
	return 0;
}