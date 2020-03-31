// https://www.algospot.com/judge/problem/read/GRADUATION
/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int MAXN = 12;
int n, k, m, l;

// i번째 과목의 선수과목의 집합
int pre[MAXN];
// i번째 학기에 신설되는 과목의 집합
int classes[10];
int cache[10][1 << MAXN];

int bitCount(int num) {
	int cnt = 0;
	while (num) {
		cnt += num & 1;
		num = num >> 1;
	}
	return cnt;
}

int graduate(int semester, int taken) {
	// 기저 사례: k개 이상의 과목을 이미 들은 경우
	if (bitCount(taken) >= k)return 0;
	// 기저 사례 : m학기가 전부 지난 경우
	if (semester == m) return INF;
	int& ret = cache[semester][taken];
	if (ret != -1)
		return ret;
	ret = INF;
	// 이번 학기에 들을 수 있는 과목 중 아직 듣지 않은 과목들을 찾는다
	int canTake = (classes[semester] & ~taken);
	// 선수 과목을 다 듣지 않은 과목들을 걸러낸다.
	for (int i = 0; i < n; ++i) {
		if ((canTake & (1 << i)) &&
			(taken & pre[i]) != pre[i]) {
			canTake &= ~(1 << i);
		}
	}
	// 이 집합은 모든 부분집합을 순회한다
	for (int take = canTake; take > 0; take = ((take - 1) & canTake)) {
		// 한 학기에 l과목까지만 들을 수 있다
		if (bitCount(take) > l)continue;
		ret = min(ret, graduate(semester + 1, taken | take) + 1);
	}
	// 이번 학기 아무것도 듣지 않는 경우
	ret = min(ret, graduate(semester + 1, taken));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		memset(pre, 0, sizeof pre);
		memset(classes, 0, sizeof classes);
		memset(cache, 0xff, sizeof cache);
		cin >> n >> k >> m >> l;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a;
			while (a--) {
				cin >> b;
				pre[i] |= 1 << b;
			}
		}
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a;
			while (a--) {
				cin >> b;
				classes[i] |= 1 << b;
			}
		}
		int res = graduate(0, 0);
		if (res == INF)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << "\n";
	}
	return 0;
}
*/