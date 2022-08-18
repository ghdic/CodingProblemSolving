// https://www.acmicpc.net/problem/7570
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MAX = 1000001;

int n, dp[MAX];

int main() {
	FASTIO;
	cin >> n;
	int a, cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		dp[a] = dp[a - 1] + 1;
		cnt = max(cnt, dp[a]);
	}

	cout << n - cnt;
	return 0;
}
*/