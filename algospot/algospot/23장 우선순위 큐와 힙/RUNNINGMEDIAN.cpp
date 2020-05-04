// https://algospot.com/judge/problem/read/RUNNINGMEDIAN

/*
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

struct RNG {
	int seed, a, b;
	RNG(int _a, int _b):a(_a), b(_b), seed(1983){}
	int next() {
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int runningMedian(int n, RNG rng) {
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int ret = 0;
	// 반복문 불변식:
	// 1. maxHeap의 크기는 minHeap의 크기와 같거나 1 더 크다
	// 2. maxHeap.top() <= minHeap.top()
	for (int cnt = 1; cnt <= n; ++cnt) {
		// 우선 1번 불변식부터 만족한다
		if (maxHeap.size() == minHeap.size())
			maxHeap.push(rng.next());
		else
			minHeap.push(rng.next());
		// 2번 불변식이 깨졌을 경우 복구한다
		if (!minHeap.empty() && !maxHeap.empty() &&
			minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		RNG rng(a, b);
		cout << runningMedian(n, rng) << "\n";
	}
	return 0;
}
*/