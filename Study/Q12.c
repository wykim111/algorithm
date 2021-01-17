#include<stdio.h>
#define VMAX 21 //시력의 최댓값은 2.1 * 10

typedef struct {
	char name[20];
	int height;
	double vision;
}PhysCheck;

/*키의 평균값을 구합니다*/
double ave_height(const PhysCheck dat[], int n)
{
	int i;
	double sum = 0;

	for (i = 0; i < n; i++)
	{
		sum += dat[i].height;
	}

	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
	/*
		사람수만큼 돌면서 시력을 검사한다
		시력에 10을 곱한 데이터를 인덱스로 하여 배열에 저장한다.
	*/
	for (int i = 0; i < VMAX; i++)
	{
		dist[i]=0;
	}

	for (int i = 0; i < n; i++)
	{
		dist[(int)(dat[i].vision * 10)]++;
	}
}

int main()
{
	int i;
	PhysCheck x[] = {
		{"박현규",162,0.3},
		{"함진아",173,0.7},
		{"최윤미",175,2.0},
		{"홍연의",171,1.5},
		{"이수진",168,0.4},
		{"최윤미",174,1.2},
		{"최윤미",169,0.8}
	};
	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	puts("■□■ 신체검사표 ■□■");
	puts("이름		키		시력");
	puts("------------------------------");

	for (i = 0; i < nx; i++)
		printf("% - 18.18s % 4d % 5.1f \n", x[i].name, x[i].height, x[i].vision);
	printf("\n평균 키: %5.1fcm\n", ave_height(x, nx));

	dist_vision(x, nx, vdist); /* 시력의 분포를 구합니다. */

	printf("\n시력의 분포\n");
	for (int i = 0; i < VMAX; i++) {
		printf("%3.1f ~ : ", i / 10.0);
		for (int j = 0; j < vdist[i]; j++)
			putchar('*');
		putchar('\n');
	}
}