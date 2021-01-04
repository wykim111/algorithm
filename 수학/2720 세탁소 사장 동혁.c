/*
	제일 큰 액수 순으로 나누어 갯수 파악
*/

#include<stdio.h>


int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		int num;
		double Quarter = 25, Dime = 10, Nickel = 5, Penny = 1;
		int cntQuarter = 0, cntDime = 0, cntNickel = 0, cntPenny = 0;

		scanf("%d", &num);

		/* 쿼터 */
		cntQuarter = num / Quarter;

		num -= (cntQuarter * Quarter);

		/* 다임 */
		cntDime = num / Dime;

		num -= (cntDime * Dime);

		/* 니켈 */
		cntNickel =  num / Nickel;

		num -= (cntNickel * Nickel);

		/* 페니 */
		cntPenny = num / Penny;

		num -= (cntPenny * Penny);


		printf("%d %d %d %d\n", cntQuarter, cntDime, cntNickel, cntPenny);

	}

	return 0;
}
