//https://algospot.com/judge/problem/read/PICNIC

/*
#include <iostream>
using namespace std;
int C, n, m;
bool areFriends[10][10] = { };
//taken[i] = i번째 학생이 짝을 이미 찾았으면 true아니면 false

int countPairings(bool taken[10]) {
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	//기저 사례: 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료한다.
	if (firstFree == -1)return 1;
	int ret = 0;
	//이 학생과 짝지을 학생을 결정한다.
	for (int pairWith = firstFree + 1; pairWith < n; ++pairWith) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[pairWith] = taken[firstFree] = true;
			ret += countPairings(taken);
			taken[pairWith] = taken[firstFree] = false;
		}
	}
	return ret;
}


int main() {
	bool taken[10] = {};
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> n >> m;
		int a, b;
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		printf("%d\n", countPairings(taken));

		//areFriends 초기화
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				areFriends[j][k] = false;
			}
		}
	}

	return 0;
}
*/