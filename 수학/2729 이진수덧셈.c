/*
0 + 0 = 0
1 + 0 = 1
0 + 1 = 1
1 + 1 = 10
1 + 1 + 1 = 11


- 문자열로 구현
- 둘 중 긴 문자열 길이까지 반복
- carry 변수 활용
- 문자열의 구성 상 0번쨰가 제일 큰 자릿수이므로 가장 마지막 자리부터 연산
- carry가 발생하면 그 수를 carry 변수에 저장

*/
#include<stdio.h>
#include<string.h>

int T;
char str1[82], str2[82], total[82];
int numStr1[81], numStr2[81];


void reverseStr()
{
	int strLen = strlen(total);

	for (int i = 0; i < strLen/2; i++)
	{
		char temp = total[i];
		total[i] = total[strLen - 1 - i];
		total[strLen - 1 - i] = temp;
	}
}
int allZeroCheck()
{
	int strLen = strlen(total);
	int offset = 0;
	//offset의 원리로 맨 앞이 0인 경우 연속으로 0이 몇개있는지 체크
	if (total[0] == 0)
	{
		for (int i = 1; i < strLen; i++)
		{
			if (total[i] == '0')
			{
				offset++;
			}
			else
			{
				break;
			}

		}
	}




	return offset;
}

int max(int n1, int n2)
{
	if (n1 > n2)
	{
		return n1;
	}

	return n2;
}

int main()
{
	scanf("%d", &T);
	getchar();

	while (T--)
	{
		int len1 = 0, len2 = 0;
		int sum = 0,strLen = 0;
		int carry = 0;

		memset(str1, 0, sizeof(str1));
		memset(str2, 0, sizeof(str2));
		memset(total, 0, sizeof(total));

		scanf("%s %s", str1, str2);
		getchar();

		len1 = strlen(str1);
		len2 = strlen(str2);


		int idx = 0;
		//끝자리부터 비교
		//for문의 조건문이 '<='인 이유는 carry가 발생하여 
		//올림수를 표현해야하므로
		for (idx = 0; idx <= len1 || idx <= len2; idx++)
		{
			int num1 = 0, num2 = 0;

			//각 끝자리를 숫자로 변환
			if (idx >= len1)
			{

			}
			else
			{
				num1 = str1[strlen(str1) - idx - 1] - '0';
			}


			if (idx >= len2)
			{

			}
			else
			{
				num2 = str2[strlen(str2) - idx - 1] - '0';
			}

		

			//끝자리부터 연산
			sum = num1 + num2 + carry;
			carry = sum / 2;

			if (idx == (max(len1, len2)) && sum == 0)
			{
				break;
			}


			total[idx] = (sum % 2) + '0';

		}
		total[idx] = '\0';
	
		reverseStr();

		//맨 앞자리가 0인 경우 앞으로 1칸씩 당긴다.
		strLen = strlen(total);
		while (total[0] == '0' && strlen(total) > 1)
		{
			if (total[0] == '0')
			{
				
				for (int i = 0; i < strLen-1; i++)
				{
					total[i] = total[i+1];
				}
				total[strLen - 1] = '\0';
			}

		}


		printf("%s\n", total);


		
	}

	return 0;
}
