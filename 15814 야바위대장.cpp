#include<stdio.h>
#include<string.h>


void swap(char* s, int idx1, int idx2)
{
	char temp;

	temp = s[idx1];
	s[idx1] = s[idx2];
	s[idx2] = temp;
}

int main()
{
	char str[100];
	int T;

	scanf("%s", str);
	scanf("%d", &T);

	while (T--)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		swap(str,a, b);
	}
	printf("%s\n", str);

	return 0;
}