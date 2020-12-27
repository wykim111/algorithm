/*
W(1) = 1 * T(2) = 1 *(1+2) = 3
W(2) = 2 * T(3) =W(1) +  2* (1+2+3) = 15
W(3) = 3 * T(4) =W(2) +  3 * (1+2+3+4) = 45
W(4) = 4 * T(5) = W(3) + 4 * (1+2+3+4+5) = 105

W(n) = Sum[k=1..n; k*T(k+1)]
*/

#include<stdio.h>

int T;

int go(int dep)
{
	if (dep == 1)
	{
		int Tn = 0;

		for (int i = 1; i <= 2; i++)
		{
			Tn += i;
		}

		return dep * Tn;
	}
	
	int Tn = 0;

	for (int i = 1; i <= dep + 1; i++)
	{
		Tn += i;
	}


	return go(dep - 1) + (dep * Tn);
}

int main()
{
	scanf("%d", &T);

	while (T--)
	{
		int num;

		scanf("%d", &num);
	
		printf("%d\n", go(num));
	}

	return 0;
}
