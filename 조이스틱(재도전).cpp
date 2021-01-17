#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// �����̴µ� �ʿ��� �ּ�:
int Distance[20][20];   // ù��°���� �ι�°�� ���� �Ÿ�
bool isarrived[20];
bool isExist[20];       // �����ϴ���

						// ���� curIndex���� ������ġ�� ���� �ǰ�,
						// ������� ���� distance�� curDist�̰�
						// ������� �Ϸ�� Count�� curCount
						// �Ϸ�Ǿ���� ������ maxCount
int TotalMinDistance = 10000;
int stringSize;

void recursive(int curIndex, int curDist, int curCount, int maxCount) {

#ifdef debug
	cout << curIndex << " " << curDist << " " << curCount << " " << maxCount << endl;
#endif
	// �̹� �Դ����̶�� return
	if (isarrived[curIndex])
		return;

	// dist�� �ʰ���� return
	if (curDist > TotalMinDistance)
		return;

	// ��� �Ϸ� �Ǿ��ٸ� update �� return
	if (curCount >= maxCount) {

		cout << curIndex << " " << maxCount << endl;
		if (curDist < TotalMinDistance)
			TotalMinDistance = curDist;
		return;
	}



	isarrived[curIndex] = true;

	// ������ġ���� ������ �� �߿���, �����ִ°� ��� ������
	for (int i = 0; i < stringSize; i++) {
		if (isExist[i] && !isarrived[i]) {
			recursive(i, curDist + Distance[curIndex][i], curCount + 1, maxCount);
			isarrived[i] = false;
		}
	}

}
int solution(string name) {
	int answer = 0;
	stringSize = name.size();
	memset(isarrived, false, sizeof(isarrived));
	memset(isExist, false, sizeof(isExist));

	// �����ϴ°��� �ε������� �����´�
	int TotCount = 0;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') {
			TotCount++;
			isExist[i] = true;
		}
	}

	// �ش� start���� end�� ���� �ּҰŸ��� ���Ѵ�.
	for (int startNum = 0; startNum < name.size(); startNum++) {
		for (int endNum = 0; endNum < name.size(); endNum++) {
			int mindist = min(abs(startNum - endNum), stringSize - abs(startNum - endNum));
			Distance[startNum][endNum] = mindist;
			Distance[endNum][startNum] = mindist;
		}
	}

	recursive(0, 0, 1, TotCount);

	// ���ĺ��� ����µ� �ʿ��� Ŭ���� ���ϱ�
	for (int i = 0; i < name.size(); i++) {
		int Count = min(abs(name[i] - 'A'), abs('Z' - name[i] + 1));
		answer += Count;
	}

#ifdef debug
	cout << "�̵��Ÿ�:" << TotalMinDistance << " �ּ�Ŭ����:" << answer << endl;
#endif
	return answer + TotalMinDistance;
}
