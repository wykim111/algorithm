#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// 움직이는데 필요한 최소:
int Distance[20][20];   // 첫번째에서 두번째로 가는 거리
bool isarrived[20];
bool isExist[20];       // 존재하는지

						// 현재 curIndex에서 다음위치를 고르면 되고,
						// 현재까지 쌓인 distance는 curDist이고
						// 현재까지 완료된 Count는 curCount
						// 완료되어야할 개수는 maxCount
int TotalMinDistance = 10000;
int stringSize;

void recursive(int curIndex, int curDist, int curCount, int maxCount) {

#ifdef debug
	cout << curIndex << " " << curDist << " " << curCount << " " << maxCount << endl;
#endif
	// 이미 왔던곳이라면 return
	if (isarrived[curIndex])
		return;

	// dist가 초과라면 return
	if (curDist > TotalMinDistance)
		return;

	// 모두 완료 되었다면 update 후 return
	if (curCount >= maxCount) {

		cout << curIndex << " " << maxCount << endl;
		if (curDist < TotalMinDistance)
			TotalMinDistance = curDist;
		return;
	}



	isarrived[curIndex] = true;

	// 현재위치에서 가야할 곳 중에서, 갈수있는곳 모두 가보기
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

	// 가야하는곳의 인덱스들을 가져온다
	int TotCount = 0;
	for (int i = 0; i < name.size(); i++) {
		if (name[i] != 'A') {
			TotCount++;
			isExist[i] = true;
		}
	}

	// 해당 start에서 end로 가는 최소거리를 구한다.
	for (int startNum = 0; startNum < name.size(); startNum++) {
		for (int endNum = 0; endNum < name.size(); endNum++) {
			int mindist = min(abs(startNum - endNum), stringSize - abs(startNum - endNum));
			Distance[startNum][endNum] = mindist;
			Distance[endNum][startNum] = mindist;
		}
	}

	recursive(0, 0, 1, TotCount);

	// 알파벳을 만드는데 필요한 클릭수 구하기
	for (int i = 0; i < name.size(); i++) {
		int Count = min(abs(name[i] - 'A'), abs('Z' - name[i] + 1));
		answer += Count;
	}

#ifdef debug
	cout << "이동거리:" << TotalMinDistance << " 최소클릭수:" << answer << endl;
#endif
	return answer + TotalMinDistance;
}
