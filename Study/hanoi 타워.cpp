#include<stdio.h>

void hanoi(int num, char from, char to, char other)
{
	//BaseCase 1
	if (num == 0)
		return;
	hanoi(num - 1, from, other, to);
	printf("%c¿¡¼­ %c·Î ¿Å±ä´Ù\n", from, to);
	hanoi(num - 1, other, to, from);
}
int main()
{
	hanoi(3, 'A', 'B', 'C');

	return 0;
}
