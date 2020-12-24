/*
	분모가 같은 경우 
		분자만 단순히 더함
	분모가 다른 경우 
		분모 A와 분자 A에 최대공약수로 분모 B를 나눈 몫을 곱한다
		분모 B와 분자 B에 최대공약수로 분모 A를 나눈 몫을 곱한다
	              
*/

#include<stdio.h>
#include<math.h>

int denominatorA, denominatorB, denominatorC;//분모 A,B
int numeratorA, numeratorB, numeratorC;//분자 A,B

int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a%b);
}




int main()
{
	int numGCD;
	int denominatorTempA, denominatorTempB;//분모 A,B
	int numeratorTempA, numeratorTempB;//분자 A,B
	// input 분자, 분모
	scanf("%d %d",&numeratorA,&denominatorA);
	scanf("%d %d", &numeratorB, &denominatorB);

	numGCD = GCD(denominatorA, denominatorB);

	//분모 연산
	denominatorTempA = denominatorA *(denominatorB / numGCD);
	denominatorTempB = denominatorB * (denominatorA / numGCD);

	//분자 연산
	numeratorTempA = numeratorA * (denominatorB / numGCD);
	numeratorTempB = numeratorB * (denominatorA / numGCD);

	
	denominatorC = denominatorTempA;//B도 연산하였기 때문에 denominatorB 가능
	numeratorC = numeratorTempA + numeratorTempB;

	//기약분수
	numGCD = GCD(numeratorC, denominatorC);
	printf("%d %d\n", numeratorC/numGCD, denominatorC/numGCD);


	return 0;
}
