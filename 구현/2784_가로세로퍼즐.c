/*
	1. 중복문자 제거
	2. 순열의 원리 활용
	3. 문자열이 다 쓰였는지 가로,세로 체크
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str[10][10];
int index_size = 0;
int check_str[10];

int ret_perm[10];//순열
int visit[10];//순열

char map[10][10];
int flag = 1;

void bubbleSort(int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (strcmp(str[j], str[j + 1]) > 0)
			{
				char temp[4];

				strcpy(temp, str[j]);
				strcpy(str[j], str[j + 1]);
				strcpy(str[j + 1], temp);

			}
		}
	}
}
#if 0
int remove_dup(char* pStr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(pStr, str[i]) == 0)
		{
			return 1;
		}
	}

	return 0;
}
#endif
int check_width_weight()
{
	int i, j;
	char extract_str[6][4];

	memset(check_str, 0, sizeof(check_str));
	for (int i = 0; i < 6; i++)
	{
		memset(extract_str[i], 0, sizeof(char)*4);
	}
	//6개의 문자열 추출 가로 3개 세로 3개
	//가로 3개 문자열 추출 및 체크
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			extract_str[i][j] = map[i][j];
		}
		extract_str[i][j] = '\0';
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < index_size; j++)
		{

			if (strcmp(extract_str[i], str[j]) == 0 && !check_str[j])
			{
				//printf("1. extract_str = %s str[%d] = %s\n", extract_str[i], j, str[j]);
				check_str[j] = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		memset(extract_str[i], 0, sizeof(char) * 4);
	}
	//세로 3개 문자열 추출 및 체크
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			extract_str[i][j] = map[j][i];
		}
		extract_str[i][j] = '\0';

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < index_size; j++)
		{

			if (strcmp(extract_str[i], str[j]) == 0 && !check_str[j])
			{
				//printf("2. extract_str = %s str[%d] = %s\n", extract_str[i],j,str[j]);
				check_str[j] = 1;
				break;
			}
		}
	}


	for (int i = 0; i < index_size; i++)
	{
		//printf("index_size = %d\n", index_size);
		if (check_str[i] == 0)
			return 0;
	}

	return 1;
}

void perm(int dep, int size)
{
	if (dep == 3)
	{
#if 0
		printf("순열:");
		for (int i = 0; i < 3; i++)
		{
			printf(" %d ", ret_perm[i]);
		}
		printf("\n");
#endif
		for (int i = 0; i < 3; i++)
		{
			strcpy(map[i], str[ret_perm[i]]);
		}

#if 0
		printf("\n3x3 배열 적용\n");
		for (int i = 0; i < size; i++)
		{
			printf("%s\n", map[i]);
		}

#endif

#if 1
		if (check_width_weight() == 1)
		{
			for (int i = 0; i < 3; i++)
			{
				printf("%s\n", map[i]);
			}
			exit(0);
		}

		flag = 0;
#endif
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (visit[i] == 1)
			continue;
		visit[i] = 1;
		ret_perm[dep] = i;
		perm(dep + 1, size);
		visit[i] = 0;
	}
}


int main()
{
	for (int i = 0; i < 6; i++)
	{
		char temp_str[10];

		memset(temp_str, 0, sizeof(temp_str));
		scanf("%s", temp_str);


		strcpy(str[index_size], temp_str);
		index_size++;
	}

	//bubbleSort(index_size);


	perm(0, index_size);

	/*
	for (int i = 0; i < index_size;i++)
	{
		printf("%s\n", str[i]);
	}
	*/

	if (flag == 0)
	{
		printf("0\n");
	}

	return 0;
}
