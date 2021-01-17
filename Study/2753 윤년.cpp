/*
	윤년
	-> ((년도%4==0) && ((년도%100 !=0) || (년도%400 == 0))== true)

*/

#include<iostream>
#include<cstdio>

int main()
{
	int year;
	bool ret = false;
	scanf("%d", &year);

	if (((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))) == true)
	{
		ret = true;
	}
	printf("%d\n", ret);

	return 0;
}