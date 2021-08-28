/*
	먼저 암호화 할 문자열을 1,1부터 위에서 아래 순서대로 채운다. 
	그리고 가장 밑의 행을 채운 후에는 오른쪽 열에서 다시 같은 과정을 반복
	이제 왼쪽-> 오른쪽, 오른쪽-> 왼쪽, 왼쪽->오른쪽 ... 으로 읽으면서 다시 문자열을 만든다
*/
#include<stdio.h>
#include<string.h>

int K;
char str[202];
int len = 0;
char copy[202][202];

void read(int row_size,int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		//오른쪽에서 왼쪽으로
		if (i % 2 == 1)
		{
			for (int j = 0; j < col_size/2; j++)
			{
				char temp = copy[i][j];
				copy[i][j] = copy[i][col_size - j - 1];
				copy[i][col_size - j - 1] = temp;
			}
		}
	
	}

	for (int i = 0; i < col_size; i++)
	{
		for (int j = 0; j < row_size; j++)
		{
			printf("%c", copy[j][i]);
		}
	}

}

int main()
{
	int row = 0;
	int col = 0;

	scanf("%d", &K);
	scanf("%s", str);

	len = strlen(str);

	row = len / K;
	col = K;

	/*
		for(i = 0부터 문자열 순으로)
		{
			if(c > 마지막 열)
			{
				c = 0;
				r++;
			}
			copy[r][c] = str[i]

		}
	*/
	int r = 0, c = 0;
	for (int i = 0; i < len; i++)
	{
		copy[r][c] = str[i];

		c++;

		if (c == col)
		{
			c = 0;
			r++;
		}

	}

	read(row, col);
	
	return 0;
}
