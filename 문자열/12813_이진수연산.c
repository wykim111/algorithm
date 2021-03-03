/*
A & B, A | B, A ^ B, ~A, ~B

*/

#include<stdio.h>
#include<string.h>

 char str1[100001] = { 0, };
 char str2[100001] = { 0, };
 char ret[100001] = { 0, };

int main()
{

	int len1 = 0, len2 = 0;

	scanf("%s %s", str1, str2);

	
	len1 = strlen(str1);
	len2 = strlen(str2);

	for (int i = 0; i < len1; i++)
	{
		ret[i] = (str1[i] & str2[i]);
	}
	printf("%s\n",ret);

	for (int i = 0; i < len1; i++)
	{
		ret[i] = (str1[i] | str2[i]);
	}
	printf("%s\n", ret);

	for (int i = 0; i < len1; i++)
	{
		//XOR 둘다 같으면 0 둘이 다르면 1
		if (str1[i] != str2[i])
		{
			ret[i] = '1';
		}
		else
		{
			ret[i] = '0';
		}
	}
	printf("%s\n", ret);

	//~A
	for (int i = 0; i < len1; i++)
	{
		if (str1[i] == '0')
		{
			ret[i] = '1';
		}
		else
		{
			ret[i] = '0';
		}
	}

	printf("%s\n", ret);


	//~B
	for (int i = 0; i < len2; i++)
	{
		if (str2[i] == '0')
		{
			ret[i] = '1';
		}
		else
		{
			ret[i] = '0';
		}
	}

	printf("%s\n", ret);
	
	return 0;
}
