// 8.14 264p 폴리오미노 POLY
/*
#include <iostream>
using namespace std;
#define MOD 10000000

int cache[101][101] = {};
// n개의 정사각형으로 이루어졌고, 맨 위 가로줄에 first개의
// 정사각형을 포함하는 폴리오미노 수를 반환한다.
int poly(int n, int first) {
	// 기저사례 n == first
	if (n == first) return 1;
	// 메모이제이션
	int& ret = cache[n][first];
	if (ret != -1)return ret;
	ret = 0;
	for (int second = 1; second <= n - first; ++second) {
		int add = second + first - 1;
		add *= poly(n - first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T;
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			cache[i][j] = -1;
	cin >> T;
	while (T--) {
		
		int n, sum = 0;
		cin >> n;

		for (int i = 1; i <= n; ++i) {
			sum += poly(n, i);
			sum %= MOD;
		}
		cout << sum << "\n";
	}
}
*/