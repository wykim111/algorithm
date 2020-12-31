#include<stdio.h>

double arr[5];
double maxRet = 0;
int cntRet = 0;

/*
	swap을 이용하여 temp로 회전
*/
void rotate(int idx1,int idx2,int idx3, int idx4)
{
	//90도 회전
	double temp;

	temp = arr[idx3];
	arr[idx3] = arr[idx4];
	arr[idx4] = arr[idx2];
	arr[idx2] = arr[idx1];
	arr[idx1] = temp;
 
}



double cal()
{

	return ((double)arr[1] / (double)arr[3]) + ((double)arr[2] / (double)arr[4]);
}

int main()
{
	int A, B, C, D;

	scanf("%d %d", &A, &B);
	scanf("%d %d", &C, &D);
	
	arr[1] = (double) A;
	arr[2] = (double)B;
	arr[3] = (double)C;
	arr[4] = (double)D;

	//최초 세팅

	maxRet = cal();
	cntRet = 0;

	//시간이 걸렸던 이유 
	// 4번 회전하면 최초 설정이랑 같아지는데
	// 이 경우 처음 input 시(0번째) 최초 설정과 같기때문이다.
	for (int i = 1; i < 4; i++)
	{
		double temp;

		rotate(1,2,3,4);
		temp = cal();

		if (maxRet < temp)
		{
			maxRet = temp;
			cntRet = i;
		}

	/*
		printf("%lf %lf\n", arr[1], arr[2]);
		printf("%lf %lf\n", arr[3], arr[4]);
		printf("%lf\n", temp);


		printf("\n");
	*/
	}

	printf("%d\n", cntRet);


	return 0;
}
