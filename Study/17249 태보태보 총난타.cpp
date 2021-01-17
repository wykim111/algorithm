#include<stdio.h>
#include<string.h>
char str[1001];
int main()
{
	int len = 0;
	int left = 0, right = 0;
	int leftHands = 0, rightHands = 0;

	scanf("%s", str);
	
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '(')
			left = i;
		if (str[i] == ')')
			right = i;
	}

	for (int i = 0; i < left; i++)
	{
		if (str[i] == '@')
			leftHands++;
	}
	for (int i = right+1; i < strlen(str); i++)
	{
		if (str[i] == '@')
			rightHands++;
	}
	printf("%d %d\n", leftHands, rightHands);

	return 0;
}