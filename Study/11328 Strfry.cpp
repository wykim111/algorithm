#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;

void BubbleSort(char* s,int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (s[j] > s[j + 1])
			{
				char temp;
				temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
			}
		}
	}
}
int main()
{
	

	scanf("%d", &N);

	while (N--)
	{
		char str1[1001], str2[1001];
		int alphabet1[26], alphabet2[26];
		int flag = 1;

		memset(alphabet1, 0, sizeof(alphabet1));
		memset(alphabet2, 0, sizeof(alphabet2));
		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));

		scanf("%s %s", str1, str2);

		int len = strlen(str1);

		for (int i = 0; i < len; i++)
		{
			alphabet1[str1[i]-'a']++;
			alphabet2[str2[i]-'a']++;
		}


		
		for (int i = 0; i < 26 ; i++)
		{
			if (alphabet1[i] != alphabet2[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Impossible\n");
		}

	}

	

	return 0;

}