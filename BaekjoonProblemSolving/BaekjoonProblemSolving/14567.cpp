// https://www.acmicpc.net/problem/14567
/*
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 10001;

int n, m;
int dp[MAX];
vector<int> v[MAX];


int backtrack(int num) {
	if (v[num].size() == 0) return 1;
	int& ret = dp[num];
	if (ret != 0) return ret;

	ret = 1;
	for (int i : v[num]) {
		ret = max(ret, backtrack(i) + 1);
	}
	return ret;
}


int main() {
	FASTIO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		cout << backtrack(i) << ' ';
	}
	cout << endl;

	return 0;
}
*/