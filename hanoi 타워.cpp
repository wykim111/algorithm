#include<stdio.h>

void hanoi(int num, char from, char to, char other)
{
	//BaseCase 1
	if (num == 0)
		return;
	hanoi(num - 1, from, other, to);
	printf("%c에서 %c로 옮긴다\n", from, to);
	hanoi(num - 1, other, to, from);
}
int main()
{
	hanoi(3, 'A', 'B', 'C');

	return 0;
}