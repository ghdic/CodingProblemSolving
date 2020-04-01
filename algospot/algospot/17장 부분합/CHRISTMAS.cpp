//https://www.algospot.com/judge/problem/read/CHRISTMAS
// 크리스마스 인형

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 20091101;
const int MAXN = 100001;

// d[]의 부분 합 배열 psum[]과 k가 주어질 때, 몇 가지 방법으로 살 수 있는지 반환한다.
// psum[]의 첫 번째 원소 전에 0을 삽입했다고 가정한다
int waysToBuy(const vector<int>& psum, int k) {
	int ret = 0;
	vector<long long> cnt(k, 0);
	for (int i : psum)
		cnt[i]++;
	// 두 번 이상 본 적 있다면 이 값 중 두 개를 선택하는 방법의 수를 더한다.
	for (int i = 0; i < k; ++i)
		if (cnt[i] >= 2)
			ret = (ret + ((cnt[i] * (cnt[i] - 1)) / 2)) % MOD; // nC2 더함
	return ret;
}

// d[]의 부분 합 배열 psum[]과 k가 주어질 때, 겹치기 않게 몇 번이나 살 수 있는지 반환한다.
// psum[]의 첫 번째 원소 전에 0을 삽입했다고 가정 한다.
int maxBuys(const vector<int>& psum, int k) {
	// ret[i]=첫 번째 상자부터 i번째 상자까지 고려했을 때 살 수 있는 최대 횟수
	vector<int> ret(psum.size(), 0);
	// prv[s]=psum[]이 s였던 마지막 위치
	vector<int> prv(k, -1);
	for (int i = 0; i < psum.size(); ++i) {
		// i번째 상자를 아예 고려하지 않는 경우
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;
		// psum[i]를 전에도 본 적이 있으면, prv[psum[i]]+1부터 여기까지 쭉 사 본다.
		int loc = prv[psum[i]];
		if (loc != -1)ret[i] = max(ret[i], ret[loc] + 1);
		// prv[]에 현재 위치를 기록한다.
		prv[psum[i]] = i;
	}
	return ret.back();
}

int t, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> k;

		vector<int> v(n);

		for (int i = 0; i < n; ++i)
			cin >> v[i];

		vector<int> sum(n + 1);
		for (int i = 1; i <= n; ++i)
			sum[i] = (sum[i - 1] + v[i - 1]) % k;

		cout << waysToBuy(sum, k) << " " << maxBuys(sum, k) << endl;
	}
	return 0;
}
*/