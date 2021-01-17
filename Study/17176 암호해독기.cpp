/*
	0�� ����, 1 - 26 ���� ���� ���� A ~ Z, 27 - 52 ���� ���� ���� a ~ z�� �ؼ�

	-> �迭 arr[53] �����Ͽ� 0���� 52���� ���� ���ĺ��� �����Ѵ�.
	-> �Է��� ���ڿ��� ���ڸ� �ε����� ���� �����Ϳ� ��ġ ���θ� �ľ�
	-> �� ���� �������� �ش� ������ �÷��׸� ī��Ʈ�Ͽ� ��� 2�̸� �� �ִ� ���̰� �ϳ��� 1�̸� ��ġ���� ���� ��
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int N;
int script[53];
char str[100005];

int main()
{
	int len = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		int num;

		scanf("%d", &num);

		script[num]++;
		//printf("num = %d\n", num);
	}
	while (getchar() != '\n');
	//���ڿ� �Է�
	fgets(str, sizeof(str), stdin);
	len = strlen(str);

	str[len - 1] = '\0';
	len = strlen(str);

	//��ȣ�� �÷��� ī��Ʈ
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			script[0]--;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			script[str[i] - 'A'+1]--;
		}
		else if ('a' <= str[i] && str[i] <= 'z')
		{
			script[str[i] - 'a' + 27]--;
		}
	}
	//ī��Ʈ �÷��� �߿� 1�� ������ ��ȣȭ �� �� ����
	for (int i = 0; i <= 52; i++)
	{
		if (script[i] != 0)
		{
			printf("n\n");
			return 0;
		}
	}
	
	printf("y\n");

	return 0;
}

