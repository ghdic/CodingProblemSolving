// https://www.acmicpc.net/problem/16198

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1001;

int n, ans = 0;
vector<int> w;


void dfs(int sum) {
	if (w.size() == 2) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 1; i < w.size() - 1; i++) {
		int add = w[i - 1] * w[i + 1];
		int item = w[i];

		w.erase(w.begin() + i);
		dfs(sum + add);
		w.insert(w.begin() + i, item);
	}
}

int main() {
	FASTIO;
	cin >> n;
	w.reserve(n + 1);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		w.push_back(a);
	}

	dfs(0);

	cout << ans << endl;

	return 0;
}
*/