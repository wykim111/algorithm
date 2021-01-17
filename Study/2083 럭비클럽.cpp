/*
나이가 17세보다 많거나, 몸무게가 80kg 이상이면 성인부이다. 그 밖에는 모두 청소년부이다. 클럽 회원들을 올바르게 분류하라.
*/
#include<stdio.h>
#include<string.h>

int main()
{
	while (1)
	{
		char name[11];
		int age, weight;

		scanf("%s %d %d", name, &age, &weight);

		if (name[0] == '#' && age == 0 && weight == 0)
			break;
		if (age > 17 || weight >= 80)
			printf("%s Senior\n", name);
		else
			printf("%s Junior\n", name);

	}
	return 0;
}