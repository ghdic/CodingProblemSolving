// https://www.acmicpc.net/problem/10422
/*
#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
const int MOD = 1000000007;

int t, l, dp[2501] = {1, 1};

int main() {
	FASTIO;
	cin >> t;
	for (int i = 2; i <= 2500; i++) {
		long long a = 0;
		for (int j = 1; j <= i / 2; j++)
			a += ((long long)dp[i - j] * dp[j - 1]) % MOD;
		dp[i] = (2 * a + (i % 2 ? (long long)dp[i / 2] * dp[i / 2] : 0)) % MOD;
	}

	while (t--) {
		cin >> l;
		cout << (l % 2 ? 0 : dp[l / 2]) << "\n";
	}
	return 0;
}
*/