/*
	https://sejinik.tistory.com/46
	dp ��͸� ���� ���� �ذ� ����
	dp[n���� ����][����ð�]
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, d[1010][1010];
vector<pair<int, int>> vt;

int go(int idx, int t) {
	printf("�����ε���=%d, ���� �ð� = %d\n", idx, t);
	if (idx == n || t > 1000) return 0;

	int&ret = d[idx][t];
	if (ret != -1) return ret;

	int ptime = vt[idx].first;
	int pcost = vt[idx].second;

	ret = max(ret, go(idx + 1, t));
	if (t <= ptime) ret = max(ret, go(idx + 1, t + 1) + pcost);
	
	return ret;
}
int main() 
{
	memset(d, -1, sizeof(d));
	scanf(" %d", &n);
	vt.resize(n);
	for (int i = 0; i < n; i++) scanf(" %d %d", &vt[i].first, &vt[i].second);
	sort(vt.begin(), vt.end());
	/*
	for (int i = 0; i < vt.size(); i++)
	{
		printf("%d %d\n", vt[i].first, vt[i].second);
	}
	*/
	printf("%d\n", go(0, 1));
	
	printf("d ������ ��ȸ\n");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 70; j++)
		{
			printf("%d ", d[i][j]);
		}
	}
	
	return 0;
}
