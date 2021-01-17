#include<stdio.h>
#include<string.h>

char* wyStrStr(char* s1, char* s2)
{
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	int i,j;
	char* p_Str;
	/*
	for (; *s1 != '\0'; s1++)
	{
		if (*s1 == *s2)
		{
			for ( i = 1; *(s1 + i) == *(s2 + i) && i < size2; i++)
			{

			}

			if (i == size2)
			{
				return s1;
			}
		}
	}
	*/
	for (i=0; s1[i] != '\0'; i++)
	{
		
		if (s1[i] == s2[0])
		{
			for (j = 1; s1[i+j] == s2[j] && j < size2; j++)
			{
			
			}

			if (j == size2)
			{
				printf("i = %d¹ø¤ŠÁøÀÔ\n",i);
				p_Str = (s1 + i);
				return p_Str;
			}
		}
	}
	return NULL;
}
int main()
{
	char str1[30];
	char str2[30];
	char* ret;

	scanf("%s", str1);
	scanf("%s", str2);


	ret = wyStrStr(str1, str2);

	if (ret == NULL)
	{
		printf("Not Find");
	}
	else
	{
		printf("%s", ret);
	}
	return 0;
}