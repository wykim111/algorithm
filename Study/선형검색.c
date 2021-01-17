/*선형 검색(보초법)*/
#include<stdio.h>
#include<stdlib.h>
/*
	1. 검색할 값을 발견하지 못하고 배열의 끝을 지나간 경우
	2. 검색할 값과 같은 요소를 발견한 경우

	N 사이즈 만큼 두어서 인덱스가 N-1까지 탐색하여 키가 존재하지 않으면 N번째에 있는 경우로 -1 리턴
	키를 찾으면 해당 인덱스 리턴
*/
int search(int* a, int n, int key)
{
	int i = 0;
	
	a[n] = key;

	for (i = 0; i < n; i++)
	{
		if (a[i] == key)
			break;
	}
	return i == n ? -1 : i;
}


int main()
{
	int i, nx, ky, idx;
	int* x;
	
	printf("선형검색(보초법)\n");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	
	x = calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; i++)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("검색값 : ");
	scanf("%d", &ky);
	
	idx = search(x, nx, ky);

	if (idx == -1)
		printf("검색에 실패\n");
	else
		printf("%d(은)는 x[%d]에 있습니다\n", ky, idx);
	
	free(x);

	return 0;
}