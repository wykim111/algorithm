/*
	���� Ž�� ����
	�� ���ĺ��� ���� 1���� 9���� ���� �� ���� �����̸� �ȵ� 

	�̶�, �� ���ĺ� �빮�ڸ� 0���� 9������ ���� �� �ϳ��� �ٲ㼭 N���� ���� ���ϴ� �����̴�. 
	���� ���ĺ��� ���� ���ڷ� �ٲ�� �ϸ�, �� �� �̻��� ���ĺ��� ���� ���ڷ� �ٲ������ �� �ȴ�.

	1. �� ���ĺ� ����
	2. ���ĺ��߿� �ߺ��Ȱ� �ش� ��ġ �ε��� �����ϸ�, �ߺ����� ������ -1 ����
	3. ������ �� ���ĺ� 0���� 9���� ����(ù��°���ڿ� 0���� 9���� ���� �ι�° ���ڿ� ù���� ������ ���� �����ϰ� ����)
	4. �ִ� ��
*/
#include<stdio.h>
#include<string.h>

int N;
char str[11][11];
char alphabet[26] = { 0, };
int num[10];
int idx = 0;
int visit[10] = { 0, };
int retMax;

int checkAlphabet(char ch)
{
	for (int i = 0; i < idx; i++)
	{
		if (alphabet[i] == ch)
		{
			return i;
		}
	}

	return -1;
}


void perm(int dep)
{
	if (dep == idx)
	{
		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			int cal = 0;
			int len = strlen(str[i]);

			for (int j = 0; j < len; j++)
			{
				cal = (cal * 10) + num[checkAlphabet(str[i][j])];
			}
			sum += cal;
		}

		if (sum > retMax)
		{
			retMax = sum;
		}
	}


	for (int i = 0; i < idx; i++)
	{
		if (visit[i] == 1)
			continue;

		visit[i] = 1;
		num[dep] = 9 - i;
		perm(dep + 1);
		visit[i] = 0;
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", str[i]);

		while (getchar() != '\n'); //���� ����
	}
	//���ĺ� üũ
	for (int i = 0; i < N; i++)
	{
		//NULL���� Ž��
		for (int j = 0; str[i][j] != '\0'; j++)
		{
			if (checkAlphabet(str[i][j]) == -1)
			{
				alphabet[idx++] = str[i][j];
			}
		}
	}
	/*
	for (int i = 0; i < idx; i++)
	{
		printf("%c\n", alphabet[i]);
	}
	*/
	perm(0);

	printf("%d\n", retMax);
	
	return 0;
}