//https://algospot.com/judge/problem/read/PACKING
// 9.2 여행 짐 싸기 PACKING (중)

/*
// 결국 전부 돌아보고 최대값 구하는 코드 시작복잡도 O(nw)
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, W;
// 가져가고 싶은 물건 1~100, 캐리어 용량 1~1000
int cache[1001][100] = {};
string s[101]; // 물건이름 1~20
int volume[101], need[101]; // 부피 1~1000, 원하는정도 1~1000

// 캐리어 용량이 capacity만큼 남았을때 남은 item중 물건을 싸서 얻을 수 있는 최대 절박도
int pack(int capacity, int item) {
	// 기저 사례 : 더 담을 물건이 없을 때
	if (item == N) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1)return ret;
	// 이 물건을 담지 않을 경우
	ret = pack(capacity, item + 1);
	// 이 물건을 담을 경우
	if (capacity >= volume[item])
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

// pack(capacity, item)이 선택한 물건들의 목록을 picked에 저장한다.
// 담았을 경우 item을 담았는지 안담았는지 item == item + 1을 통해 알 수 있음 담았을 경우 capcity가 변화하기 때문
void reconstruct(int capacity, int item, vector<string>& picked) {
	// 기저 사례 : 모든 물건을 다 고려했음
	if (item == N)return;
	if (pack(capacity, item) == pack(capacity, item + 1)) {
		reconstruct(capacity, item + 1, picked);
	}
	else {
		picked.push_back(s[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 1001; ++i)
			for (int j = 0; j < 101; ++j)
				cache[i][j] = -1;
		cin >> N >> W;
		for (int i = 0; i < N; ++i) {
			cin >> s[i] >> volume[i] >> need[i];
		}
		vector<string> picked;
		
		cout << pack(W, 0);
		reconstruct(W, 0, picked);
		cout << " " << picked.size() << "\n";
		for (int i = 0; i < picked.size(); ++i)
			cout << picked[i] << "\n";
	}
	return 0;
}
*/