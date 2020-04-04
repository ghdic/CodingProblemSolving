// https://www.algospot.com/judge/problem/read/ITES

/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct RNG {
	unsigned seed;
	RNG() : seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = seed * 214013u + 2531011u; // unsigned int이므로 mod안해줘도 오버플로우 되면 % 2^32와 같음..
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n) {
	RNG rng; // 신호 값을 생성하는 난수 생성기
	queue<int> q; // 합이 k이하인 구간 저장
	int ret = 0, rangeSum = 0;
	for (int i = 0; i < n; ++i) {
		// 구간에 숫자를 추가한다
		int newSignal = rng.next();
		rangeSum += newSignal;
		q.push(newSignal);

		// 구간 합이 k를 초과하는 동안 구간에서 숫자를 뺀다
		while (rangeSum > k) {
			rangeSum -= q.front();
			q.pop();
		}
		if (rangeSum == k)++ret;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, k, n;
	cin >> t;
	while (t--) {
		cin >> k >> n;
		cout << countRanges(k, n) << "\n";
	}
}
*/